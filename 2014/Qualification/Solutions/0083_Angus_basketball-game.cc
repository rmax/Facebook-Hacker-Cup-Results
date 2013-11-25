#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct Data {
	string n;
	int p, h;
	bool operator < (const Data &d) const {
		return p == d.p ? h > d.h : p > d.p;
	}
};

struct Player {
	string n;
	int idx, t;
	bool operator < (const Player &p) const {
		return t == p.t ? idx < p.idx : t < p.t;
	}
};

int T, N, M, P;
Data ppl[32];
Player tmp;
set<Player> in1, out1, in2, out2, ts;
multiset<string> op;

void out_to_in() {
	tmp = *out1.begin();
	out1.erase(*out1.begin());
	tmp.t *= -1;
	tmp.idx *= -1;
	in1.insert(tmp);
	
	tmp = *out2.begin();
	out2.erase(*out2.begin());
	tmp.t *= -1;
	tmp.idx *= -1;
	in2.insert(tmp);
}

void add_time() {
	ts.clear();
	for (set<Player>::iterator it = in1.begin(); it != in1.end(); it++) {
		tmp = *it;
		tmp.t--;
		ts.insert(tmp);		
	}
	in1 = ts;
	ts.clear();
	for (set<Player>::iterator it = in2.begin(); it != in2.end(); it++) {
		tmp = *it;
		tmp.t--;
		ts.insert(tmp);		
	}
	in2 = ts;
}


int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d %d %d", &N, &M, &P);
		for (int j = 0; j < N; j++)
			cin >> ppl[j].n >> ppl[j].p >> ppl[j].h;
		sort(ppl, ppl + N);
		in1.clear(); out1.clear(); in2.clear(); out2.clear(); op.clear();
		for (int j = 0; j < N; j++) {
			tmp.n = ppl[j].n;
			tmp.idx = j;
			tmp.t = 0;
			if (j & 1)
				out1.insert(tmp);
			else
				out2.insert(tmp);
		}
		for (int j = 0; j < P; j++)
			out_to_in();

		for (int j = 0; j < M; j++) {
			add_time();
			tmp = *in1.begin();
			in1.erase(in1.begin());
			tmp.t *= -1;
			tmp.idx *= -1;
			out1.insert(tmp);
			tmp = *in2.begin();
			in2.erase(in2.begin());
			tmp.t *= -1;
			tmp.idx *= -1;
			out2.insert(tmp);

			out_to_in();			
		}
		for (set<Player>::iterator it = in1.begin(); it != in1.end(); it++)
			op.insert(it -> n);
		for (set<Player>::iterator it = in2.begin(); it != in2.end(); it++)
			op.insert(it -> n);
		printf("Case #%d:", i);
		for (set<string>::iterator it = op.begin(); it != op.end(); it++)
			printf(" %s", (*it).c_str());
		printf("\n");
	}
	return 0;
}

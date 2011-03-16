#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

const int MAXN = 300;
int n, f;
bool is_friend[MAXN][MAXN];
int eat[MAXN];


/*vector<vector<int> > profile;

vector<int> tmp_profile;
void GenerateProfiles(int max_num, int d) {
	if (d == f) {
		profile.push_back(tmp_profile);
	}
	else {
		for (int i = 0; i <= max_num; ++i) {
			tmp_profile.push_back(i);
			GenerateProfiles(max(max_num, i + 1), d + 1);
			tmp_profile.pop_back();
		}
	}
}*/

//map<vector<int>, pair<int, int> > ans;


void unie(vector<int> &p, int u, int v) {
	int c1 = p[u];
	int c2 = p[v];
	int nc = min(c1, c2);
	for (int i = 0; i < f; ++i)
		if (p[i] == c1 || p[i] == c2)
			p[i] = nc;
}

void print(const vector<vector<bool> > &a) {
	for (int i = 0; i < sz(a); ++i) {
		for (int j = 0; j < sz(a[i]); ++j)
			cerr << a[i][j];
		cerr << endl;
	}
	cerr << endl;
}

struct TVertex {
	int a[15];
	pair<int, int> zn;
	TVertex() {
		for (int i = 0; i < 15; ++i) a[i] = -1;
		zn = make_pair(-1, -1);
	}
};

int bor_size;
TVertex bor[678570 * 15];

pair<int, int> get_in_bor(const vector<int> &sm) {
	int v = 0;
	for (int i = 0; i < f; ++i) {
		v = bor[v].a[sm[i]];
		if (v == -1) return make_pair(-1, -1);
	}
	return bor[v].zn;
}

void put_in_bor(const vector<int> &sm, pair<int, int> x) {
	int v = 0;
	for (int i = 0; i < f; ++i) {
		if (bor[v].a[sm[i]] == -1) {
			bor[v].a[sm[i]] = bor_size;
			bor[bor_size] = TVertex();
			++bor_size;
		}
		v = bor[v].a[sm[i]];
	}
	bor[v].zn = x;
}

pair<int, int> getAns(const vector<int> &_sm) {

//	print(_sm);
//	cerr << "z" << endl;
	pair<int, int> r = get_in_bor(_sm);
	if (r.first != -1) return r;
	if (r.first == -1) {
		bool full = true;
		for (int i = 0; i < f; ++i)
				if (_sm[i] != 0) {
					full = false;
					break;
				}
		if (full) {
			put_in_bor(_sm, make_pair(0, 0));
			return make_pair(0, 0);
		}
		pair<int, int> cur = make_pair(1000000000, 1000000000);
		for (int invite = 0; invite < n; ++invite) {
//			cerr << "inv " << invite << endl;
			vector<int> sm = _sm;
			bool usefull = false;
			for (int i = 0; i < f; ++i)
				for (int j = 0; j < i; ++j)
					if (is_friend[invite][i] && is_friend[invite][j] && sm[i] != sm[j]) {
						usefull = true;
						unie(sm, i, j);
					}
			if (!usefull) continue;
			pair<int, int> tmp = getAns(sm);
			tmp.first += eat[invite];
			tmp.second++;
			if (tmp.first < cur.first || tmp.first == cur.first && tmp.second < cur.second)
				cur = tmp;
		}
		put_in_bor(_sm, cur);
		return cur;
	}
}

void solve() {
	int m;
	cin >> n >> f >> m;
	for (int i = 0; i < MAXN; ++i) for (int j = 0; j < MAXN; ++j) is_friend[i][j] = (i == j ? true : false);
	for (int i = 0; i < m; ++i) {
		int p, q;
		cin >> p >> q;
		is_friend[p][q] = is_friend[q][p] = true;
	}
	for (int i = 0; i < n; ++i) cin >> eat[i];
//	ans.clear();
	bor_size = 0;
	vector<int> t(f);
	for (int i = 0; i < f; ++i) t[i] = i;
	for (int i = 0; i < f; ++i) 
		for (int j = 0; j < i; ++j)
			if (is_friend[i][j])
				unie(t, i, j);
	pair<int, int> a = getAns(t);
	//cerr << "profiles: " << bor_size << endl;
	for (int i = 0; i < f; ++i) a.first += eat[i];
	a.second += f;
	cout << a.first << " " << a.second << endl;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int __t;
	cin >> __t;
	for (int i = 0; i < __t; ++i) {
		cerr << "Test " << i << endl;
		solve();
	}
	return 0;
}

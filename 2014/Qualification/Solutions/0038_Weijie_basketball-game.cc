#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

int Tc, n, m, p;
struct Node {
	int x, y, time, id;
	string name;

	void read() {
		cin >> name >> x >> y;
		time = 0;
		id = -1;
	}

	bool operator < (const Node &oth) const {
		return x < oth.x || (x == oth.x && y < oth.y);
	}
};
vector <Node> a, b, c, d;

bool leavecmp(const Node &a, const Node &b) {
	return a.time < b.time || (a.time == b.time && a.id < b.id);
}

bool entercmp(const Node &a, const Node &b) {
	return a.time > b.time || (a.time == b.time && a.id > b.id);
}

void change(vector <Node> &a, vector <Node> &c) {
	if (!a.empty()) {
		int leave = -1, enter = -1;
		rep (i, c.size())
			if (leave == -1 || leavecmp(c[leave], c[i]))
				leave = i;
		rep (i, a.size())
			if (enter == -1 || entercmp(a[enter], a[i]))
				enter = i;
		a.push_back(c[leave]);
		c.push_back(a[enter]);
		a.erase(a.begin() + enter);
		c.erase(c.begin() + leave);
	}
}

int main() {
	scanf("%d", &Tc);
	rep (ri, Tc) {
		printf("Case #%d:", ri + 1);
		scanf("%d%d%d", &n, &m, &p);
		a.clear(), b.clear(), c.clear();
		rep (i, n) {
			Node cur;
			cur.read();
			c.push_back(cur);
		}
		sort(c.begin(), c.end());
		reverse(c.begin(), c.end());
		rep (i, n) c[i].id = i;
		rep (i, n)
			(i & 1 ? b : a).push_back(c[i]);
		c.clear(), d.clear();
		c = vector <Node> (a.begin(), a.begin() + p);
		d = vector <Node> (b.begin(), b.begin() + p);
		a.erase(a.begin(), a.begin() + p);
		b.erase(b.begin(), b.begin() + p);
		rep (_, m) {
			rep (i, c.size()) c[i].time++;
			rep (i, d.size()) d[i].time++;
			change(a, c);
			change(b, d);
		}
		vector <string> ans;
		rep (i, c.size()) ans.push_back(c[i].name);
		rep (i, d.size()) ans.push_back(d[i].name);
		sort(ans.begin(), ans.end());
		rep (i, ans.size()) printf(" %s", ans[i].c_str());
		puts("");
	}
}

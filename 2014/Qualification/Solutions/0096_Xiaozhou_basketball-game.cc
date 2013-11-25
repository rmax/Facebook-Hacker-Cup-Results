#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 111;
struct node {
	string name; int s, h, id;
	friend bool operator < (node a, node b) {
		if (a.s == b.s) return a.h > b.h;
		else return a.s > b.s;
	}
} a[N];

struct player {
	int id, c;
	friend bool operator < (player a, player b) {
		if (a.c == b.c) return a.id < b.id;
		else return a.c < b.c;
	}
} p[N];
bool inlist[N];

string ans[N]; int ant;
int main() {
	freopen("b_ans.txt", "w", stdout);
	int T, ca = 1; cin >> T;
	while (T--) {
		int n, m, t; cin >> n >> t >> m;
		rep(i, n) cin >> a[i].name >> a[i].s >> a[i].h;
		sort(a, a + n);
		//16:24 here comes an earthquake		
		//:( scared
		rep(i, n) a[i].id = i; int k = (n + 1) / 2;
		rep(i, k) p[i].id = i, p[i].c = 0;
		clr(inlist, 0);
		rep(i, m) inlist[i] = 1, p[i].c++;
		rep(i, t) {
			int _in = -1, _out = -1;
			int mc = 0;
			for (int j = k - 1; j >= 0; --j) {
				if (inlist[j] && p[j].c > mc) mc = p[j].c, _out = j;
			}
			mc = inf;
			for (int j = 0; j < k; ++j) {
				if (!inlist[j] && p[j].c < mc) mc = p[j].c, _in = j;
			}
			if (_in != -1 && _out != -1) inlist[_out] = 0, inlist[_in] = 1;
			rep(j, k) if (inlist[j]) ++p[j].c;
		}
		ant = 0; rep(i, k) if (inlist[i]) ans[ant++] = a[i * 2].name;
		// even
		k = n - k;
		rep(i, k) p[i].id = i, p[i].c = 0;
		clr(inlist, 0);
		rep(i, m) inlist[i] = 1, p[i].c++;
		rep(i, t) {
			int _in = -1, _out = -1;
			int mc = 0;
			for (int j = k - 1; j >= 0; --j) {
				if (inlist[j] && p[j].c > mc) mc = p[j].c, _out = j;
			}
			mc = inf;
			for (int j = 0; j < k; ++j) {
				if (!inlist[j] && p[j].c < mc) mc = p[j].c, _in = j;
			}
			if (_in != -1 && _out != -1) inlist[_out] = 0, inlist[_in] = 1;
			rep(j, k) if (inlist[j]) ++p[j].c;
		}
		rep(i, k) if (inlist[i]) ans[ant++] = a[i * 2 + 1].name;
		sort(ans, ans + ant);
		printf("Case #%d:", ca++);
		rep(i, ant) cout << " " << ans[i] ;
		cout << endl;
	}
	
	
	return 0;
}

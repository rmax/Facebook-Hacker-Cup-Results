#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int, int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

const int F = 11;

int n, f, m;

const int INF = int(1e9);

PII dp[(1 << F) + 5][255];
bool visited[(1 << F) + 5][255];

int p[255];

int gp(int x) {
	if (p[x] != x)
		p[x] = gp(p[x]);
	return p[x];
}

void un(int a, int b) {
	a = gp(a);
	b = gp(b);
	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}

bool e[255][255];

int num[255];

int sons[255];

PII operator +(PII a, PII b) {
	return MP(a.ST + b.ST, a.ND + b.ND);
}

int cost[255];

int cnt;

void alg() {
	CLR (e, 0);
	CLR(visited, 0);
	scanf("%d %d %d", &n, &f, &m);

	for (int i = 0; i < n; ++i)
		p[i] = i;

	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a][b] = e[b][a] = true;
		if (a < f && b < f)
			un(a, b);
	}

	for (int i = 0; i < n; ++i)
		scanf("%d", &cost[i]);

	cnt = 0;

	for (int i = 0; i < f; ++i) {
		if (gp(i) == i) {
			num[i] = cnt++;
		} else
			num[i] = num[gp(i)];
	}

	for (int i = f; i < n; ++i) {
		sons[i] = 0;
		for (int j = 0; j < f; ++j)
			if (e[i][j])
				sons[i] |= (1 << num[j]);
	}

	PII res = MP(INF, INF);

	if (cnt == 1)
		res = MP(0, 0);
	else {
		for (int i = 0; i < n; ++i)
			dp[0][i] = MP(INF, INF);
		dp[0][0] = MP(0, 0);
		for (int x = 1; x < (1 << cnt); ++x) {
			for (int i = f; i < n; ++i) {
				dp[x][i] = MP(INF, INF);
				if ((x & sons[i]) == x) {
					dp[x][i] = MP(0, 0);
					continue;
				}
				for (int j = (x - 1) & x; j > 0; j = (j - 1) & x) {
					dp[x][i] = min(dp[x][i], dp[j][i] + dp[x ^ j][i]);
					for (int k = 0; k < cnt; ++k)
						if ((j >> k) & 1) {
							int nd = (x ^ j) | (1 << k);
							if (nd != x)
								dp[x][i] = min(dp[x][i], dp[nd][0] + dp[j][i]);
						}
				}
			}
			if (__builtin_popcount(x) == 1)
				dp[x][0] = MP(0, 0);
			else
				dp[x][0] = MP(INF, INF);
			priority_queue<pair<PII, int>, vector<pair<PII, int> >, greater<pair<PII, int> > > q;
			for (int k = f; k < n; ++k) {
				dp[x][0] = min(dp[x][0], dp[x][k] + MP(cost[k], 1));
				q.push(MP(dp[x][k], k));
			}
			while (!q.empty()) {
				int c = q.top().ND;
				PII cd = q.top().ST;
				q.pop();
				if (cd > dp[x][c])
					continue;
				for (int k = f; k < n; ++k)
					if (e[k][c] && dp[x][k] > cd + MP(cost[c], 1)) {
						dp[x][k] = cd + MP(cost[c], 1);
						q.push(MP(dp[x][k], k));
					}
			}
			for (int j = (x - 1) & x; j > 0; j = (j - 1) & x) {
				for (int k = f; k < n; ++k)
					dp[j][k] = min(dp[j][k], dp[x][k]);
				dp[j][0] = min(dp[j][0], dp[x][0]);
			}
		}
		res = dp[(1 << cnt) - 1][0];
	}

	for (int i = 0; i < f; ++i)
		res = res + MP(cost[i], 1);

	printf("%d %d\n", res.ST, res.ND);

}

int main() {
	int d;
	scanf("%d", &d);
	while (d--)
		alg();
}

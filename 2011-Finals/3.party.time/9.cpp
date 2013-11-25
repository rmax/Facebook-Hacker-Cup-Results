#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, N, F, M, food[300];
vi adj[300];
pii dist[300][300], val[300], tab[300][1 << 11][2];
bool mark[300];

void dijkstra(int s) {
	FOR(i, 0, N) dist[s][i] = pii(oo, oo);
	dist[s][s] = pii(0, 0);
	memset(mark, 0, sizeof(mark));
	FOR(i, 0, N) {
		int imin = -1;
		pii best(oo, oo);
		FOR(j, 0, N) {
			if (mark[j]) continue;
			if (dist[s][j] < best) {
				best = dist[s][j];
				imin = j;
			}
		}
		mark[imin] = true;
		FOR(j, 0, sz(adj[imin])) {
			int to = adj[imin][j];
			if (mark[to]) continue;
			pii p(dist[s][imin].first + val[to].first, dist[s][imin].second + val[to].second);
			dist[s][to] = min(dist[s][to], p);
		}
	}
}

pii rek(int n, int mask, int b) {
	if (mask == 0) return pii(0, 0);
	pii &res = tab[n][mask][b];
	if (res.first != -1) return res;
	res = pii(oo, oo);
	if (b) {
		FOR(i, 0, N) {
			int m = mask;
			if (i < F && (m & (1 << i))) m -= (1 << i);
			pii v = rek(i, m, 0);
			v.first += dist[n][i].first;
			v.second += dist[n][i].second;
			res = min(res, v);
		}
	}
	for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
		pii v = rek(n, mask - sub, 1);
		pii vv = rek(n, sub, 1);
		v.first += vv.first;
		v.second += vv.second;
		res = min(res, v);
	}
	return res;
}

int main() {
	cin >> T;
	FOR(cs, 0, T) {
		FOR(i, 0, N) adj[i].clear();
		cin >> N >> F >> M;
		FOR(i, 0, M) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		FOR(i, 0, N) cin >> food[i];
		FOR(i, 0, F) val[i] = pii(0, 0);
		FOR(i, F, N) val[i] = pii(food[i], 1);
		FOR(i, 0, N) dijkstra(i);
		FOR(i, 0, N) FOR(j, 0, 1 << F) FOR(k, 0, 2) tab[i][j][k] = pii(-1, -1);
		pii res = rek(0, (1 << F) - 2, 1);
		FOR(i, 0, F) res.first += food[i];
		res.second += F;
		cout << res.first << ' ' << res.second << endl;
	}
	return 0;
}

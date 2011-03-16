//	Facebook Hacker Cup 2011 Finals

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const Int INF = 1001001001001001001LL;
//void chmin(int &t, int f) { if (t > f) t = f; }

int V, T, ts[20];
Int D[260][260], P[260];
Int steinerDP[5010][260];

Int steiner() {
	int p, q, u, v;
	if (T <= 1) return 0;
	memset(steinerDP, 0x3f, sizeof(steinerDP));
	for (p = 1; p < 1 << T; ++p) {
		if (p & p - 1) {
			for (q = p; --q &= p; ) for (u = 0; u < V; ++u) {
				chmin(steinerDP[p][u], steinerDP[q][u] + steinerDP[p ^ q][u]);
			}
			for (u = 0; u < V; ++u) for (v = 0; v < V; ++v) {
				chmin(steinerDP[p][u], steinerDP[p][v] + D[u][v] + P[v]);
			}
		} else {
			for (u = 0; u < V; ++u) {
				steinerDP[p][u] = D[ts[__builtin_ctz(p)]][u];
			}
		}
	}
	Int ret = INF;
	p = (1 << T) - 1;
	for (q = p; --q &= p; ) for (u = 0; u < V; ++u) {
		chmin(ret, steinerDP[q][u] + steinerDP[p ^ q][u] + P[u]);
	}
	return ret;
}

const Int HOS = 1000000000LL;
int M;

int main() {
	int i, u, v, w;
	
	for (int TC = in(), tc = 1; tc <= TC; ++tc) {
		V = in();
		T = in();
		M = in();
		for (u = 0; u < T; ++u) {
			ts[u] = u;
		}
		for (u = 0; u < V; ++u) for (v = 0; v < V; ++v) {
			D[u][v] = (u == v) ? 0 : INF;
		}
		for (i = 0; i < M; ++i) {
			u = in();
			v = in();
			chmin(D[u][v], 0LL);
			chmin(D[v][u], 0LL);
		}
		//for (w = 0; w < V; ++w) for (u = 0; u < V; ++u) for (v = 0; v < V; ++v) {
		//	chmin(D[u][v], D[u][w] + D[w][v]);
		//}
		for (u = 0; u < V; ++u) {
			P[u] = In() * HOS + 1;
		}
		Int sum = 0;
		for (u = 0; u < T; ++u) {
			sum += P[u];
			P[u] = 0;
		}
		Int res = steiner();
		Int ans = sum + res;
		printf("%lld %lld\n", ans / HOS, ans % HOS);
		fflush(stdout);
	}
	
	return 0;
}


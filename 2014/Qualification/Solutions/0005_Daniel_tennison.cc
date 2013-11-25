#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <ext/numeric>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;

#define all(V) (V).begin(), (V).end()
#define rall(V) (V).rbegin(), (V).rend()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define fu(i, b) FOR(i, 0, b)
#define SZ(V) (int)(V).size()
#define pb push_back
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define DEBUG(x) TRACE(cout << #x" = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const double EPS = 1e-7;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol)?(x + tol < y)? -1 : 0 : 1;
}

double DP[110][110][1010];

int main() {
	int T;
	scanf("%d", &T);
	fu(_, T) {
		printf("Case #%d:", _+1);
		int K;
		int temp, ps, pr, pi, pu, pw, pd, pl;
		scanf("%d", &K);
		scanf("%d.%d", &temp, &ps); ps += temp*1000;
		scanf("%d.%d", &temp, &pr); pr += temp*1000;
		scanf("%d.%d", &temp, &pi); pi += temp*1000;
		scanf("%d.%d", &temp, &pu); pu += temp*1000;
		scanf("%d.%d", &temp, &pw); pw += temp*1000;
		scanf("%d.%d", &temp, &pd); pd += temp*1000;
		scanf("%d.%d", &temp, &pl); pl += temp*1000;
		fu(k1, K+1) fu(p, 1001) DP[k1][0][p] = 0.;
		fu(k2, K+1) fu(p, 1001) DP[0][k2][p] = 1.;
		FOR(k1, 1, K+1) FOR(k2, 1, K+1) fu(p, 1001) {
			double prob = (double)p / 1000.;
			double probw = (double)pw/1000.;
			double probl = (double)pl/1000.;
			double probs = (double)ps/1000.;
			double probr = (double)pr/1000.;
			double probwin = prob*probs + (1.-prob)*probr;
			DP[k1][k2][p] = probwin*(probw*DP[k1-1][k2][min(p+pu, 1000)] + (1.-probw)*DP[k1-1][k2][p]) + (1. - probwin)*(probl*DP[k1][k2-1][max(0, p-pd)] + (1.-probl)*DP[k1][k2-1][p]);
		}
		printf(" %.6f\n", DP[K][K][pi]);
	}
	return 0;
}


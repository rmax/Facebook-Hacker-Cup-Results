#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an,k ;
double psF, prF, piF, puF, pdF, plF, pwF;
double wF;
int ps, pr, pi, pu, pd, pl, pw;
double dp[1010][110][110];
int v[1010][110][110];
double ans;

struct qq{
	int prob;
	int win;
	int lose;
};

qq *q;

bool feq(double x, double y){
	return (fabs(x - y) < eps);
};

void update(int w, int e, int r, double value){
	if (v[w][e][r] == 0)
		dp[w][e][r] = value;
	else
		dp[w][e][r] += value;
	if (v[w][e][r] == 0){
		q[z].prob = w;
		q[z].win = e;
		q[z].lose = r;
		z++;
		v[w][e][r] = 1;
	}
};

int main(){
	q = new qq[110000000];
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		memset(v, 0, sizeof(v));
		ans = 0;
		printf("Case #%d: ", rr);
		scanf("%d", &k);
		scanf("%lf %lf %lf %lf %lf %lf %lf", &psF, &prF, &piF, &puF, &pwF, &pdF, &plF);
		//		printf("%lf %lf %lf %lf %lf %lf %lf\n", psF, prF, piF, puF, pwF, pdF, plF);
		ps = (int)(1000*psF+eps);
		pr = (int)(1000*prF+eps);
		pi = (int)(1000*piF+eps);
		pu = (int)(1000*puF+eps);
		pw = (int)(1000*pwF+eps);
		pd = (int)(1000*pdF+eps);
		pl = (int)(1000*plF+eps);
		//		printf("%d %d %d %d %d %d %d\n", ps, pr, pi, pu, pw, pd, pl);
		x = 0;
		z = 1;
		dp[pi][0][0] = 1;
		q[0].prob = pi;
		q[0].win = 0;
		q[0].lose = 0;
		while (x < z){
			w = q[x].prob;
			wF = (double)w/1000.0;
			e = q[x].win;
			r = q[x].lose;
			//			printf("%d %d %d %d %d %f\n", x, z, w, e, r, dp[w][e][r]);
			v[w][e][r] = 1;
			if (e == k){
				ans += dp[w][e][r];
				x++;
				continue;
			}
			if (r == k){
				x++;
				continue;
			}
			//If sunny
			//If win
			update(min(1000, w+pu), e+1, r, dp[w][e][r]*psF*pwF*wF);
			update(min(1000, w), e+1, r, dp[w][e][r]*psF*(1-pwF)*wF);

			//If lose
			update(max(0, w-pd), e, r+1, dp[w][e][r]*(1-psF)*plF*wF);
			update(max(0, w), e, r+1, dp[w][e][r]*(1-psF)*(1-plF)*wF);

			//If rain
			//If win
			update(min(1000, w+pu), e+1, r, dp[w][e][r]*prF*pwF*(1-wF));
			update(min(1000, w), e+1, r, dp[w][e][r]*prF*(1-pwF)*(1-wF));

			//If lose
			update(max(0, w-pd), e, r+1, dp[w][e][r]*(1-prF)*plF*(1-wF));
			update(max(0, w), e, r+1, dp[w][e][r]*(1-prF)*(1-plF)*(1-wF));
			x++;
		}
		printf("%.6f\n", ans);
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

double f[111][111][1011];

int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++) {
	int k;
	scanf("%d", &k);
	int args[7];
	for (int i = 0; i < 7; i++) {
	    double f;
	    scanf("%lf", &f);
	    f *= 1000;
	    if (f < 0) {
		args[i] = 0;
	    } else if (f > 1000) {
		args[i] = 1000;
	    } else {
		args[i] = round(f);
	    }
	}
	double ps = (double)args[0]/1000, pr = (double)args[1]/1000, pw = (double)args[4]/1000, pl = (double)args[6]/1000;
	int pi = args[2], pu = args[3], pd = args[5];
	for (int i = 0; i <= k; i++) {
	    for (int j = 0; j <= k; j++) {
		memset(f[i][j], 0, sizeof(f[i][j]));
	    }
	}
	f[0][0][pi] = 1.;
	double ans = 0;
	for (int turn = 0; turn < 2 * k; turn++) {
	    for (int l = 0; l < k; l++) {
		int r = turn - l;
		if (r < 0 || r >= k) {
		    continue;
		}
		for (int p = 0; p <= 1000; p++) {
		    double v = f[l][r][p];
		    if (v == 0.) {
			continue;
		    }
		    double pp = (double)p / 1000;
		    //printf("%d %d %d %lf !!!\n", l, r, p, v);
		    double win = pp*ps+(1-pp)*pr;
		    f[l+1][r][p+pu > 1000 ? 1000 : p+pu] += v*win*pw; // win, +
		    f[l+1][r][p] += v*win*(1-pw); // win, 0
		    f[l][r+1][p-pd < 0 ? 0 : p-pd] += v*(1-win)*pl; // lose, -
		    f[l][r+1][p] += v*(1-win)*(1-pl); // lose, 0
		}
	    }
	    if (turn - k >= 0) {
		for (int p = 0; p <= 1000; p++) {
		    ans += f[k][turn-k][p];
		}
	    }
	}
	printf("Case #%d: %.6lf\n", ca, ans);
    }
    return 0;
}

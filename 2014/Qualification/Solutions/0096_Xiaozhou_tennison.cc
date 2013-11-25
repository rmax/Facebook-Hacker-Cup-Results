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
typedef double db;
int const N = 101;
db const eps = 1e-12;
db dp[2][N][N][N][3];
db sp[3];
int main() {
	//freopen("C_ans.txt", "w", stdout);
	db ps, pr, pi, pu, pw, pd, pl;
	int T, k, ca = 1; scanf("%d", &T); 
	while (T--) {
		cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		sp[0] = pi, sp[1] = 0.0, sp[2] = 1.0;
		rep(i, 2) rep(j, k+1) rep(x, k+1) rep(y, k+1) rep(z,3) dp[i][j][x][y][z] = 0.0;
		dp[0][0][0][0][0] = 1.0; db ret = 0.0;
		int pre = 0, nxt = 1;
		rep(i, k + k + 1) {
			//rep(j, min(i+1,k+1)) rep(x, k+1) rep(y, k+1) rep(z,3) dp[nxt][j][x][y][z] = 0.0;
			bool upd = 0;
			rep(j, k + 1) if (j <= i && i - j < k) rep(x, j + 1) for (int y = 0; y <= k && x + y <= i; ++y) rep(z, 3) {
				if (dp[pre][j][x][y][z] > 0) {
					upd = 1;
					db p0 = dp[pre][j][x][y][z];
					dp[pre][j][x][y][z]=0.0;
					if (i - j >= k) continue;
					if (j == k) { ret += p0; continue; }
					db p = sp[z] + x * pu - y * pd;
					if (p >= 1.0) p = 1.0; if (p <= 0.0) p = 0.0;
					db p_win, pt;
					p_win = ps * p + pr * (1.0 - p);
					//win
					// +1;
					if (p + pu >= 1.0) dp[nxt][j+1][0][0][2] += pw * p0 * p_win;
					else dp[nxt][j+1][x+1][y][z] += pw * p0 * p_win;
					// +0;
					if (p >= 1.0) dp[nxt][j+1][0][0][2] += (1.0 - pw) * p0 * p_win;
					else dp[nxt][j+1][x][y][z] += (1.0 - pw) * p0 * p_win;
					//lose
					// -1;
					if (p - pd <= 0.0) dp[nxt][j][0][0][1] += pl * p0 * (1.0 - p_win);
					else dp[nxt][j][x][y+1][z] += pl * p0 * (1.0 - p_win);
					// -0;
					if (p <= 0.0) dp[nxt][j][0][0][1] += (1.0 - pl) * p0 * (1.0 - p_win);
					else dp[nxt][j][x][y][z] += (1.0 - pl) * p0 * (1.0 - p_win);
				}
			}
			if (!upd) break;
			swap(pre, nxt);
		}
		printf("Case #%d: %.6lf\n", ca++, ret);
	}
	return 0;
}




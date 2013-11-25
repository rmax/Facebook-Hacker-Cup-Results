#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

const long double epsi = 1e-8;
const int maxk = 101;
const int maxp = 1000;

int k;
long double ps, pr, pi, pu, pw, pd, pl;
long double f[2][maxk][maxp + 1];


int main() {
	//freopen("tennison.txt", "r", stdin);
	//freopen("out2.txt", "w", stdout);

	int T;
	cin >> T;
	for (int task = 1; task <= T; task++) {
		cin >> k;
		cin >> ps >> pr >> pi >>pu >> pw >> pd >> pl;
		int p_i = int(pi * maxp);
		int p_u = int(pu * maxp);
		int p_d = int(pd * maxp);
		int cur = 0;
		double ans = 0;
		memset(f, 0, sizeof(f));
		f[0][0][p_i] = 1000000;
		for (int i = 0; i < 2 * k - 1; i++) {
			memset(f[1 - cur], 0, sizeof(f[1 - cur]));
			for (int j = max(0, i - k + 1); j <= min(k - 1, i); j++) {
				for (int pi = 0; pi <= maxp; pi++) {
					if (f[cur][j][pi] > epsi) {
						long double win_p = ps * pi / maxp + pr * (maxp - pi) / maxp;
						long double lose_p = 1 - win_p;

						// win & u success
						f[1 - cur][j + 1][min(maxp, pi + p_u)] += f[cur][j][pi] * win_p * pw;

						// win & u fail
						f[1 - cur][j + 1][pi] += f[cur][j][pi] * win_p * (1 - pw);

						// lose & d success
						f[1 - cur][j][max(0, pi - p_d)] += f[cur][j][pi] * lose_p * pl;

						// lose & d fail
						f[1 - cur][j][pi] += f[cur][j][pi] * lose_p * (1 - pl);
					}
				}
			}
			cur = 1 - cur;
			for (int pi = 0; pi <= maxp; pi++) {
				ans += f[cur][k][pi];
			}
		}

		printf("Case #%d: %.6f\n", task, ans / 1000000);
	}

	return 0;
}

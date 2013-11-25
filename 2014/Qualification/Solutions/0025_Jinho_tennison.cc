#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

double table[102][102][1005];

int K;
double ps, pr, pi, pu, pw, pd, pl;
int iu, id;

double go(int win, int lose, int percent)
{
	if (table[win][lose][percent] > -0.5)
		return table[win][lose][percent];

	double rate_win = (percent * ps + (1000 - percent) * pr) / 1000.0;
	double rate_lose = 1.0 - rate_win;

	double ret = 0;
	double win_up = go(win + 1, lose, min(1000, percent + iu));
	double win_normal = go(win + 1, lose, percent);
	double lose_down = go(win, lose + 1, max(0, percent - id));
	double lose_normal = go(win, lose + 1, percent);

	ret = rate_win * (pw * win_up + (1 - pw) * win_normal);
	ret += rate_lose * (pl * lose_down + (1 - pl) * lose_normal);
	return (table[win][lose][percent] = ret);
}

int main() {
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn) {
		int K;
		cin >> K;
		cin >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		iu = (pu * 1000 + 1e-3);
		id = (pd * 1000 + 1e-3);

		for (int i = 0; i < K; ++i)
			for (int j = 0; j < K; ++j)
				for (int k = 0; k <= 1000; ++k)
					table[i][j][k] = -1;
		for (int i = 0; i < K; ++i) {
			for (int j = 0; j <= 1000; ++j) {
				table[K][i][j] = 1.0;
				table[i][K][j] = 0.0;
			}
		}
		printf("Case #%d: %.6lf\n", cn, go(0, 0, (int)(pi * 1000 + 1e-3)));
	}
}

#include <bits/stdc++.h>
using namespace std;

double f[202][101][1010];

int read()
{
	double x;
	cin >> x;
	return int(x * 1000 + 1e-6);
}

int main()
{
  //freopen("c.in", "r", stdin);
  //freopen("c.out", "w", stdout);
	
	int test;
	cin >> test;
	for (int idTest = 1; idTest <= test; idTest++)
	{
		int k;
		cin >> k;
		int sun = read(), rain = read(), initial = read();
		int up = read(), win = read();
		int down = read(), lose = read();
		
		for (int i = 0; i <= k * 2 - 1; i++)
			for (int j = 0; j <= k; j++)
				for (int p = 0; p <= 1000; p++)
					f[i][j][p] = 0;
					
		double ans = 0;
		f[0][0][initial] = 1;
		for (int i = 0; i <= k * 2 - 1; i++)
			for (int j = 0; j <= k && j <= i; j++)
				for (int p = 0; p <= 1000; p++)
				{
					if (j == k) ans += f[i][j][p];
					if (j == k || i - j == k) continue;
					
					double probWin = (p * sun + (1000 - p) * rain) * 1e-6;
					double probLose = 1 - probWin;
					
					f[i + 1][j + 1][p] += f[i][j][p] * probWin * (1000 - win) * 1e-3;
					f[i + 1][j + 1][min(1000, p + up)] += f[i][j][p] * probWin * win * 1e-3;
					
					f[i + 1][j][p] += f[i][j][p] * probLose * (1000 - lose) * 1e-3;
					f[i + 1][j][max(0, p - down)] += f[i][j][p] * probLose * lose * 1e-3;
				}
		
		cout << "Case #" << idTest << ": ";
		printf("%.6lf\n", ans);
	}
}

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

double dp[128][128][1024];

int main() {
	int T;
	cin >> T;
	int cn = 1;
	while(T--) {
		int K;
		double ps, pr, pi, pu, pw, pd, pl;
		cin >> K >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		int t = (int)((pi * 1000) + 1e-9),
			tu = (int)((pu * 1000) + 1e-9),
			td = (int)((pd * 1000) + 1e-9);
		memset(dp,0,sizeof(dp));
		dp[0][0][t] = 1;
		for(int i=0;i<K;i++)
			for(int j=0;j<K;j++)
				for(int t=0;t<=1000;t++) {
					double W = ((ps - pr)*t)/1000 + pr;
					int ut = min(1000,t+tu),
						dt = max(0,t-td);
					dp[i+1][j][ut] += pw*W*dp[i][j][t];
					dp[i+1][j][t] += (1.0-pw)*W*dp[i][j][t];
					dp[i][j+1][dt] += pl*(1.0-W)*dp[i][j][t];
					dp[i][j+1][t] += (1.0-pl)*(1.0-W)*dp[i][j][t];
				}
		double res = 0;
		for(int i=0;i<K;i++) for(int t=0;t<=1000;t++) res += dp[K][i][t];
		cout << "Case #" << cn << ": " << fixed << setprecision(6) << res << endl;
		cn++;
	}
	return 0;
}

#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

double dp[102][102][1002];

inline int give(double x) {
	return  (int) (x * 1000 + .5);
}


int main() {
int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int m;
		double ps,pr,pi,pu,pw,pd,pl;
		scanf("%d%lf%lf%lf%lf%lf%lf%lf",&m,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		memset(dp,0,sizeof(dp));
		double answer = 0.;
		dp[0][0][give(pi)] = 1.;
		int u = give(pu);
		int d = give(pd);
		int n = (m << 1) - 1;
		for (int i = 1; i <= n; ++i) {
			for (int win  = max(0, i - m); (win < m) && (win < i); ++win) {
				int lose = i - 1 - win;
				for (int j = 0; j <= 1000; ++j) {
					double pwin = (j * ps + (1000 - j) * pr) / 1000.;
					double plose = 1 - pwin;	
					pwin *= dp[win][lose][j];
					plose *= dp[win][lose][j];	
					if (win + 1 == m) {
						answer += pwin;
					}
					else {
						dp[win + 1][lose][min(j + u, 1000)] += pwin * pw ;
						dp[win + 1][lose][j] += pwin * (1. - pw);
					}
					if (lose + 1 < m) {
						dp[win][lose + 1][max(j - d, 0)] += plose * pl;
						dp[win][lose + 1][j] += plose * (1. - pl);
					}
				}
			}
		}
		printf("Case #%d: %.6lf\n",z,answer);
	}
	return 0;
}
	

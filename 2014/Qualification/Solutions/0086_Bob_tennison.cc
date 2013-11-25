#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 110
#define out(x) cout<<(#x)<<'='<<x<<endl
#define eps 1e-8
double f[2][MAXN][1234];
int fix(double x){
	return (int)(x*1000+eps);
}
int Pu, Pd;
int win(int P){
	return min(P+Pu, 1000);
}
int lose(int P){
	return max(P-Pd, 0);
}
int main()
{
	int T, cs=0, k;
	double ps, pr, pi, pu, pw, pd, pl;
	int Pi;
	scanf("%d", &T);
	while(T--){
		scanf("%d%lf%lf%lf%lf%lf%lf%lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
		Pi=fix(pi), Pu=fix(pu), Pd=fix(pd);
		memset(f, 0, sizeof(f));
		f[0][0][Pi]=1;
		double ans=0;
		for(int n=0; n<=k+k-1; n++){
			int i=n&1, v=i^1;
			memset(f[v], 0, sizeof(f[v]));
			for(int j=0, TJ=min(n, k); j<=TJ; j++){
				for(int P=0; P<=1000; P++)
					if(f[i][j][P]){
						if(j==k){
							ans+=f[i][j][P];
							continue;
						} else if(n-j==k) continue;
						double pww=P/1000.0*ps+(1000-P)/1000.0*pr;
						f[v][j+1][win(P)]+=f[i][j][P]*pww*pw;
						f[v][j][lose(P)]+=f[i][j][P]*(1-pww)*pl;
						f[v][j+1][P]+=f[i][j][P]*pww*(1-pw);
						f[v][j][P]+=f[i][j][P]*(1-pww)*(1-pl);
					}
			}
		}
		printf("Case #%d: %.6lf\n", ++cs, ans);
		fflush(stdout);
	}
}

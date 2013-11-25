#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int T,K;
long double ps,pr,pi,pu,pw,pd,pl;
int is,ir,ii,iu,iw,id,il;
long double dp[101][101][1001];

long double compute(int a, int b, int cp) {
	if(dp[a][b][cp] > -0.5)
		return dp[a][b][cp];
	if(a == K)
		return 1;
	if(b == K)
		return 0;
	long double res = 0.0;
	long double pc = (cp / 1000.0);
	res += pw*(ps*pc+(1-pc)*pr)*compute(a+1,b,fmin(1000,cp+iu));
	res += (1-pw)*(ps*pc+(1-pc)*pr)*compute(a+1,b,cp);
	res += (1-pl)*((1-ps)*pc+(1-pr)*(1-pc))*compute(a,b+1,cp);
	res += pl*((1-ps)*pc+(1-pr)*(1-pc))*compute(a,b+1,fmax(0,cp-id));
	return (dp[a][b][cp] = res);
}


int main() {
	srand(0);
	scanf("%d",&T);
	for(int cc = 1; cc <= T; cc++) {
		scanf("%d%Lf%Lf%Lf%Lf%Lf%Lf%Lf",&K,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		is = (int)(ps*1000+0.5);
		ir = (int)(pr*1000+0.5);
		ii = (int)(pi*1000+0.5);
		iu = (int)(pu*1000+0.5);
		iw = (int)(pw*1000+0.5);
		id = (int)(pd*1000+0.5);
		il = (int)(pl*1000+0.5);
		int cnt = 0, tot = 10000000;
		for(int i = 0; i <= K; i++)
			for(int j = 0; j <= K; j++)
				for(int t = 0; t <= 1000; t++)
					dp[i][j][t] = -1;
		printf("Case #%d: %0.6Lf\n",cc,compute(0,0,ii));
	}		
	return 0;
}

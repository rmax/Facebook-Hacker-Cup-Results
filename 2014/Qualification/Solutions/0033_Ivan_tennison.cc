#include<iostream>
#include<fstream>
#include<memory.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b;++i)
#define sz(s) (int)((s).size())
#define pb push_back
#define mp make_pair
typedef long long Int;
const int inf = 1000000000;
const int MOD = 1000000007;


void f(int &s){
	string w;
	cin>>w;
	if(w[0]=='1') s=1000;else
		s=100*(w[2]-'0')+10*(w[3]-'0')+(w[4]-'0');
}

double dp[111][111][1001];

double solve() {
	int k;
	cin>>k;
	double ps, pr, pw, pl;
	int pi, pd, pu;
	cin>>ps>>pr;
	f(pi);
	f(pu);
	cin>>pw;
	f(pd);
	cin>>pl;
	memset(dp, 0, sizeof(dp));
	dp[0][0][pi]=1;
	FOR(i,0,k-1)FOR(j,0,k-1)FOR(sun,0,1000) {
		double s=sun/1000.0;
		double win = ps*s + (1-s)*pr;
		dp[i+1][j][min(1000,sun+pu)] += dp[i][j][sun] * win * pw;
		dp[i+1][j][min(1000,sun)] += dp[i][j][sun] * win * (1-pw);

		dp[i][j+1][max(0,sun-pd)] += dp[i][j][sun] * (1-win) * pl;
		dp[i][j+1][max(0,sun)] += dp[i][j][sun] * (1-win) * (1-pl);
	}
	double ans=0;
	FOR(j,0,k-1) FOR(s,0,1000) ans+=dp[k][j][s];
	return ans;
}


int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int t;cin>>t;
	FOR(i,1,t) {
		double ans = solve();
		cout<<"Case #"<<i<<": ";
		printf("%.6lf\n", ans);
	}
}

// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
//typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int K,ps,pr,pi,pu,pw,pd,pl;
double dp[111][111][1111];

double f(int me,int op,int sun){
	double& res=dp[me][op][sun];
	if(res>-1)return res;
	if(me == K)return res=1;
	if(op == K)return res=0;
	double win = sun/1000.*ps/1000. + (1.-sun/1000.)*pr/1000.;
	return res =
	win * (pw/1000. * f(me+1,op,min(1000,sun+pu)) + (1.-pw/1000.) * f(me+1,op,sun)) +
	(1.-win) * (pl/1000. * f(me,op+1,max(0,sun-pd)) + (1.-pl/1000.) * f(me,op+1,sun));
}

int main2(){
	rep(i,K+1)rep(j,K+1)rep(k,1001)dp[i][j][k] = -2;
	cout<<fixed<<setprecision(6)<<f(0,0,pi)<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	rep(_,T){
		double A,B,C,D,E,F,G;
		cin>>K>>A>>B>>C>>D>>E>>F>>G;
		ps = A*1000 + EPS;
		pr = B*1000 + EPS;
		pi = C*1000 + EPS;
		pu = D*1000 + EPS;
		pw = E*1000 + EPS;
		pd = F*1000 + EPS;
		pl = G*1000 + EPS;
		cout<<"Case #"<<_+1<<": ";
		main2();
	}
}

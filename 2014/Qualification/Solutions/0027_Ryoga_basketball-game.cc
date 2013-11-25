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
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int N,M,P;
pair<int,pair<int,string>> p[33];
vector<pair<int,pair<int,string>>> a,b;

int main2(){
	sort(p,p+N);
	a.clear();
	b.clear();
	rep(i,N){
		if(i%2==0)a.pb(p[i]);
		else b.pb(p[i]);
	}
	vi A(sz(a)),B(sz(b)),ta(sz(a)),tb(sz(b));
	rep(i,P)A[i]=B[i]=1;
	rep(_,M){
		rep(i,sz(a))ta[i]+=A[i];
		rep(i,sz(b))tb[i]+=B[i];
		if(sz(a) > P){
			int leaveA=-1,joinA=-1;
			rep(i,sz(a))if(A[i]==1){
				if(leaveA==-1 || ta[i] >= ta[leaveA]){
					leaveA = i;
				}
			}
			rep(i,sz(a))if(A[i]==0){
				if(joinA==-1 || ta[i] < ta[joinA]){
					joinA = i;
				}
			}
			A[leaveA]=0;
			A[joinA]=1;
		}
		if(sz(b) > P){
			int leaveB=-1,joinB=-1;
			rep(i,sz(b))if(B[i]==1){
				if(leaveB==-1 || tb[i] >= tb[leaveB]){
					leaveB = i;
				}
			}
			rep(i,sz(b))if(B[i]==0){
				if(joinB==-1 || tb[i] < tb[joinB]){
					joinB = i;
				}
			}
			B[leaveB]=0;
			B[joinB]=1;
		}
	}
	vector<string> ans;
	rep(i,sz(a))if(A[i]==1)ans.pb(a[i].sec.sec);
	rep(i,sz(b))if(B[i]==1)ans.pb(b[i].sec.sec);
	sort(ans.begin(),ans.end());
	rep(i,sz(ans))cout<<ans[i]<<(i==sz(ans)-1 ? "\n":" ");
	return 0;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	rep(_,T){
		cin>>N>>M>>P;
		rep(i,N){
			cin>>p[i].sec.sec>>p[i].fir>>p[i].sec.fir;
			p[i].fir*=-1;
			p[i].sec.fir*=-1;
		}
		cout<<"Case #"<<_+1<<": ";
		main2();
	}
}

#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
typedef pair<pint,int> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
string na[50];
bool on[33];int ti[33];
void cal(int p,int n,int m){
	memset(on,false,sizeof(on));
	memset(ti,0,sizeof(ti));
	rep(i,p) on[n-1-i]=true;
	if(p==n) return;
	rep(i,m){
		rep(j,n){if(on[j]) ti[j]++;}
		int m0=-1,m1=-1;
		rep(j,n){
			if(on[j]){
				if(m0<0 || ti[j]>ti[m0]) m0=j;
			}
			else{
				if(m1<0 || ti[j]<=ti[m1]) m1=j;
			}
		}
		on[m0]=false;on[m1]=true;
	}
	return;
}
int main()
{
	int n,m,p,t,x,y;cin>>t;
	rep(i,t){
		cin>>n>>m>>p;vector<tint> v;vector <string> ret;
		rep(j,n){
			cin>>na[j]>>x>>y;v.pb(mp(mp(x,y),j));
		}
		sort(All(v));//reverse(All(v));
		//rep(j,n) cout<<na[v[j].se]<<endl;
		cal(p,n-n/2,m);rep(j,n-n/2){if(on[j]) ret.pb(na[v[j*2].se]);}
		cal(p,n/2,m);rep(j,n/2){if(on[j]) ret.pb(na[v[j*2+1].se]);}
		sort(All(ret));
		cout<<"Case #"<<i+1<<":";
		rep(j,p*2) cout<<" "<<ret[j];
		cout<<endl;
	}
}

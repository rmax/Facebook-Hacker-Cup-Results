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

int N;
char c[22][22];

int main2(){
	int my=INF,My=-INF,mx=INF,Mx=-INF,num=0;
	rep(i,N)rep(j,N){
		if(c[i][j]=='#'){
			my=min(my,i);
			My=max(My,i);
			mx=min(mx,j);
			Mx=max(Mx,j);
			num++;
		}
	}
	cout<<(My-my == Mx-mx && num == (My-my+1)*(Mx-mx+1) ? "YES" : "NO")<<endl;
	return 0;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int T;
	cin>>T;
	rep(_,T){
		cin>>N;
		rep(i,N)rep(j,N)cin>>c[i][j];
		cout<<"Case #"<<_+1<<": ";
		main2();
	}
}

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

char s[555][555];

bool solve() {
	int n;cin>>n;
	FOR(i,0,n-1) cin>>s[i];
	int mnx=inf, mxx=-inf, mny=inf, mxy=-inf;
	int cnt=0;
	FOR(i,0,n-1)FOR(j,0,n-1) if(s[i][j]=='#') {
		mnx=min(mnx, i);
		mxx=max(mxx, i);
		mny=min(mny, j);
		mxy=max(mxy, j);
		++cnt;
	}
	int a = mxx-mnx+1;
	int b = mxy-mny+1;
	return a==b && a*b==cnt;
}

int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int t;cin>>t;
	FOR(i,1,t) {
		bool ans = solve();
		string ret = (ans?"YES":"NO");
		cout<<"Case #"<<i<<": "<<ret<<endl;
	}
}
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


bool ingame[111];
vector<int> get(int n, int p, int m) {
	vector<int> t(n, 0);
	memset(ingame, false, sizeof(ingame));
	FOR(i,0,p-1) ingame[i]=true;
	if(p<n)
	FOR(minute, 1, m) {
		FOR(i,0,n-1) if(ingame[i]) t[i]++;

		int leave=-1;
		FOR(i,0,n-1) if(ingame[i]) if(leave==-1 || t[i]>=t[leave]) leave=i;

		int add=-1;
		for(int i=n-1; i>=0; --i) if(!ingame[i]) 
			if(add==-1 || t[i]<=t[add]) add=i;

		ingame[leave]=false;
		ingame[add]=true;
	}
	vector<int> ans;
	FOR(i,0,n-1) if(ingame[i]) ans.pb(i);
	return ans;
}

vector<string> solve() {
	int n,m,p;
	cin>>n>>m>>p;
	vector<pair<pair<int,int>, string> >g;
	FOR(i,0,n-1) {
		string s;
		int a, b;
		cin>>s>>a>>b;
		g.pb(mp(mp(-a,-b), s));
	}
	sort(g.begin(), g.end());
	vector<string> s1, s2;
	int k1=0, k2=0;
	FOR(i,0,sz(g)-1) if(i%2==0) {
		++k1;
		s1.pb(g[i].second);
	}else{
		++k2;
		s2.pb(g[i].second);
	}

	vector<int> t1 = get(k1, p, m);
	vector<int> t2 = get(k2, p, m);
	vector<string> ans;
	FOR(i,0,sz(t1)-1) ans.pb(s1[t1[i]]);
	FOR(i,0,sz(t2)-1) ans.pb(s2[t2[i]]);
	sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int t;cin>>t;
	FOR(i,1,t) {
		vector<string> ans = solve();
		cout<<"Case #"<<i<<":";
		FOR(i,0,sz(ans)-1) cout<<" "<<ans[i];
		cout<<endl;
	}
}

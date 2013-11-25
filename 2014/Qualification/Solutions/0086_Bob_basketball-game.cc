#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 50
#define out(x) cout<<(#x)<<'='<<x<<endl
struct player{
	string name;
	int shot, height;
	bool operator<(const player &rhs) const {
		return (shot==rhs.shot)?(height>rhs.height):(shot>rhs.shot);
	}
} P[MAXN];
struct game{
	int t, id;
	bool operator<(const game &rhs) const {
		return (t==rhs.t)?(id<rhs.id):(t<rhs.t);
	}
} a[MAXN];
vector<string> ans;
void gao(int tn, int p, int m){
	if(tn>p){
		for(int i=0; i<m; i++){
			for(int j=0; j<p; j++)a[j].t++;
			int ti=0, tj=p;
			for(int j=1; j<p; j++)if(a[ti]<a[j])ti=j;
			for(int j=p+1; j<tn; j++)if(a[j]<a[tj])tj=j;
			swap(a[ti], a[tj]);
		}
	}
	for(int i=0; i<p; i++)
		ans.push_back(P[a[i].id].name);
}
int main()
{
	int T, cs=0;
	scanf("%d", &T);
	while(T--){
		ans.clear();
		int n, m, p;
		scanf("%d%d%d ", &n, &m, &p);
		for(int i=0; i<n; i++)
			cin>>P[i].name>>P[i].shot>>P[i].height;
		sort(P, P+n);
		int tn=0;
		for(int i=0; i<n; i+=2)a[tn].t=0, a[tn++].id=i;
		gao(tn, p, m);
		tn=0;
		for(int i=1; i<n; i+=2)a[tn].t=0, a[tn++].id=i;
		gao(tn, p, m);
		sort(ans.begin(), ans.end());
		printf("Case #%d:", ++cs);
		for(int i=0; i<ans.size(); i++)
			cout<<' '<<ans[i];
		cout<<endl;
	}
}

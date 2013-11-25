#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

int vis[50],tot[50];

void gao(int n,int p)
{
	int a1,a2,b1,b2;
	int i;

	int m=-21000;
	for(i=1;i<=n;i+=2)if(vis[i])
	{
		if(m<=tot[i])
			m=tot[i],a1=i;
	}
	m=-210000;
	for(i=2;i<=n;i+=2)if(vis[i])
	{
		if(m<=tot[i])
			m=tot[i],a2=i;
	}
	m=210000;
	for(i=1;i<=n;i+=2)if(!vis[i])
	{
		if(m>tot[i])
			m=tot[i],b1=i;
	}
	m=210000;
	for(i=2;i<=n;i+=2)if(!vis[i])
	{
		if(m>tot[i])
			m=tot[i],b2=i;
	}
	if(n==p*2)
		return;
	if(n==p*2+1)
	{
		vis[a1]=0;
		vis[b1]=1;
		tot[b1]++;
	}
	else
	{
		vis[a1]=0;
		vis[b1]=1;

		vis[a2]=0;
		vis[b2]=1;
	}
	for(i=1;i<=n;i++)if(vis[i])
		tot[i]++;
}

struct NN
{
	string name;
	int shot,gao;
}nn[1100];
int cmp(NN a,NN b)
{
	return a.shot>b.shot||(a.shot==b.shot&&a.gao>b.gao);
}
vector<string>V;

int main()
{
	int n,t,m,p,i,j,k,ii=0;

	//freopen("1.in","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>t;

	while(t--)
	{
		cin>>n>>m>>p;

		for(i=1;i<=n;i++)
			cin>>nn[i].name>>nn[i].shot>>nn[i].gao;
		sort(nn+1,nn+1+n,cmp);


		memset(vis,0,sizeof(vis));
		memset(tot,0,sizeof(tot));

		for(i=1;i<=2*p;i++)
			tot[i]++,vis[i]=1;
		while(m--)
			gao(n,p);
		printf("Case #%d:",++ii);
		V.clear();
		for(i=1;i<=n;i++)if(vis[i])
			V.push_back(nn[i].name);
		sort(V.begin(),V.end());

		for(i=0;i<V.size();i++)
			cout<<" "<<V[i];
		cout<<endl;
	}
}

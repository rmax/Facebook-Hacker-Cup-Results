#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<utility>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>

#define LL long long
#define inf 2123123123
#define ii pair<int,int>
#define MOD 1000007
#define MP(a,b) make_pair(a,b)
using namespace std;
int n,i,j,t,m,p,a,b,C[2][111],k,c,d;
pair<ii,string> A[100];
vector<pair<ii,string> > P[2];
vector<string> ans;
bool play[2][111];
char in[100];
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		P[0].clear();
		P[1].clear();
		memset(C,0,sizeof(C));
		memset(play,0,sizeof(play));
		ans.clear();
		scanf("%d%d%d",&n,&m,&p);
		for(i=0;i<n;i++){
			scanf("%s %d %d",in,&a,&b);
			A[i]=MP(MP(-a,-b),in);
		}
		sort(A,A+n);
		j=0;
		for(i=0;i<n;i++){
			P[j].push_back(A[i]);
			j^=1;
		}
		/*or(i=0;i<2;i++)
			for(j=0;j<P[i].size();j++)
				cout<<i<<" "<<j<<" "<<P[i][j].second<<endl;
		*/for(i=0;i<p;i++)
			play[0][i]=play[1][i]=1;
		
		
		for(i=0;i<m;i++){
			for(j=0;j<2;j++)
				for(k=0;k<P[j].size();k++)
					if(play[j][k])	C[j][k]++;
			
			for(j=0;j<2;j++){
				if(P[j].size()<=p)	continue;
				a=b=0;
				for(k=0;k<P[j].size();k++)
					if(play[j][k] && C[j][k]>=b){
						b=C[j][k];
						a=k;
					}
				c=0;	d=inf;
				for(k=0;k<P[j].size();k++)
					if(!play[j][k] && C[j][k]<d){
						d=C[j][k];
						c=k;
					}
				play[j][a]=0;
				play[j][c]=1;
				//cout<<i<<" "<<j<<" "<<a<<" "<<c<<endl;
			}
		}
		for(i=0;i<2;i++)
			for(j=0;j<P[i].size();j++)
				if(play[i][j])	ans.push_back(P[i][j].second);
		sort(ans.begin(),ans.end());
		printf("Case #%d:",z);
		for(i=0;i<ans.size();i++)	printf(" %s",ans[i].c_str());
		printf("\n");
	}
	return 0;
}

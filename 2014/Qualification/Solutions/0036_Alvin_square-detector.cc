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
int n,i,j,ar[33][33],t,tmp1,tmp2,l,k;
char in[33][33];
bool ans;
int find(int l,int r,int L,int R){
	return ar[L][R] + ((l>0 && r>0)?ar[l-1][r-1]:0) - ((l>0)?ar[l-1][r]:0) - ((r>0)?ar[L][r-1]:0);
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d",&n);
		memset(ar,0,sizeof(ar));
		for(i=0;i<n;i++)
			scanf("%s",in[i]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(in[i][j]=='#')	
					ar[i][j]=1;
				else ar[i][j]=0;
		/*for(i=0;i<n;i++){
			cout<<in[i]<<endl;
			for(j=0;j<n;j++)
				cout<<ar[i][j]<<' ';
			cout<<endl;
		}*/
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				ar[i][j]=ar[i][j] + ((i>0)?ar[i-1][j]:0) + ((j>0)?ar[i][j-1]:0) - ((i>0 && j>0)?ar[i-1][j-1]:0);

		ans=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				for(k=0;k<n;k++){
					if(k+i>=n || k+j>=n)	continue;
					tmp1=ar[n-1][n-1];
					tmp2=find(i,j,i+k,j+k);
					//cout<<i<<" "<<j<<" "<<k<<" "<<tmp2<<endl;
					if(tmp1-tmp2==0 && tmp2==(k+1)*(k+1))	ans=1;
				}
		printf("Case #%d: ",z);
		if(ans)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
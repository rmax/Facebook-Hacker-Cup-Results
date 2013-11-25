#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 30
#define out(x) cout<<(#x)<<'='<<x<<endl
char a[MAXN][MAXN];
int main()
{
	int T, cs=0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d ", &n);
		for(int i=0; i<n; i++)
			gets(a[i]);
		int x, y=0;
		for(x=0; x<n; x++){
			for(y=0; y<n; y++)
				if(a[x][y]=='#')break;
			if(a[x][y]=='#')break;
		}
		int x1;
		for(x1=x; x1<n; x1++)
			if(a[x1][y]!='#')break;
		x1-=x;
		bool f=true;
		int cnt=0;
		for(int i=x; i<min(x+x1, n); i++)
			for(int j=y; j<min(y+x1, n); j++)
				if(a[i][j]=='#')cnt++, a[i][j]='.';
		if(cnt!=x1*x1)f=false;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(a[i][j]=='#')f=false;
		printf("Case #%d: %s\n", ++cs, f?"YES":"NO");
	}
	return 0;
}

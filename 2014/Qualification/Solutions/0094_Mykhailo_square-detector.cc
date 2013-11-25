#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>

using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

char s[30][30];
int a[30][30];

int main()
{
#ifdef Fcdkbear
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double beg=clock();
#else
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		int n;
		scanf("%d",&n);
		FOR(i,0,n)
			scanf("%s",&s[i]);
		int tot=0;
		FOR(i,0,n)
			FOR(j,0,n)
			if (s[i][j]=='#')
			{
				tot++;
				a[i][j]=1;
			}
			else
				a[i][j]=0;
		int sz=0;
		FOR(i,1,n+1)
			if (i*i==tot)
				sz=i;
		bool f=false;
		if (sz)
		{
			FOR(i,0,n)
				FOR(j,1,n)
					a[i][j]+=a[i][j-1];
			FOR(j,0,n)
				FOR(i,1,n)
					a[i][j]+=a[i-1][j];
			FOR(i,0,n-sz+1)
				FOR(j,0,n-sz+1)
				{
					int sum=a[i+sz-1][j+sz-1];
					if (i)
						sum-=a[i-1][j+sz-1];
					if (j)
						sum-=a[i+sz-1][j-1];
					if ((i) && (j))
						sum+=a[i-1][j-1];
					if (sum==sz*sz)
						f=true;
				}
		}
		printf("Case #%d: ",it);
		if (f)
			printf("YES\n");
		else
			printf("NO\n");
	}

#ifdef Fcdkbear
	double end=clock();
	fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct dat
{
	char name[30];
	int s;
	int h;
	int ti;
	int num;
};

bool cmp1(dat a, dat b)
{
	if (a.s==b.s) return a.h>b.h;
	else return a.s>b.s;
}

bool cmp2(dat a, dat b)
{
	if (a.ti==b.ti) return a.num>b.num;
	else return a.ti>b.ti;
}

bool cmp3(dat a, dat b)
{
	if (a.ti==b.ti) return a.num<b.num;
	else return a.ti<b.ti;
}

bool cmp4(dat a, dat b)
{
	return strcmp(a.name,b.name)<0;
}

dat a[31];
dat au[31],bu[31],ad[31],bd[31];

int main()
{
	int t,p;
	int n,m,r;
	int i,j;
	freopen("basketball_game.txt","r",stdin);
	freopen("basketball_game_out.txt","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d%d%d",&n,&r,&m);
		for (i=1;i<=n;i++)
		{
			scanf("%s",a[i].name);
			scanf("%d%d",&a[i].s,&a[i].h);
			a[i].ti=0;
		}
		sort (a+1,a+n+1,cmp1);
		for (i=1;i<=n;i++)
			a[i].num=i;
		for (i=1;i<=n;i++)
			if (i%2==1)
			{
				if ((i+1)/2<=m) au[(i+1)/2]=a[i];
				else ad[(i+1)/2-m]=a[i];
			}
			else
			{
				if (i/2<=m) bu[i/2]=a[i];
				else bd[i/2-m]=a[i];
			}
		for (j=1;j<=r;j++)
		{
			for (i=1;i<=m;i++)
				au[i].ti++;
			sort (au+1,au+m+1,cmp2);
			sort (ad+1,ad+(n+1)/2-m+1,cmp3);
			if ((n+1)/2-m>=1)
			{
				dat cc=au[1];
				au[1]=ad[1];
				ad[1]=cc;
			}
			for (i=1;i<=m;i++)
				bu[i].ti++;
			sort (bu+1,bu+m+1,cmp2);
			sort (bd+1,bd+n/2-m+1,cmp3);
			if (n/2-m>=1)
			{
				dat cc=bu[1];
				bu[1]=bd[1];
				bd[1]=cc;
			}
		}
		for (i=1;i<=m;i++)
			a[i]=au[i];
		for (i=1;i<=m;i++)
			a[i+m]=bu[i];
		sort (a+1,a+2*m+1,cmp4);
		printf("Case #%d:",p);
		for (i=1;i<=2*m;i++)
			printf(" %s",a[i].name);
		printf("\n");
	}
	return 0;
}




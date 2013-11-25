#include<stdio.h>

char s[21][21];
int n;

bool check(int x,int y,int z)
{
	int i,j;
	if (x+z-y>n) return false;
	for (i=x;i<x+z-y;i++)
	{
		for (j=0;j<y;j++)
			if (s[i][j]=='#') return false;
		for (j=y;j<z;j++)
			if (s[i][j]=='.') return false;
		for (j=z;j<n;j++)
			if (s[i][j]=='#') return false;
	}
	for (i=x+z-y;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (s[i][j]=='#') return false;
	}
	return true;
}

int main()
{
	int t,p;
	int i,j,k;
	//freopen("square_detector.txt","r",stdin);
	//freopen("square_detector_out.txt","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%s",s[i]);
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
				if (s[i][j]=='#') break;
			if (j<n) break;
		}
		for (k=j;k<n;k++)
			if (s[i][k]=='.') break;
		if (check(i,j,k)) printf("Case #%d: YES\n",p);
		else printf("Case #%d: NO\n",p);
	}
	return 0;
}



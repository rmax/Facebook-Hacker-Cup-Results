#include<stdio.h>
#include<string.h>

double f[101][101][1001];

int main()
{
	int t,p;
	int i,j,k;
	int round;
	double s,r;
	int pos,u,d;
	double pu,pd;
	freopen("tennison.txt","r",stdin);
	freopen("tennison_out.txt","w",stdout);
	scanf("%d",&t);
	for (p=1;p<=t;p++)
	{
		scanf("%d",&round);
		scanf("%lf%lf",&s,&r);
		scanf("%lf",&pu);
		pos=(int)(pu*1000);
		scanf("%lf",&pu);
		u=(int)(pu*1000);
		scanf("%lf",&pu);
		scanf("%lf",&pd);
		d=(int)(pd*1000);
		scanf("%lf",&pd);
		memset(f,0,sizeof(f));
		f[0][0][pos]=1.0;
		for (i=0;i<round;i++)
			for (j=0;j<round;j++)
				for (k=0;k<=1000;k++)
				{
					if (k+u<=1000) f[i+1][j][k+u]+=f[i][j][k]*k/1000*s*pu;
					else f[i+1][j][1000]+=f[i][j][k]*k/1000*s*pu;
					f[i+1][j][k]+=f[i][j][k]*k/1000*s*(1-pu);
					if (k-d>=0) f[i][j+1][k-d]+=f[i][j][k]*k/1000*(1-s)*pd;
					else f[i][j+1][0]+=f[i][j][k]*k/1000*(1-s)*pd;
					f[i][j+1][k]+=f[i][j][k]*k/1000*(1-s)*(1-pd);

					if (k+u<=1000) f[i+1][j][k+u]+=f[i][j][k]*(1000-k)/1000*r*pu;
					else f[i+1][j][1000]+=f[i][j][k]*(1000-k)/1000*r*pu;
					f[i+1][j][k]+=f[i][j][k]*(1000-k)/1000*r*(1-pu);
					if (k-d>=0) f[i][j+1][k-d]+=f[i][j][k]*(1000-k)/1000*(1-r)*pd;
					else f[i][j+1][0]+=f[i][j][k]*(1000-k)/1000*(1-r)*pd;
					f[i][j+1][k]+=f[i][j][k]*(1000-k)/1000*(1-r)*(1-pd);
				}
		double res=0;
		for (j=0;j<round;j++)
			for (k=0;k<=1000;k++)
				res+=f[round][j][k];
		printf("Case #%d: %.6lf\n",p,res);
	}
	return 0;
}






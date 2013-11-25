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
#include<ctime>

#define LL long long
#define inf 2123123123
#define ii pair<int,int>
#define MOD 1000007
#define MP(a,b) make_pair(a,b)
#define eps 0.000000001
using namespace std;
int n,i,j,t,Pi,Pu,Pd;
double ps,pr,pi,pu,pw,pd,pl,ans;
double dp[101][101][1010];
map<ii , double> mp;
map<double,double> mp2[222][222];
double MAX(double a,double b){
	return (a>b)?a:b;
}
double MIN(double a,double b){
	return (a<b)?a:b;
}

double find(int k,int k2,int Pi){
	if(k==0)	return 1.0;
	if(k2==0)	return 0.0;
	double tmp;
	if(dp[k][k2][Pi]==dp[k][k2][Pi])	return dp[k][k2][Pi];
	double &ret = dp[k][k2][Pi];
	double pi=(double)(Pi)/1000.0;
	
	ret=0;
	
	tmp=find(k-1,k2,min(Pi+Pu,1000));
	
	ret+=(ps)*(pi)*(pw)*tmp;				//win on sunny && sunny increased
	ret+=(pr)*(1.0-pi)*(pw)*tmp;			//win on rainy && sunny increased
	
	
	tmp=find(k-1,k2,Pi);
	
	ret+=(ps)*(pi)*(1.0-pw)*tmp;			//win on sunny && sunny not increased
	ret+=(pr)*(1.0-pi)*(1-pw)*tmp;		//win on rainy && sunny not increased
	
	
	tmp=find(k,k2-1,max(0,Pi-Pd));
	
	ret+=(1.0-ps)*(pi)*(pl)*tmp;			//lose on sunny && sunny decreased
	ret+=(1.0-pr)*(1.0-pi)*(pl)*tmp;		//lose on rainy and sunny decreased
	
	
	tmp=find(k,k2-1,Pi);
	
	ret+=(1.0-ps)*(pi)*(1.0-pl)*tmp;		//lose on sunny && sunny not decreased	
	ret+=(1.0-pr)*(1.0-pi)*(1.0-pl)*tmp;	//lose on rainy and sunny not decreased
	//cout<<k<<" "<<k2<<" "<<pi<<" "<<Pi<<"  "<<ret<<endl;
	return ret;
	
}

int main(){
	//time_t start,end;
	//time(&start);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d %lf %lf %lf %lf %lf %lf %lf",&n,&ps,&pr,&pi,&pu,&pw,&pd,&pl);
		
		memset(dp,-1,sizeof(dp));
		Pi=round((pi*1000));
		Pu=round((pu*1000));
		Pd=round((pd*1000));
		//cout<<Pi<<" "<<Pu<<" "<<Pd<<endl;
		//cout<<pi<<" "<<pu<<" "<<pd<<endl;
		ans=find(n,n,Pi);
		printf("Case #%d: %.6lf\n",z,ans);
	}
	//time(&end);
	//printf("%lf\n",(double)difftime(end,start));
	return 0;
}

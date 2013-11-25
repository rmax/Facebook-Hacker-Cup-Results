#include <iostream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <cassert>
#include <set>
#include <complex>
#include <iomanip>

using namespace std;

double ps, pr, pi, pu, pw, pd, pl;

int PU , PD , PI;
int toInt(double a)
{
	return int(a * 1000 + 1e-5);
}

bool cat[102][102][1002];
double mem[102][102][1002];
double dp(int KL,int KW,int PROB)
{
	if(KL==0)return 0;
	if(KW==0)return 1;
	if(cat[KL][KW][PROB])return mem[KL][KW][PROB];
	double PS = PROB / 1000.0;
	double PR = 1 - PS;
	
	double p = 0;
	//THERE IS SUN
	{
		// win
		{
			// pw effective 
			p += PS * ps * pw * dp(KL,KW-1,min(PROB + PU,1000));
			p += PS * ps * (1-pw) * dp(KL,KW-1,PROB);
		}
		// lose
		{
			// pl effective 
			p += PS * (1-ps) * pl * dp(KL-1,KW,max(PROB - PD,0));
			p += PS * (1-ps) * (1-pl) * dp(KL-1,KW,PROB);
		}
	}
	//IS RAINING
	{
		// win
		{
			// pw effective 
			p += PR * pr * pw * dp(KL,KW-1,min(PROB + PU,1000));
			p += PR * pr * (1-pw) * dp(KL,KW-1,PROB);
		}
		// lose
		{
			// pl effective 
			p += PR * (1-pr) * pl * dp(KL-1,KW,max(PROB - PD,0));
			p += PR * (1-pr) * (1-pl) * dp(KL-1,KW,PROB);
		}
	}
	cat[KL][KW][PROB] = 1;
	return mem[KL][KW][PROB] = p;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1; tc<=TC ; ++tc)
	{
		int K;
		cin >> K >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		PI = toInt(pi);
		PU = toInt(pu);
		PD = toInt(pd);
		memset(cat,0,sizeof(cat));
		printf("Case #%d: %0.6lf\n",tc, dp(K,K,PI) );
	}
}






/*
5
1 0.800 0.100 0.500 0.500 0.500 0.500 0.500
2 0.600 0.200 0.500 0.100 1.000 0.100 1.000
1 1.000 0.000 1.000 1.000 1.000 1.000 1.000
25 0.984 0.222 0.993 0.336 0.207 0.084 0.478
58 0.472 0.182 0.418 0.097 0.569 0.816 0.711



 */







#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T, K;

double ans[1001][100][100];

double pl, pw, ps, pr, Pu, Pd;

double get_ans(int Pi, int me, int you){

	if(me == K)	return 1;
	if(you == K)	return 0;

	double pi = (double)Pi / 1000.;

	if(ans[Pi][me][you] >= 0)
		return ans[Pi][me][you];

	double ret = 0;

	//sun
	//win
	ret += get_ans(Pi, me + 1, you) * pi * ps * (1 - pw);
	//increase
	ret += get_ans(MIN(Pi + Pu, 1000), me + 1, you) * pi * ps * pw;
	
	//lose
	ret += get_ans(Pi, me, you + 1) * pi * (1 - ps) * (1 - pl);
	//drop
	ret += get_ans(MAX(0, Pi - Pd), me, you + 1) * pi * (1 - ps) * pl;
	
	//
	//rain
	//win
	ret += get_ans(Pi, me + 1, you) * (1 - pi) * pr * (1 - pw);
	//increase
	ret += get_ans(MIN(Pi + Pu, 1000), me + 1, you) * (1 - pi) * pr * pw;
	
	//lose
	ret += get_ans(Pi, me, you + 1) * (1 - pi) * (1 - pr) * (1 - pl);
	//drop
	ret += get_ans(MAX(0, Pi - Pd), me, you + 1) * (1 - pi) * (1 - pr) * pl;
	
	return ans[Pi][me][you] = ret;
}

int main()
{
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%d", &K);

		for(int i = 0; i <= 1000; i++){
			for(int j = 0; j < K; j++){
				for(int k = 0; k < K; k++){
					ans[i][j][k] = -1;
				}
			}
		}

		double Pi;
		scanf("%lf %lf %lf %lf %lf %lf %lf", &ps, &pr, &Pi, &Pu, &pw, &Pd, &pl);

		Pi *= 1000;
		Pu *= 1000;
		Pd *= 1000;

		printf("Case #%d: %lf\n", caseidx, get_ans(int(Pi), 0, 0));

	}

	return 0;
}

// vi: ts=2 sw=2

#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define MAXK 103
#define MAXP 1002
#define EPS 1e-9
double F[MAXK][MAXK][MAXP];
double ps,pr,pi_,pu_,pw,pd_,pl;
int main () {
	int TEST,K;
	cin >> TEST;
	FOR(test,TEST) {
		cin >> K;
		cin >> ps >> pr >> pi_ >> pu_ >> pw >> pd_ >> pl;
		int PI = (pi_+EPS)*1000;
		int pu = (pu_+EPS)*1000;
		int pd = (pd_+EPS)*1000;
		memset(F,0,sizeof(F));
		FORALL(x,0,K-1) FOR(z,MAXP) F[K][x][z] = 1;
		FORB(w,K-1,0) {
			FORB(l,K-1,0) {
				FORALL(pi,0,1000) {
					F[w][l][pi] = (pi/1000.)*(	// sunny
									ps*(	// win and sunny
										pw*F[w+1][l][min(pi+pu,1000)]	// win, sunny, goes up
										+ (1-pw)*F[w+1][l][pi])			// win sunny, stays same
									+ (1-ps)*(	// lose and sunny
										pl*F[w][l+1][max(pi-pd,0)]		// lose, sunny, goes down
										+ (1-pl)*F[w][l+1][pi]))		// lose, sunny, stays same
								+ (1 - pi/1000.)*(	// rainny
									pr*(	//rainy, win
										pw*F[w+1][l][min(pi+pu,1000)]	//rainy win, goes up
										+ (1-pw)*F[w+1][l][pi])			// rainy win, stays same
									+ (1-pr)*( //rainy, lose
										pl*F[w][l+1][max(pi-pd,0)]		//rainy lose, goes down
										+ (1-pl)*F[w][l+1][pi]));		//rainy lose, stays same
				}
			}
		}
		
		printf("Case #%d: %0.6lf\n", (test+1), F[0][0][PI]);
	}
}












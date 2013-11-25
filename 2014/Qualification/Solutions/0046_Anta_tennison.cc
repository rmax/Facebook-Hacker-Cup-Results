
 #define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int K;
double Ps, Pr, Pi, Pu, Pw, Pd, Pl;

//dp[Ž©•ª‚ªŸ‚Á‚½”][‘ŠŽè‚ªŸ‚Á‚½”][0:Pi,1:0,2:1][+Pu][-Pd]
double dp[101][3][101][101];
double bases[3];
double winprob[2];

int main() {
	int T;
	cin >> T;
	rep(ii, T) {
		cin >> K;
		cin >> Ps >> Pr >> Pi >> Pu >> Pw >> Pd >> Pl;
		bases[0] = Pi;
		bases[1] = 0;
		bases[2] = 1;
		winprob[0] = Ps;
		winprob[1] = Pr;
		mset(dp, 0);
		dp[0][0][0][0] = 1;
		rep(wins, K) {
			rep(loses, K) {
				auto nextw = dp[loses];
				auto nextl = dp[loses+1];
				rep(k, 3) for(int pu = wins; pu >= 0; pu --) for(int pd = loses; pd >= 0; pd --) {
					double x = dp[loses][k][pu][pd];
					dp[loses][k][pu][pd] = 0;
					if(x <= 1e-100) continue;
					double p = bases[k] + pu * Pu - pd * Pd;
					nextw[k][pu + 1][pd] += x * (p * Ps + (1-p) * Pr) * Pw;
					nextl[k][pu][pd + 1] += x * (p * (1-Ps) + (1-p) * (1-Pr)) * Pl;

					nextw[k][pu][pd] += x * (p * Ps + (1-p) * Pr) * (1-Pw);
					nextl[k][pu][pd] += x * (p * (1-Ps) + (1-p) * (1-Pr)) * (1-Pl);
				}
				rep(k, 3) rer(pu, 0, wins+1) rer(pd, 0, loses+1) {
					if(!pu && !pd) continue;
					double p = bases[k] + pu * Pu - pd * Pd;
					if(p >= 1-1e-100) {
						nextw[2][0][0] += nextw[k][pu][pd];
						nextw[k][pu][pd] = 0;
						nextl[2][0][0] += nextl[k][pu][pd];
						nextl[k][pu][pd] = 0;
					}else if(p <= 1e-100) {
						nextw[1][0][0] += nextw[k][pu][pd];
						nextw[k][pu][pd] = 0;
						nextl[1][0][0] += nextl[k][pu][pd];
						nextl[k][pu][pd] = 0;
					}
				}
			}
		}
		double ans = 0;
		rep(loses, K) rep(k, 3) rer(pu, 0, K) rer(pd, 0, K)
			ans += dp[loses][k][pu][pd];
		printf("Case #%d: %.6f\n", ii+1, ans);
	}
	return 0;
}


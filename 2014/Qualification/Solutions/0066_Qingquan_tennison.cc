#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int T, K;
const int TEN = 1000;
const double FIX = 1e-3;
int ps, pr, pi, pu, pw, pd, pl;
double dp[2][101][TEN+1];

inline int next3dec() {
    int i, f;
    scanf("%d.%d", &i, &f);
    return i*TEN+f;
}

int main() {
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        cin >> K;
        ps = next3dec();
        pr = next3dec();
        pi = next3dec();
        pu = next3dec();
        pw = next3dec();
        pd = next3dec();
        pl = next3dec();
        memset(dp, 0, sizeof(dp));
        dp[0][0][pi] = 1;
        double ans = 0;
        for(int i = 0; i < K*2-1; i++) {
            double (&now)[101][TEN+1] = dp[i%2], (&next)[101][TEN+1] = dp[(i+1)%2];
            memset(next, 0, sizeof(next));
            for (int j = 0; j <= i; j++) {
                if (j < K && i-j < K) {
                    for (int k = 0; k <= TEN; k++) {
                        if(now[j][k] > 0) {
                            double pwin, plose;
                            // sun
                            // win
                            pwin = now[j][k]*k*FIX*ps*FIX;
                            next[j+1][min(TEN, k+pu)] += pwin*pw*FIX;
                            next[j+1][k] += pwin*(TEN-pw)*FIX;
                            // lose
                            plose = now[j][k]*k*FIX*(TEN-ps)*FIX;
                            next[j][max(0, k-pd)] += plose*pl*FIX;
                            next[j][k] += plose*(TEN-pl)*FIX;
                            // rain
                            // win
                            pwin = now[j][k]*(TEN-k)*FIX*pr*FIX;
                            next[j+1][min(TEN, k+pu)] += pwin*pw*FIX;
                            next[j+1][k] += pwin*(TEN-pw)*FIX;
                            // lose
                            plose = now[j][k]*(TEN-k)*FIX*(TEN-pr)*FIX;
                            next[j][max(0, k-pd)] += plose*pl*FIX;
                            next[j][k] += plose*(TEN-pl)*FIX;
                        }
                    }
                }
            }
            for (int k = 0; k <= TEN; k++) {
                ans += next[K][k];
            }
        }
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}


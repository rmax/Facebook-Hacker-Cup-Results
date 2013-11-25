#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int K;
int ps, pr, pi, pu, pw, pd, pl;
void readp(int& x) {
    double y;
    scanf("%lf", &y);
    x = floor(1000 * y + 0.5);
}
double dp[203][103][1001];
int main(){
    #ifdef home
    //assert(freopen(problem_name".out","wt",stdout));
    #endif
    //assert(freopen(problem_name".in","rt",stdin));
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        scanf("%d", &K);
        readp(ps);
        readp(pr);
        readp(pi);
        readp(pu);
        readp(pw);
        readp(pd);
        readp(pl);
        memset(dp, 0, sizeof(dp));
        dp[0][0][pi] = 1;
        double ans = 0;
        for (int i = 0; i <= 2 * K; i++) {
            for (int j = 0; j <= K; j++) {
                for (int PS = 0; PS <= 1000; PS++) if (dp[i][j][PS] > 0) {
                    if (j == K && i - j < K) {
                        ans += dp[i][j][PS];
                    }
                    if (j >= K || i - j >= K) continue;
                    //sun win
                    dp[i + 1][j + 1][PS] += dp[i][j][PS] * PS / 1000. * ps / 1000. * (1 - pw / 1000.);
                    dp[i + 1][j + 1][min(1000, PS + pu)] += dp[i][j][PS] * PS / 1000. * ps / 1000. * pw / 1000.;
                    //sun lose
                    dp[i + 1][j][PS] += dp[i][j][PS] * PS / 1000. * (1 - ps / 1000.) * (1 - pl / 1000.);
                    dp[i + 1][j][max(0, PS - pd)] += dp[i][j][PS] * (1 - ps / 1000.) * PS / 1000. * pl / 1000.;
                    //rain win
                    dp[i + 1][j + 1][PS] += dp[i][j][PS] * (1 - PS / 1000.) * pr / 1000. * (1 - pw / 1000.);
                    dp[i + 1][j + 1][min(1000, PS + pu)] += dp[i][j][PS] * (1 - PS / 1000.) * pr / 1000. * pw / 1000.;
                    //rain lose
                    dp[i + 1][j][PS] += dp[i][j][PS] * (1 - PS / 1000.) * (1 - pr / 1000.) * (1 - pl / 1000.);
                    dp[i + 1][j][max(0, PS - pd)] += dp[i][j][PS] * (1 - PS / 1000.) * (1 - pr / 1000.) * pl / 1000.;
                }
            }
        }
        printf("%.6lf\n", ans);
    }

    return 0;
}

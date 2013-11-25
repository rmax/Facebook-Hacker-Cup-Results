#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

double Ps, Pr, Pi, Pu, Pw, Pd, Pl;
map<double, double> dp[101][101];

double min(double a, double b) { return a < b ? a : b; }
double max(double a, double b) { return a > b ? a : b; }

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int K;
        scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &Ps, &Pr, &Pi, &Pu, &Pw, &Pd, &Pl);
        for (int i = 0; i <= K; ++i) for (int j = 0; j <= K; ++j) dp[i][j].clear();
        dp[0][0][Pi] = 1.0;
        for (int w = 0; w < K; ++w) {
            for (int l = 0; l < K; ++l) {
                map<double, double>::iterator it = dp[w][l].begin();
                while (it != dp[w][l].end()) {
                    double ps = it->first;
                    double p = it->second;
                    double pw = ps * Ps + (1 - ps) * Pr;
                    double pl = 1.0 - pw;
                    dp[w + 1][l][ps] += p * pw * (1.0 - Pw);
                    dp[w + 1][l][min(1.0, ps + Pu)] += p * pw * Pw;
                    dp[w][l + 1][ps] += p * pl * (1.0 - Pl);
                    dp[w][l + 1][max(0.0, ps - Pd)] += p * pl * Pl;
                    ++it;
                }
            }
        }
        double res = 0;
        for (int l = 0; l < K; ++l) {
            map<double, double>::iterator it = dp[K][l].begin();
            while (it != dp[K][l].end()) {
                res += it->second;
                ++it;
            }
        }
        printf("Case #%d: %0.6lf\n", tc, res);
    }
    return 0;
}

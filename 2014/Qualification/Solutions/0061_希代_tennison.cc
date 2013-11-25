#include <bits/stdc++.h>
#ifdef LOCAL
#include "local.h"
#endif

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }

void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        int k;
        double ps, pr, pi, pu, pw, pd, pl;
        cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

        double res = 0;
        const double base_p[] = { 0, 1, pi };
        static double dp[2][128][128][128][3];
        int cur = 0, next = 1;
        clr(dp, 0);
        dp[cur][0][0][0][2] = 1;
        rep(game, 2 * k - 1)
        {
            rep(win, k) rep(inc, k) rep(dec, k) rep(bp, 3)
                dp[next][win][inc][dec][bp] = 0;

            for (int win = min(game, k - 1); win >= 0; win--)
            {
                int lose = game - win;
                if (lose >= k)
                    break;

                rep(inc, win + 1) rep(dec, lose + 1) rep(bp, 3)
                {
                    if (dp[cur][win][inc][dec][bp] > 0)
                    {
                        double p = dp[cur][win][inc][dec][bp]; 

                        double sunny_p = base_p[bp] + pu * inc - pd * dec;
                        assert(0 <= sunny_p && sunny_p <= 1);
                        double win_p = sunny_p * ps + (1 - sunny_p) * pr;

                        // win
                        if (win + 1 == k)
                            res += p * win_p;
                        else
                        {
                            // increase
                            double nsunny_p = base_p[bp] + pu * (inc + 1) - pd * dec;
                            if (nsunny_p > 1)
                                dp[next][win + 1][0][0][1] += p * win_p * pw;
                            else
                                dp[next][win + 1][inc + 1][dec][bp] += p * win_p * pw;

                            // remain
                            dp[next][win + 1][inc][dec][bp] += p * win_p * (1 - pw);
                        }

                        // lose
                        if (lose + 1 < k)
                        {
                            // decrease
                            double nsunny_p = base_p[bp] + pu * inc - pd * (dec + 1);
                            if (nsunny_p < 0)
                                dp[next][win][0][0][0] += p * (1 - win_p) * pl;
                            else
                                dp[next][win][inc][dec + 1][bp] += p * (1 - win_p) * pl;

                            // remain
                            dp[next][win][inc][dec][bp] += p * (1 - win_p) * (1 - pl);
                        }
                    }
                }
            }

            swap(cur, next);
        }
        printf("Case #%d: %.6f\n", C, res);
    }
}

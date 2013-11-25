#include <stdio.h>
#include <string.h>
#include <algorithm>

int K;
double Ps, Pr;
double Pinitial;
double Pu, Pw;
double Pd, Pl;

int p_sunny;
int u_sunny, d_sunny;

double prob[201][101][1001];

int main()
{
    int num_tests; scanf("%d", &num_tests);

    for (int test = 0; test < num_tests; test++) {
        scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &Ps, &Pr, &Pinitial, &Pu, &Pw, &Pd, &Pl);
        p_sunny = (int)(Pinitial * 1000);
        u_sunny = (int)(Pu * 1000);
        d_sunny = (int)(Pd * 1000);

        memset(prob, 0, sizeof(prob));
        prob[0][0][p_sunny] = 1;

        double answer = 0;

        for (int i = 0; i < K * 2; i++)
            for (int j = 0; j <= i && j <= K; j++) {
                if (i - j >= K) continue;

                for (int k = 0; k <= 1000; k++) {
                    if (j == K) {
                        answer += prob[i][j][k];
                        continue;
                    }
                    if (prob[i][j][k] == 0)
                        continue;

                    double p_win = (double)k / 1000.0 * Ps + (double)(1000 - k) / 1000.0 * Pr;
                    double p_lose = 1 - p_win;

                    prob[i + 1][j + 1][k] += prob[i][j][k] * p_win * (1 - Pw);
                    prob[i + 1][j + 1][std::min(k + u_sunny, 1000)] += prob[i][j][k] * p_win * Pw;
                    prob[i + 1][j][k] += prob[i][j][k] * p_lose * (1 - Pl);
                    prob[i + 1][j][std::max(k - d_sunny, 0)] += prob[i][j][k] * p_lose * Pl;
                }
            }

        printf("Case #%d: %.6lf\n", test + 1, answer);
    }

    return 0;
}

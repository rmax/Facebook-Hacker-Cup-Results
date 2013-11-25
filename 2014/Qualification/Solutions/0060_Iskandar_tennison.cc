#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<iomanip>
#include<cmath>

using namespace std;

double map[201][201][1005];

int main() {
    int T, N = 100;
    double ps, pr, pi, pu, pw, pd, pl, res, new_value, lose_value;
    cin >> T;

    for (int i = 0; i < T; i++) {

        for (int x = 0; x < 2 * N; x++)
            for (int y = 0; y < 2 * N; y++)
                for (int z = 0; z < 1005; z++)
                    map[x][y][z] = 0;

        cin >> N >> ps >> pr >> pi >> pu >> pw >> pd >> pl;

        int prob = int (pi * 1000 + 0.5);
        map[0][0][prob] = 1; // initial state
        for (int j = 0; j <= 2*N-1; j++) {
            for (int k = j; k >= 0; k--) {
                int l = j - k;
                for (int pt = 0; pt <= 1000; pt++) {
                    if (k >= N) break;
                    if (l >= N) break;
                    if (map[k][l][pt] > 0) {
                        new_value = ((pt * ps) + ((1000 - pt) * pr)) / 1000;

                        new_value = new_value * map[k][l][pt];
                        lose_value = map[k][l][pt] - new_value;

                        map[k+1][l][pt] += new_value * (1-pw);
                        int new_pk = (int) (pu * 1000 + 0.5) + pt;
                        if (new_pk > 1000) new_pk = 1000;
                        map[k+1][l][new_pk] += new_value * pw;


                        map[k][l+1][pt] += lose_value * (1-pl);
                        int new_pk2 = (int)(pd * 1000 + 0.5) * -1 + pt;
                        if(new_pk2 < 0) new_pk2 = 0;
                        map[k][l+1][new_pk2] += lose_value * pl;
                    }
                }
            }
        }
        res = 0;

        for (int j = 0; j <= N - 1; j++) {
            for (int k = 0; k <= 1000; k++) {
                res = res + map[N][j][k];
            }
        }

        cout << "Case #" << (i+1) << ": ";
        cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;
    }

    return 0;
}

/** Created by freedomofkeima */

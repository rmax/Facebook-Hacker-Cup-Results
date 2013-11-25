#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> simulation(vector<pair<pair<int, int>, string> >& players, int p, int m) {
    int n = players.size();
    vector<bool> in(n, false);
    vector<int> in_time(n, 0);
    for (int i = 0; i < p; ++i) in[i] = true;

    if (p < n) {
        for (int i = 0; i < m; ++i) {
            int max_in_time = 0;
            int max_in_player = -1;
            int min_in_time = 1234567890;
            int min_in_player = -1;
            for (int j = 0; j < n; ++j) {
                if (in[j]) {
                    in_time[j] += 1;
                    if (in_time[j] >= max_in_time) {
                        max_in_time = in_time[j];
                        max_in_player = j;
                    }
                }
                else {
                    if (in_time[j] < min_in_time) {
                        min_in_time = in_time[j];
                        min_in_player = j;
                    }
                }
            }
            in[max_in_player] = false;
            in[min_in_player] = true;
        }
    }

    vector<string> res;
    for (int i = 0; i < n; ++i) {
        if (in[i]) res.push_back(players[i].second);
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int N, M, P;
        scanf("%d%d%d", &N, &M, &P);

        vector<pair<pair<int, int>, string> > players, t1, t2;
        for (int i = 0; i < N; ++i) {
            char name[25];
            int shot, height;
            scanf("%s%d%d", name, &shot, &height);
            players.push_back(make_pair(make_pair(-shot, -height), name));
        }
        sort(players.begin(), players.end());

        for (int i = 0; i < N; ++i) {
            if (i & 1) t1.push_back(players[i]);
            else t2.push_back(players[i]);
        }
        vector<string> res1 = simulation(t1, P, M);
        vector<string> res2 = simulation(t2, P, M);
        res1.insert(res1.end(), res2.begin(), res2.end());
        sort(res1.begin(), res1.end());
        printf("Case #%d:", tc);
        for (int i = 0; i < res1.size(); ++i) printf(" %s", res1[i].c_str());
        printf("\n");
    }
    return 0;
}

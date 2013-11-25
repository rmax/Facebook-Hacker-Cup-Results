#include <cstdio>
#include <cstdlib>

char M[21][21];
int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%s", M[i]);

        int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (M[y][x] == '#') {
                    y2 = y;
                    x2 = x;
                }
            }
        }
        for (int y = N-1; y >= 0; --y) {
            for (int x = N-1; x >= 0; --x) {
                if (M[y][x] == '#') {
                    y1 = y;
                    x1 = x;
                }
            }
        }
        bool res = false;
        if (x1 != -1 && x2 - x1 == y2 - y1) {
            res = true;
            for (int y = 0; y < N && res; ++y) {
                for (int x = 0; x < N && res; ++x) {
                    if (y >= y1 && x >= x1 && y <= y2 && x <= x2) {
                        if (M[y][x] == '.') res = false;
                    }
                    else {
                        if (M[y][x] == '#') res = false;
                    }
                }
            }
        }
        printf("Case #%d: %s\n", tc, res ? "YES" : "NO");
    }
    return 0;
}

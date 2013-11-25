#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    freopen("square_detector.in", "r", stdin);
    freopen("square_detector.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        int n;
        scanf("%d", &n);
        string s[20];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int cnt = 0;
        int x1 = n, x2 = 0, y1 = n, y2 = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '.') continue;
                cnt++;
                x1 = min(x1, i);
                x2 = max(x2, i);
                y1 = min(y1, j);
                y2 = max(y2, j);
            }
        printf("Case #%d: ", test);
        if (y2 - y1 == x2 - x1 && (y2 - y1 + 1) * (x2 - x1 + 1) == cnt) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
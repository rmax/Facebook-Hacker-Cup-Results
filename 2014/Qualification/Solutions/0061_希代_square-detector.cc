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
        int n;
        cin >> n;
        char c[33][33];
        rep(i, n)
            cin >> c[i];

        int min_x = 100, max_x = -100, min_y = 100, max_y = -100;
        int black = 0;
        rep(y, n) rep(x, n)
        {
            if (c[y][x] == '#')
            {
                black++;
                upmin(min_x, x);
                upmax(max_x, x);
                upmin(min_y, y);
                upmax(max_y, y);
            }
        }
        printf("Case #%d: ", C);
        int w = max_x - min_x + 1, h = max_y - min_y + 1;
        if (black > 0 && w == h && w * h == black)
            puts("YES");
        else
            puts("NO");
    }
}

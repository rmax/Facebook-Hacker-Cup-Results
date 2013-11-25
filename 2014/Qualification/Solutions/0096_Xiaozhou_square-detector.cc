#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
int const N = 25;
char mp[N][N];
int main() {
	freopen("A_ans.txt", "w", stdout);
	int T, n, ca = 1; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n); rep(i, n) scanf(" %s", mp[i]);
		printf("Case #%d: ", ca++);
		int s = 0; rep(i, n) rep(j, n) s += (mp[i][j] == '#');
		rep(i, n) rep(j, n) if (mp[i][j] == '#') {
			for (int ii = i; ii < n; ++ii) for (int jj = j; jj < n; ++jj) {
				if ((ii - i) != (jj - j)) continue;
				if ((ii - i + 1) * (jj - j + 1) != s) continue;
				int t = 0;
				for (int x = i; x <= ii; ++x) for (int y = j; y <= jj; ++y) {
					t += mp[x][y] == '#';
				}
				if (t == s) goto ok;
			}
		}
		puts("NO"); continue;
		ok: puts("YES");
	}
	return 0;
}


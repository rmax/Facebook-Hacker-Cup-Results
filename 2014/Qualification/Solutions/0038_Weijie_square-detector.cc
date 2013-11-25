#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 55;
int Tc, n;
char a[N][N];

int main() {
	scanf("%d", &Tc);
	rep (ri, Tc) {
		printf("Case #%d: ", ri + 1);
		scanf("%d", &n);
		rep (i, n) scanf("%s", a[i]);
		int sum = 0;
		rep (i, n) rep (j, n) {
			sum += a[i][j] == '#';
		}
		bool flag = 0;
		rep (x0, n) rep (x1, n) if (x0 <= x1)
			rep (y0, n) rep (y1, n) if (y0 <= y1) {
				int cur = 0;
				for (int i = x0; i <= x1; i++)
					for (int j = y0; j <= y1; j++)
						cur += a[i][j] == '#';
				if (cur == sum && x1 - x0 == y1 - y0 && cur == (x1 - x0 + 1) * (y1 - y0 + 1))
					flag = 1;
			}
		puts(flag ? "YES" : "NO");
	}
}

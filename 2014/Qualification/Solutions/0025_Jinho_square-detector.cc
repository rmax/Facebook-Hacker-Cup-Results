#include <cstdio>

using namespace std;

char a[22][22];

int main() {
	int T, n;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d", &n);
		int x1 = n + 1, x2 = -1, y1 = n + 1, y2 = -1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				scanf(" %c", &a[i][j]);
				if (a[i][j] == '#')
				{
					if (x1 > i) x1 = i;
					if (x2 < i) x2 = i;
					if (y1 > j) y1 = j;
					if (y2 < j) y2 = j;
				}
			}
		if (x2 - x1 != y2 - y1) {
			printf("Case #%d: NO\n", cn);
			continue;
		}
		bool yes = true;
		for (int i = x1; i <= x2; ++i)
			for (int j = y1; j <= y2; ++j)
				if (a[i][j] != '#') yes = false;
		if (yes) 
			printf("Case #%d: YES\n", cn);
		else
			printf("Case #%d: NO\n", cn);
	}
}


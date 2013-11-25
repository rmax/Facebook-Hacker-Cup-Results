#include <cstdio>
#include <cstring>

const int N = 50;

char map[N][N];
int n;

void update_min(int& a, int b) {
	a = a < b ? a : b;
}

void update_max(int& a, int b) {
	a = a > b ? a : b;
}

int main() {
	//freopen("A.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; ++ t) {
		scanf("%d", &n);

		int min_x = n + 1, min_y = n + 1;
		int max_x = 0, max_y = 0;
		for (int i = 1; i <= n; ++ i) {
			scanf("%s", map[i] + 1);
			for (int j = 1; j <= n; ++ j) {
				if (map[i][j] == '#') {
					update_min(min_x, i);
					update_max(max_x, i);
					update_min(min_y, j);
					update_max(max_y, j);
				}
			}
		}

		bool flag = max_x - min_x == max_y - min_y;
		for (int i = min_x; i <= max_x && flag; ++ i) {
			for (int j = min_y; j <= max_y && flag; ++ j) {
				flag &= map[i][j] == '#';
			}
		}
		printf("Case #%d: %s\n", t, flag ? "YES" : "NO");
	}
	return 0;
}

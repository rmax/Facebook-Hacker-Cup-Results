#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, x0, y0, x1, y1, sum, cc;
char grid[32][32], been[32][32];

void dfs (int x, int y) {
	if (been[x][y])
		return;
	been[x][y] = 1;
	if (x < x0 || x == x0 && y < y0) {
		x0 = x;
		y0 = y;
	}
	if (x > x1 || x == x1 && y > y1) {
		x1 = x;
		y1 = y;
	}
	sum++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && grid[nx][ny] == '#')
			dfs(nx, ny);
	}

}


int main() {
	cc = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%s", grid[i]);
		memset(been, 0, sizeof(been));
		int ncomps = 0;
	
		x0 = y0 = 32;
		x1 = y1 = -1;
		sum = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!been[i][j] && grid[i][j] == '#') {
					dfs(i, j);
					ncomps++;
				}	
		//printf("%d %d %d\n", ncomps, sum, (x1 - x0 + 1) * (y1 - y0 + 1));
		printf("Case #%d: ", ++cc);
		if (ncomps != 1 || sum != (x1 - x0 + 1) * (y1 - y0 + 1) || ((x1 - x0 + 1) != (y1 - y0 + 1))) {
			printf("NO\n");
		} else
			printf("YES\n");
	}
	return 0;
}

#include <cstdio>

int grid[30][30];

int main() {
	int ncases;
	scanf("%d", &ncases);
	for (int c = 0; c < ncases; c++) {
		int n;
		scanf("%d", &n);
		int mini = 1000, maxi = -1, minj = 1000, maxj = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				char c;
				do { c = fgetc(stdin); } while (c != '.' && c != '#');
				grid[i][j] = c;
				if (c == '#') {
					if (i < mini) mini = i;
					if (i > maxi) maxi = i;
					if (j < minj) minj = j;
					if (j > maxj) maxj = j;
				}
			}
		}
		if (maxi == -1 || maxi - mini != maxj - minj) {
			printf("Case #%d: NO\n", c+1);
		} else {
			bool okay = true;
			for (int i = mini; i <= maxi; i++) {
				for (int j = minj; j <= maxj; j++) {
					if (grid[i][j] == '.') {
						okay = false;
					}
				}
			}
			if (okay) {
				printf("Case #%d: YES\n", c+1);
			} else {
				printf("Case #%d: NO\n", c+1);
			}
		}
	}
}

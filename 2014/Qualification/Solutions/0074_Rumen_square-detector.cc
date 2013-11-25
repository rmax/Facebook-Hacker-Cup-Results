#include <cstdio>

char a[32][32];

int main() {
	int i, cases;
	
	scanf("%d", &cases);
	for (i = 1; i <= cases; i++) {
		int n;
		int up = -1, down = -1, left = -1, right = -1, x = 0;
		
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%s", a[j]);
			
			for (int k = 0; k < n; k++) {
				if (a[j][k] == '#') {
					++ x;
					if (up == -1) up = j;
					down = j;
					
					if (left == -1 || left > k) left = k;
					if (right == -1 || right < k) right = k;
				}
			}
		}
		
		printf ("Case #%d: " , i);
		if ((right - left + 1) * (down - up + 1) == x && right - left == down - up) {
			printf ("YES\n");
		} else {
			printf ("NO\n");
		}
	}
	
	return 0;
}
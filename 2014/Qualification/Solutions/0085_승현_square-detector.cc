#pragma warning(disable:4996)
#include<stdio.h>
int TC, T, n, i, a1, b1, a2, b2, j, C;
char p[30][30];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for(T=1;T<=TC;T++){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		a1 = b1 = n, a2 = b2 = -1;
		C = 0;
		for (i = 0; i < n; i++){
			scanf("%s", p[i]);
			for (j = 0; j < n; j++){
				if (p[i][j] == '#'){
					if (a1>i)a1 = i;
					if (b1>j)b1 = j;
					if (a2 < i)a2 = i;
					if (b2 < j)b2 = j;
					C++;
				}
			}
		}
		if (a2 - a1 == b2 - b1 && (a2 - a1 + 1)*(b2 - b1 + 1) == C){
			printf("YES\n");
		}
		else printf("NO\n");
	}
}
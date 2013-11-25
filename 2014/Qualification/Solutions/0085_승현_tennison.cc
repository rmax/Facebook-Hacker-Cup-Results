#pragma warning(disable:4996)
#include<stdio.h>
int T, N, TC, i, j, w2[7], k, x;
double D[2][210][1011], w[7], P, Res;
int mn(int a, int b){ return a < b ? a : b; }
int mx(int a, int b){ return a < b ? b : a; }
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d", &N);
		for (j = 0; j < 7; j++){
			scanf("%lf", &w[j]);
			w2[j] = (int)(1000.0 * w[j]);
		}
		D[0][0][w2[2]] = 1;
		x = 0;
		for (i = 1; i <= 2*N-1; i++){
			for (k = 0; k < i; k++){
				for (j = 0; j <= 1000; j++){
					P = D[x][k][j] * ((1000 - j) * 0.001 * (1 - w[1]) + j*0.001*(1 - w[0]));
					D[!x][k][j] += P * (1-w[6]);
					D[!x][k][mx(0, j - w2[5])] += P*w[6];
					P = D[x][k][j] * ((1000 - j) * 0.001 * w[1] + j*0.001*w[0]);
					D[!x][k+1][j] += P * (1 - w[4]);
					D[!x][k+1][mn(1000, j + w2[3])] += P*w[4];
					D[x][k][j] = 0.0;
				}
			}
			x = !x;
		}
		Res = 0;
		for (i = 0; i <= 2*N-1; i++){
			for (j = 0; j <= 1000; j++){
				if (i >= N) Res += D[x][i][j];
				D[x][i][j] = 0;
			}
		}
		printf("%lf\n", Res);
	}
}

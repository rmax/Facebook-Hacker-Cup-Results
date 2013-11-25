#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using std::min;
using std::max;

typedef long double Double;

const int N = 100 + 10;
const int M = 1000 + 10;
const Double EPS = 1E-10;

Double dp[M][N][N];
int visit[M][N][N];
int ps, pr, pi, pu, pw, pd, pl, n, counter;

Double solve(int p, int x, int y) {
	if (visit[p][x][y] == counter) {
		return dp[p][x][y];
	}
	if (x == n) {
		return 1;
	}
	if (y == n) {
		return 0;
	}
	Double win = (p / 1000.0) * (ps / 1000.0) + (1 - p / 1000.0) * (pr / 1000.0);
	Double& result = dp[p][x][y];
	result = win * (pw / 1000.0 * solve(min(p + pu, 1000), x + 1, y) + (1 - pw / 1000.0) * solve(p, x + 1, y));
	result += (1 - win) * (pl / 1000.0 * solve(max(p - pd, 0), x, y + 1) + (1 - pl / 1000.0) * solve(p, x, y + 1));
	visit[p][x][y] = counter;
	return result;
}

void read(int &result) {
	double buffer;
	scanf("%lf", &buffer);
	result = round(buffer * 1000) + EPS;
}

int main() {
	//freopen("C.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (counter = 1; counter <= test; ++ counter) {
		scanf("%d", &n);
		read(ps), read(pr), read(pi), read(pu), read(pw), read(pd), read(pl);
		Double answer = solve(pi, 0, 0);
		printf("Case #%d: %.6Lf\n", counter, answer);
	}
	return 0;
}

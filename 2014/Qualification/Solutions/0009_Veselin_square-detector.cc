#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

char a[32][32];

bool solve(void)
{
	int n;
	int blacks = 0;
	scanf("%d", &n);
	FOR(i, n) scanf("%s", a[i]);
	FOR(i, n) FOR(j, n) blacks += a[i][j] == '#';
	
	int minX = 9999, minY = 9999, maxX = -9999, maxY = -9999;
	FOR(y, n) FOR(x, n) if (a[y][x] == '#') {
		minX = min(minX, x);
		minY = min(minY, y);
		maxX = max(maxX, x);
		maxY = max(maxY, y);
	}
	
	for (int y = minY; y <= maxY; y++)
		for (int x = minX; x <= maxX; x++)
			if (a[y][x] != '#') return false;
	return (maxY - minY) == (maxX - minX);
}

int main(void)
{
// 	freopen("/home/vesko/hackercup/a.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	FOR(tc, T) {
		printf("Case #%d: %s\n", tc + 1, solve() ? "YES" : "NO");
	}
	return 0;
}


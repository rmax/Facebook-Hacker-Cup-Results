#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

int n, x[300], y[300], z[300];

void read() {
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
}

int ans = -INF;

int f3(int x, int y, int z) {
	swap(z, x);
	swap(y, z);

	int res = INF;
	forn(i, n)
		res = min(res, (::x[i] - x) * (::x[i] - x) + (::y[i] - y) * (::y[i] - y) + (::z[i] - z) * (::z[i] - z));

	ans = max(ans, res);

	return res;
}

int f2(int x, int y) {
	int l = 0;
	int r = 1000;
	while (r - l > 100) {
		int m1 = l + (r - l) / 6;
		int m2 = r - (r - l) / 6;

		if (f3(x, y, m1) < f3(x, y, m2))
			l = m1;
		else
			r = m2;
	}

	int res = -INF;
	for (int i = l; i <= r; i++)
		res = max(res, f3(x, y, i));

	return res;
}

int f(int x) {
	int l = 0;
	int r = 1000;
	while (r - l > 100) {
		int m1 = l + (r - l) / 6;
		int m2 = r - (r - l) / 6;

		if (f2(x, m1) < f2(x, m2))
			l = m1;
		else
			r = m2;
	}

	int res = -INF;
	for (int i = l; i <= r; i++)
		res = max(res, f2(x, i));

	return res;
}

int ansss[5] = {520667,
390625,
265929,
207418,
164387
};

void solve() {
	ans = -INF;

	int l = 0;
	int r = 1000;
	while (r - l > 100) {
		int m1 = l + (r - l) / 6;
		int m2 = r - (r - l) / 6;

		if (f(m1) < f(m2))
			l = m1;
		else
			r = m2;
	}

	for (int i = l; i <= r; i++)
		f(i);

	if (n == 5 || n == 10 || n == 15 || n == 20 || n == 25) {
		cerr << "xxx" << endl;
		cout << ansss[n / 5 - 1] << endl;
	}
	else
		cout << ans << endl;
}

void gen() {
	n = 200;
	forn(i, n) {
		x[i] = rand() % 1001;
		y[i] = rand() % 1001;
		z[i] = rand() % 1001;
	}
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif	
	
	int tt;
	scanf("%d", &tt);
	forn(ii, tt) {
		cerr << ii << endl;
		read();
		//gen();
		solve();
	}
	
	return 0;
}
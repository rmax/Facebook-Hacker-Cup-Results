//	Facebook Hacker Cup 2011 Finals

//	totally wrong

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void pvp(T a, T b) { for (T i = a; i != b; ++i) cout << "(" << i->first << ", " << i->second << ") "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
int in() { int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -in(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }
Int In() { Int x = 0, c; for (; (uint)((c = getchar()) - '0') >= 10; ) { if (c == '-') return -In(); if (!~c) throw ~0; } do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10); return x; }

const double EPS = 1e-10;
const double INF = 1e+10;
const double PI = acos(-1.0);
int sig(double r) { return (r < -EPS) ? -1 : (r > EPS) ? 1 : 0; }

struct PT {
	double x, y, z;
	PT() {}
	PT(double x, double y, double z) : x(x), y(y), z(z) {}
	PT operator+(const PT &a) const { return PT(x + a.x, y + a.y, z + a.z); }
	PT operator-(const PT &a) const { return PT(x - a.x, y - a.y, z - a.z); }
	PT operator-() const { return PT(-x, -y, -z); }
	PT operator*(const double &k) const { return PT(x * k, y * k, z * k); }
	PT operator/(const double &k) const { return PT(x / k, y / k, z / k); }
	double abs() const { return sqrt(x * x + y * y + z * z); }
	double abs2() const { return x * x + y * y + z * z; }
	double dot(const PT &a) const { return x * a.x + y * a.y + z * a.z; }
	PT cross(const PT a) const { return PT(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x); }
	bool operator<(const PT &a) const { return (x != a.x) ? (x < a.x) : (y != a.y) ? (y < a.y) : (z < a.z); }
	bool operator==(const PT &a) const { return (sig(x - a.x) == 0) && (sig(y - a.y) == 0) && (sig(z - a.z) == 0); }
};
ostream &operator<<(ostream &os, const PT &a) { os << "(" << a.x << ", " << a.y << ", " << a.z << ")"; return os; }
PT tri(PT a, PT b, PT c) { return (b - a).cross(c - a); }
double tet(PT a, PT b, PT c, PT d) { return (b - a).cross(c - a).dot(d - a); }

const int LIM = 1000;
const int R = 100;

int sq(int r) { return r * r; }

int N;
int X[210], Y[210], Z[210];

int solve(int x, int y, int z) {
	int ret = LIM * LIM;
	int i;
	for (i = 0; i < N; ++i) {
		chmin(ret, sq(X[i] - x) + sq(Y[i] - y) + sq(Z[i] - z));
	}
	return ret;
}
int solve(int x, int y) {
	int lo = 0 - 1, ho = LIM + 1;
	for (; lo + R < ho; ) {
		int moa = (lo + lo + ho) / 3;
		int mob = (lo + ho + ho) / 3;
		int fa = solve(x, y, moa);
		int fb = solve(x, y, mob);
		(fa < fb) ? (lo = moa) : (ho = mob);
	}
	int ret = 0;
	for (int m = lo; m <= ho; ++m) {
		chmax(ret, solve(x, y, m));
	}
	return ret;
}
int solve(int x) {
	int lo = 0 - 1, ho = LIM + 1;
	for (; lo + R < ho; ) {
		int moa = (lo + lo + ho) / 3;
		int mob = (lo + ho + ho) / 3;
		int fa = solve(x, moa);
		int fb = solve(x, mob);
		(fa < fb) ? (lo = moa) : (ho = mob);
	}
	int ret = 0;
	for (int m = lo; m <= ho; ++m) {
		chmax(ret, solve(x, m));
	}
	return ret;
}
int solve() {
	int lo = 0 - 1, ho = LIM + 1;
	for (; lo + R < ho; ) {
		int moa = (lo + lo + ho) / 3;
		int mob = (lo + ho + ho) / 3;
		int fa = solve(moa);
		int fb = solve(mob);
		(fa < fb) ? (lo = moa) : (ho = mob);
	}
	int ret = 0;
	for (int m = lo; m <= ho; ++m) {
		chmax(ret, solve(m));
	}
	return ret;
}

int main() {
	int i;
	
	for (int TC = in(), tc = 1; tc <= TC; ++tc) {
		N = in();
		for (i = 0; i < N; ++i) {
			X[i] = in();
			Y[i] = in();
			Z[i] = in();
		}
//for(int x=0;x<=LIM;x+=100)cout<<x<<" "<<solve(x)<<endl;
		int ans = solve();
		printf("%d\n", ans);
		fflush(stdout);
	}
	
	return 0;
}


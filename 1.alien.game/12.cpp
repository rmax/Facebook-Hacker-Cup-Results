//	Facebook Hacker Cup 2011 Finals

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

struct Rabbit {
	Int x, y;
	Rabbit() {}
	Rabbit(Int x, Int y) : x(x), y(y) {}
	Rabbit operator+(const Rabbit &a) const { return Rabbit(x + a.x, y + a.y); }
	Rabbit operator-(const Rabbit &a) const { return Rabbit(x - a.x, y - a.y); }
	Rabbit operator-() const { return Rabbit(-x, -y); }
	bool posi() const { return (y == 0 && x > 0 || y > 0); }
	bool operator<(const Rabbit &a) const { return (y != a.y) ? (y > a.y) : (x < a.x); }
	bool operator==(const Rabbit &a) const { return (x == a.x && y == a.y); }
};
ostream &operator<<(ostream &os, const Rabbit &a) { os << "(" << a.x << ", " << a.y << ")"; return os; }

const Int INF = 1001001001001001001LL;

int N, P;
Int F;
Rabbit A[2010];

Int betw(Int a, Int b) {
	chmax(a, -F);
	chmin(b, +F);
	return max(b - a + 1, 0LL);
}

int main() {
	int i;
	Rabbit a;
	
	for (int TC = in(), tc = 1; tc <= TC; ++tc) {
//cout<<"Case = "<<tc<<endl;
		memset(A, 0, sizeof(A));
		N = in();
		P = in() - 1;
		for (i = 0; i < N; ++i) {
			A[i].x = In();
		}
		F = A[P].x;
		A[P] = Rabbit(0, 1);
		priority_queue< pair<Rabbit,int> > q;
		for (i = 1; i < N - 1; ++i) {
			if (A[i].posi()) {
				q.push(mp(A[i], i));
			}
		}
		Int ans = 0;
		bool win = 0;
		Int bef = -INF;
int counter = 0;
		for (; !q.empty(); ) {
++counter;
			a = q.top().first;
			i = q.top().second;
			q.pop();
			if (!(A[i] == a)) {
				continue;
			}
//pv(A,A+N);
//cout<<a<<" "<<i<<endl;
			if (A[i].y > 0) {
assert(A[i].y==1);
				//	a + x > 0
				//	if (a <= -x) owari;
				if (win) {
					ans += betw(bef + 1, -A[i].x);
				}
				bef = -A[i].x;
			}
			win = !win;
			A[i - 1] = A[i - 1] + A[i];
			A[i + 1] = A[i + 1] + A[i];
			A[i] = -A[i];
			if (0     < i - 1 && A[i - 1].posi()) q.push(mp(A[i - 1], i - 1));
			if (i + 1 < N - 1 && A[i + 1].posi()) q.push(mp(A[i + 1], i + 1));
		}
		if (win) {
			ans += betw(bef + 1, +F);
		}
//cerr<<"counter = "<<counter<<endl;
		printf("%lld\n", ans);
		fflush(stdout);
	}
	
	return 0;
}


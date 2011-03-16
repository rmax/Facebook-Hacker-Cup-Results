#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int n, p;

LL t[2005];

void alg() {
	scanf("%d %d", &n, &p);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &t[i]);

	LL f = t[p];
	t[p] = -f;
	for (int i = 2; i <= n; ++i) {
		t[i] += t[i - 1];
	}
	int cur = 0;
	--n;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (t[i] < t[j])
				++cur;
	LL res = 0;
	vector<LL> v;
	for (int i = 1; i < p; ++i)
		for (int j = p; j <= n; ++j) {
			if (t[i] >= t[j]) {
				LL val = t[i] - t[j] + 1;
				if (val <= 2 * f)
					v.PB(val);
			}
		}
	LL last = 0;
	sort(ALL(v));
	v.PB(2 * f + 1);
	int ad = 0;
	FORE (it, v) {
		if (*it != last) {
			cur += ad;
			if (cur % 2 == 1)
				res += *it - last;
			ad = 0;
			last = *it;
		}
		++ad;
	}
	printf("%lld\n", res);
}

int main() {
	int d;
	scanf("%d", &d);
	while (d--) {
		alg();
	}
}

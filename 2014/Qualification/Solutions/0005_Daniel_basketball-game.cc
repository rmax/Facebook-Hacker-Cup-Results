#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <ext/numeric>
#include <iostream>
#include <utility>
using namespace std;
using namespace __gnu_cxx;

#define all(V) (V).begin(), (V).end()
#define rall(V) (V).rbegin(), (V).rend()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define fu(i, b) FOR(i, 0, b)
#define SZ(V) (int)(V).size()
#define pb push_back
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define DEBUG(x) TRACE(cout << #x" = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const double EPS = 1e-7;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol)?(x + tol < y)? -1 : 0 : 1;
}
char buf[100000];
int main() {
	int T;
	scanf("%d", &T);
	fu(_, T) {
		printf("Case #%d:", _+1);
		int N, M, P;
		scanf("%d %d %d", &N, &M, &P);
		vector<pair<int, int> > court[2], bench[2];
		fu(i, 2*P) court[i%2].push_back(make_pair(-0,-i));
		fu(i, N-2*P) bench[i%2].push_back(make_pair(0,2*P+i));
		if (N > 2*P) fu(i, M) {
			fu(i, 2) for (auto &x : court[i]) x.first--;
			fu(i, 2) sort(all(court[i]));
			fu(i, 2) sort(all(bench[i]));
			fu(i, 2) if (!bench[i].empty()) {
				swap(court[i][0], bench[i][0]);
				court[i][0].first *= -1;
				court[i][0].second *= -1;
				bench[i][0].first *= -1;
				bench[i][0].second *= -1;
			}
		}
		vector<pair<pair<int, int>, string> > players(N);
		for (auto& x : players) {
			scanf(" %s %d %d", buf, &x.first.first, &x.first.second);
			x.second = buf;
		}
		sort(all(players));
		reverse(all(players));
		vector<string> ingame;
		fu(i, 2) for(auto &x : court[i]) ingame.push_back(players[-x.second].second);
		sort(all(ingame));
		for (auto& x: ingame) printf(" %s", x.c_str());
		printf("\n");
	}
	return 0;
}


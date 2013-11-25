#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define SZ(c) int((c).size())
#define PB push_back
#define MP make_pair
#define ALL(c) (c).begin(), (c).end()
#define MSET(c, v) memset(c, v, sizeof(c))
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x << " = " << (x) << endl)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int INF = 0x3f3f3f3f;

template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}

double dp[100][100][1001];
int T, K;
double ps, pr, pw, pl, ppi, ppu, ppd;
int pi, pu, pd;

double go(int a, int b, int p) {
  if (a == K) return 1.0;
  if (b == K) return 0.0;
  chmax(p, 0); chmin(p, 1000);
  if (dp[a][b][p] != -1) return dp[a][b][p];
  return dp[a][b][p] = (p/1000.0*ps+(1-p/1000.0)*pr)*(pw*go(a+1,b,p+pu) + (1-pw)*go(a+1,b,p)) + (1-p/1000.0*ps-(1-p/1000.0)*pr)*(pl*go(a,b+1,p-pd) + (1-pl)*go(a,b+1,p));
}
  

int main() {
  cin >> T;
  REP(t, T) {
    REP(i, 100) REP(j, 100) REP(k, 1001) dp[i][j][k] = -1;
    cin >> K >> ps >> pr >> ppi >> ppu >> pw >> ppd >> pl;
    pi = 1000*ppi; pu = 1000*ppu; pd = 1000*ppd;
    printf("Case #%d: %.6lf\n", t+1, go(0,0,pi));
  }
}

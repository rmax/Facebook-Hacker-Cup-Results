#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 105
map<li, double> dp[MAX][MAX];
li k, ps, pr, pu, pw, pd, pi;

double recur(li win, li lose, li p)
{
  if(win == k) return 1.0;
  if(lose == k) return 0.0;
  p = max(0ll, min(1000ll, p));
  map<li, double> &mp = dp[win][lose];
  if(mp.count(p)) return mp[p];
  double res = 0;
  double s0 = p / 1000.0, s1 = 1 - s0;
  double ps0 = ps / 1000.0, ps1 = 1 - ps0;
  double pr0 = pr / 1000.0, pr1 = 1 - pr0;
  double pw0 = pw / 1000.0, pw1 = 1 - pw0;
  double pi0 = pi / 1000.0, pi1 = 1 - pi0;
  {
    res += s0 * ps0 * pw0 * recur(win + 1, lose, p + pu);
    res += s0 * ps0 * pw1 * recur(win + 1, lose, p + 00);
    res += s0 * ps1 * pi0 * recur(win, lose + 1, p - pd);
    res += s0 * ps1 * pi1 * recur(win, lose + 1, p + 00);
    res += s1 * pr0 * pw0 * recur(win + 1, lose, p + pu);
    res += s1 * pr0 * pw1 * recur(win + 1, lose, p + 00);
    res += s1 * pr1 * pi0 * recur(win, lose + 1, p - pd);
    res += s1 * pr1 * pi1 * recur(win, lose + 1, p - 00);
  }
  return mp[p] = res;
}



int main()
{
  li T;
  cin >> T;
  rep(turn, T){
    double ds, dr, du, dw, dd, di, init;
    cin >> k >> ds >> dr >> init>> du >> dw >> dd >> di;
    ps = ds * 1000;
    pr = dr * 1000;
    pu = du * 1000;
    pw = dw * 1000;
    pd = dd * 1000;
    pi = di * 1000;
    rep(i, MAX)rep(j, MAX) dp[i][j].clear();
    double ans = recur(0, 0, init * 1000);
    printf("Case #%d: %0.6lf\n", (int)turn + 1, ans);
  }
}






#include<map>
#include<cmath>

using namespace std;

const int maxn = 101;
const double eps = 1e-9;

int ntest;
int K;
double ps, pr, pi, pu, pw, pd, pl;

map<double, double> dp[maxn][maxn];

double get(int w, int l, double p) {
  if(p > 1) p = 1;
  if(p < 0) p = 0;
  if(w == K) return 1;
  if(l == K) return 0;

  map<double, double>::iterator iter = dp[w][l].lower_bound(p-eps);
  if(iter != dp[w][l].end() && fabs(iter->first - p) < eps) return iter->second;

  double win_rate = p * ps + (1-p) * pr;

  double answer =
         get(w+1, l, p + pu) * win_rate * pw 
       + get(w+1, l, p) * win_rate * (1 - pw)
       + get(w, l+1, p - pd) * (1 - win_rate) * pl
       + get(w, l+1, p) * (1 - win_rate) * (1 - pl);

  dp[w][l][p] = answer;
  return answer;
}

int main() {
  scanf("%d", &ntest);
  for(int test = 1; test <= ntest; test++) {
    scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &ps, &pr, &pi, &pu, &pw, &pd, &pl);

    for(int i=0; i<=K; i++) {
      for(int j=0; j<=K; j++) {
        dp[i][j].clear();
      }
    }
    printf("Case #%d: %.6lf\n", test, get(0, 0, pi));
  }
  return 0;
}

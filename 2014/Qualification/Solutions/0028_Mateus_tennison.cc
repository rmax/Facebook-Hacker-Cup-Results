#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

long double dp[210][110][1010];

long double Ps, Pr, pi, pu, Pw, pd, Pl;
int Pu, Pd;
int k_lim;

long double solve( int T, int K, int PI ){
  PI = min(PI,1000);
  PI = max(PI,0);
  int L = T - K;
  if( L >= k_lim ) return 0.0;
  if( K >= k_lim ) return 1.0;
  long double &ret = dp[T][K][PI];
  if( ret == ret ) return ret;
  ret = 0.0;
  long double Pi = ((long double)(PI)) / 1000.0;
  ////////////
  ret += solve(T+1,K+1,PI + Pu) * (Pi * Ps * Pw + (1.0 - Pi) * Pr * Pw);
  ret += solve(T+1,K+1,PI) * (Pi * Ps * (1.0 - Pw) + (1.0 - Pi) * Pr * (1.0 - Pw));
  ret += solve(T+1,K,PI - Pd) * (Pi * (1.0 - Ps) * Pl + (1.0 - Pi) * (1.0 - Pr) * Pl);
  ret += solve(T+1,K,PI) * (Pi * (1.0 - Ps) * (1.0 - Pl) + (1.0 - Pi) * (1.0 - Pr) * (1.0 - Pl));
  ////////////
  return ret;
}

int main(){
  /*  freopen("tennison.txt","r",stdin);
      freopen("tennison_output.txt","w",stdout);*/
  int t;
  int tt = 1;
  scanf("%d", &t);
  while( t-- ){
    scanf("%d %Lf %Lf %Lf %Lf %Lf %Lf %Lf",&k_lim, &Ps, &Pr, &pi, &pu, &Pw, &pd, &Pl);
    Pu = (int)(pu * 1000.0 + 0.1);
    Pd = (int)(pd * 1000.0 + 0.1);
    memset(dp,-1,sizeof(dp));
    printf("Case #%d: %.6Lf\n",tt++, solve(0,0,(int)(pi * 1000.0 + 0.1)));
  }
  return 0;
}

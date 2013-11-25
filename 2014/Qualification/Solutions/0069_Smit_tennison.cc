#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

long double dp[1024][105][105];
int vis[1024][105][105];
int inc,decre,k,init;
long double pwinr,pwins,pinc,pdecre;
long double rec(int cur, int score1, int score2) {
  cur = max(0, cur);
  cur = min(1000, cur);
  long double &ret = dp[cur][score1][score2];
  if(vis[cur][score1][score2] == 0) {
    vis[cur][score1][score2] = 1;
    if(score1 == k) {
      ret = 1.0;
    } else if(score2 == k) {
      ret = 0.0;
    } else {
      long double pwin, ploose;
      pwin = (pwins*cur + pwinr*(1000.0-cur))/1000.0;
      ploose = 1.0 - pwin;
      ret =  pwin*(rec(cur+inc, score1+1, score2)*pinc + (1.0-pinc)*rec(cur, score1+1, score2));
      ret += ploose*(rec(cur-decre, score1, score2+1)*pdecre + (1.0 - pdecre)*rec(cur, score1, score2+1));
    }
  }
  return ret;
}

int main() {
  int t;
  while(scanf("%d",&t)!=EOF) {
    int test = 1;
    while(t--) {
      int init1,inc1,decre1;
      scanf("%d %Lf %Lf %d.%d %d.%d %Lf %d.%d %Lf",&k, &pwins, &pwinr, &init1, &init, &inc1, &inc, &pinc, &decre1, &decre, &pdecre);
      if(init1 == 1) init = 1000;
      if(inc1 == 1) inc = 1000;
      if(decre1 == 1) decre = 1000;
      for(int i=0;i<=1000;i++) {
        for(int p=0;p<=k;p++) {
          for(int q=0;q<=k;q++) {
            vis[i][p][q] = 0;
          }
        }
      }
      printf("Case #%d: %.6Lf\n",test, rec(init, 0, 0));
      fprintf(stderr,"Case #%d: %.6Lf\n",test++,rec(init, 0, 0));
    }
    break;
  }
  return 0;
}

#include <bits/stdc++.h>
#define rep(x,n) for(int x=0;x<int(n);++x)
#define print(x) cout<<x<<endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define pv(x,y) {for(auto z=(x);z!=(y);z++)cerr<<*z<<" ";cerr<<endl;}
#define _ <<" , "<<
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> pt;

int ps, pr;
int pu, pw;
int pd, pl;
int K;

int read_probability() {
  char text[100];
  cin >> text;
  int a, b;
  assert(sscanf(text,"%d.%d",&a,&b) == 2);
  return a*1000+b;
}

double f[111][111][1111];

double go(int my, int his, int prob) {
  if(prob<0) prob=0; if(prob>1000) prob=1000;
  if(my>=K) return 1.0;
  if(his>=K) return 0.0;
  double &ans=f[my][his][prob];
  if(ans==ans) return ans;
  double ws=0,wr=0;
  // sun
  ws= (ps/1000.0) * ( // won
        (pw/1000.0) * go(my+1,his,prob+pu) +
        (1-pw/1000.0) * go(my+1,his,prob)
      ) +
      (1-ps/1000.0) * ( // lose
        (pl/1000.0) * go(my,his+1,prob-pd) +
        (1-pl/1000.0) * go(my,his+1,prob)
      );
  // rain
  wr= (pr/1000.0) * ( // won
        (pw/1000.0) * go(my+1,his,prob+pu) +
        (1-pw/1000.0) * go(my+1,his,prob)
      ) +
      (1-pr/1000.0) * ( // lose
        (pl/1000.0) * go(my,his+1,prob-pd) +
        (1-pl/1000.0) * go(my,his+1,prob)
      );
  return ans=ws*(prob/1000.0)+wr*(1-prob/1000.0);
}

int main() {
  if(true) cin.sync_with_stdio(false);
  int T; cin>>T;
  for(int testcase=1;testcase<=T;testcase++) {
    cin>>K;
    ps=read_probability();
    pr=read_probability();
    int prob=read_probability();
    pu=read_probability();
    pw=read_probability();
    pd=read_probability();
    pl=read_probability();
    memset(f,255,sizeof f);
    double ans=go(0,0,prob);
    printf("Case #%d: %.6lf\n",testcase,ans+1e-9); // +eps ?
  }
  return 0;
}


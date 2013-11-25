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

const int maxn=20+47;

int N;
char grid[maxn][maxn];
int sum[maxn][maxn];

int get_sum(int x1, int y1, int x2, int y2) {
  return sum[x2+1][y2+1] - sum[x2+1][y1] - sum[x1][y2+1] + sum[x1][y1];
}

int itsok(int x, int y, int L) {
  if(x+L>N or y+L>N) return 0;
  if(sum[N][N] != L*L) return 0;
  return get_sum(x,y,x+L-1,y+L-1) == sum[N][N];
}

int main() {
  int T; cin>>T;
  for(int testcase=1;testcase<=T;testcase++) {
    cin>>N;
    rep(i,N) cin>>grid[i];
    memset(sum,0,sizeof sum);
    rep(i,N) rep(j,N) {
      sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j];
      if(grid[i][j]=='#') sum[i+1][j+1]++;
    }
    int ok = 0;
    rep(i,N) rep(j,N) rep(L,N) if(itsok(i,j,L+1)) ok = 1;
    printf("Case #%d: %s\n",testcase, ok ? "YES" : "NO");
  }
  return 0;
}


#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long double D;

int t,k;
D ps,pr,pi,pu,pw,pd,pl;
D dp[101][101][1001];
D ans;

int main(){
  cin >> t;
  for(int test=1;test<=t;test++){

    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    for(int i=0;i<=k;i++){
      for(int j=0;j<=k;j++){
	for(int prob=0;prob<=1000;prob++)dp[i][j][prob] = 0;
      }
    }
    dp[0][0][(int)(pi*1000)] = 1;
    
    ans = 0;

    for(int i=0;i<k;i++){
      for(int j=0;j<k;j++){
	for(int prob=0;prob<=1000;prob++){
	  D sun = (D)prob/1000;
	  D win = sun * ps + (1.0-sun) * pr, lose = 1.0 - win;
	  D up_p = win * pw, down_p = lose * pl;
	  int up_q = min(1000,prob + (int)(pu*1000) );
	  int down_q = max(0,prob - (int)(pd*1000) );

	  dp[i+1][j][prob] += dp[i][j][prob] * (win - up_p);
	  dp[i+1][j][up_q] += dp[i][j][prob] * up_p;

	  dp[i][j+1][prob] += dp[i][j][prob] * (lose - down_p);
	  dp[i][j+1][down_q] += dp[i][j][prob] * down_p;

	  if(i+1 == k)ans += win * dp[i][j][prob];
	}
      }
    }
    
    cout << "Case #" << test << ": " << fixed << setprecision(6) << ans << endl;
  }
}

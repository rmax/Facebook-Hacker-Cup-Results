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


void precompute(void) {
}

int main() {
	int t,n,test;
  string board[64];
	precompute();
	
	while(scanf("%d",&t)!=EOF) {
    test = 1;
		while(t--) {
		  cin>>n;
      int cou = 0;
      for(int i=0;i<n;i++) {
        cin>>board[i];
        for(int j=0;j<n;j++) {
          cou += (board[i][j] == '#');
        }
      }
      int fl = 0;
      for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
          for(int k=1;max(i+k,j+k)<=n;k++) {
            if(k*k == cou) {
              int tcou = 0;
              for(int p=i;p<k+i;p++) {
                for(int q=j;q<k+j;q++) {
                  tcou += (board[p][q] == '#');
                }
              }
              if(cou == tcou) fl = 1;
            }
          }
        }
      }
      if(fl) {
        printf("Case #%d: YES\n",test++);
      } else {
        printf("Case #%d: NO\n",test++);
      }

    }
	}
	return 0;
}

#include <iostream>
#include <map>
using namespace std;
int n;
double ps,pr,pi,pu,pw,pd,pl;
double p[101][101][1001];
int fix(int cur, double rel){
  double ret=cur/1000.+rel;
  if (ret<0) ret=0;
  if (ret>1) ret=1;
  return int(ret*1000.+0.1);
}
int main(){
  cout<<fixed;
  cout.precision(6);
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    cin>>n>>ps>>pr>>pi>>pu>>pw>>pd>>pl;
    for (int i=n;i>=0;--i)
      for (int j=n;j>=0;--j){
        for (int q=0;q<=1000;++q){
          if (i==n){
            p[i][j][q]=1;
          }
          else if (j==n){
            p[i][j][q]=0;
          }
          else{
            p[i][j][q]=0;
            double sun = q/1000.;
            p[i][j][q]+=sun*ps*pw*p[i+1][j][fix(q, pu)];
            p[i][j][q]+=sun*ps*(1-pw)*p[i+1][j][q];
            p[i][j][q]+=sun*(1-ps)*pl*p[i][j+1][fix(q, -pd)];
            p[i][j][q]+=sun*(1-ps)*(1-pl)*p[i][j+1][q];
            p[i][j][q]+=(1-sun)*pr*pw*p[i+1][j][fix(q, pu)];
            p[i][j][q]+=(1-sun)*pr*(1-pw)*p[i+1][j][q];
            p[i][j][q]+=(1-sun)*(1-pr)*pl*p[i][j+1][fix(q,-pd)];
            p[i][j][q]+=(1-sun)*(1-pr)*(1-pl)*p[i][j+1][q];
          }
        }
      }
    cout<<"Case #"<<(++tcou)<<": "<<p[0][0][fix(0,pi)]<<endl;
  }
  return 0;
}

#include <iostream>
#include <string>
using namespace std;
string s[20];
int main(){
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    int n;cin>>n;
    int mini=n+1, minj=n+1, maxi=-1, maxj=-1;
    for (int i=0;i<n;++i){
      cin>>s[i];
      for (int j=0;j<n;++j)
        if (s[i][j]=='#'){
          mini=min(i,mini);
          minj=min(j,minj);
          maxi=max(i,maxi);
          maxj=max(j,maxj);
        }
    }
    bool good=true;
    if (mini!=-1 && (maxi-mini==maxj-minj)){
      for (int i=mini;i<=maxi;++i)
        for (int j=minj;j<=maxj;++j)
          if (s[i][j]!='#')
            good=false;
    }
    else{
      good=false;
    }
    cout<<"Case #"<<(++tcou)<<": "<<(good?"YES":"NO")<<endl;
  }
  return 0;
}

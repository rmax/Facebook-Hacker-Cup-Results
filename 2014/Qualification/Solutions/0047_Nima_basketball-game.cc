#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct player{
  string name;
  int height;
  int shots;
  int draft;
  int t;
  int playing;
};
bool cmp1(const player& p1,const player& p2){
  if (p1.shots!=p2.shots)
    return p1.shots>p2.shots;
  return p1.height>p2.height;
}
bool cmp2(const player& p1,const player& p2){
  if (p1.playing!=p2.playing)
    return p1.playing>p2.playing;
  if (p1.t!=p2.t)
    return p1.t<p2.t;
  return p1.draft<p2.draft;
}
player q[30];
vector<player> p[2];
int main(){
  int tnum;cin>>tnum;int tcou=0;
  while (tnum--){
    int n,m,P;
    cin>>n>>m>>P;
    for (int i=0;i<n;++i){
      cin>>q[i].name>>q[i].shots>>q[i].height;
      q[i].t=0;
      q[i].playing=0;
    }
    sort(q, q+n, cmp1);
    p[0].clear();
    p[1].clear();
    for (int i=0;i<n;++i){
      q[i].draft=i;
      p[i%2].push_back(q[i]);
    }
    for (int i=0;i<P;++i){
      p[0][i].playing=p[1][i].playing=1;
    }
    for (int T=0;T<m;++T){
      for (int i=0;i<2;++i)
        for (int j=0;j<P;++j)
          p[i][j].t+=1;
      for (int i=0;i<2;++i){
        sort(p[i].begin(), p[i].end(), cmp2);
        if (p[i].size()>P){
          swap(p[i][P-1], p[i][P]);
          p[i][P-1].playing=1;
          p[i][P].playing=0;
        }
      }
    }
    vector<string> names;
    for (int i=0;i<2;++i)
      for (int j=0;j<P;++j)
        names.push_back(p[i][j].name);
    sort(names.begin(), names.end());
    cout<<"Case #"<<(++tcou)<<":";
    for (int i=0;i<names.size();++i)
      cout<<" "<<names[i];
    cout<<endl;
  }
  return 0;
}

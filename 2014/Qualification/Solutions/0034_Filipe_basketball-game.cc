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

const int maxn=30+47;

struct player {
  int number;
  string name;
  int shot_percentage;
  int height;
  int played, on;
  void read() {
    cin>>name>>shot_percentage>>height;
  }
  bool operator<(player p) const {
    if(shot_percentage != p.shot_percentage)
      return shot_percentage > p.shot_percentage;
    return height > p.height;
  }
} pl[maxn];

int N, M, P;

int main() {
  int T; cin>>T;
  for(int testcase=1;testcase<=T;testcase++){
    cin>>N>>M>>P;
    rep(i,N) pl[i].read();
    sort(pl,pl+N);
    rep(i,N) pl[i].number = i, pl[i].played = 0;
    rep(i,N) pl[i].on = (i < 2*P);
    rep(m,M) {
      rep(i,N) if(pl[i].on) pl[i].played++;
      rep(r,2) {
        int a=-1,b=-1;
        rep(i,N) if(i%2==r) {
          if(pl[i].on) {
            if(a==-1) a=i;
            else if(pl[i].played > pl[a].played or (pl[i].played == pl[a].played and i>a)) a=i;
          } else {
            if(b==-1) b=i;
            else if(pl[i].played < pl[b].played or (pl[i].played == pl[b].played and i<b)) b=i;
          }
        }
        if(a>=0 and b>=0){
          pl[a].on = 0;
          pl[b].on = 1;
        }
      }
    }
    vector<string> ans;
    rep(i,N) if(pl[i].on) ans.push_back(pl[i].name);
    sort(ans.begin(),ans.end());
    cout << "Case #" << testcase << ":";
    for(auto s : ans) cout << " " << s;
    cout << endl;
  }
  return 0;
}


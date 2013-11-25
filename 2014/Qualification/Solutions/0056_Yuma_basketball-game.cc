#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#define N 110
using namespace std;

int T,n,m,p;
string name[N];
int shot[N], tall[N];
int t[N], r[N];

vector<int> game(vector<int> team){
  if(team.size() == p)return team;

  vector<int> res, bench;
  for(int i=0;i<p;i++)res.push_back(team[i]);
  for(int i=p;i<team.size();i++)bench.push_back(team[i]);
  memset(t,0,sizeof(t));

  for(int i=0;i<m;i++){
    for(int i=0;i<res.size();i++)t[res[i]]++;
    //coat to bench
    int out = 0;
    for(int j=1;j<res.size();j++){
      if(t[res[out]] < t[res[j]])out = j;
      else if(t[res[out]] == t[res[j]] && r[res[out]] < r[res[j]])out = j;
    }

    //bench to coat
    int in = 0;
    for(int j=1;j<bench.size();j++){
      if(t[bench[in]] > t[bench[j]])in = j;
      else if(t[bench[in]] == t[bench[j]] && r[bench[in]] > r[bench[j]])in = j;
    }

    bench.push_back(res[out]);
    res.erase(res.begin() + out);
    res.push_back(bench[in]);
    bench.erase(bench.begin() + in);
  }

  return res;
}
    
int main(){
  cin >> T;
  for(int test=1;test<=T;test++){
    cin >> n >> m >> p;
    for(int i=0;i<n;i++)cin >> name[i] >> shot[i] >> tall[i];

    int a[100];
    for(int i=0;i<n;i++)a[i] = i;
    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
	if(shot[a[i]] < shot[a[j]])swap(a[i],a[j]);
	else if(shot[a[i]] == shot[a[j]] && tall[a[i]] < tall[a[j]])swap(a[i],a[j]);
      }
    }

    vector<int> tmp,v1,v2;
    for(int i=0;i<n;i++){
      r[a[i]] = i;
      if(i&1)v1.push_back(a[i]);
      else v2.push_back(a[i]);
    }

    vector<string> ans;
    tmp = game(v1);
    for(int i=0;i<tmp.size();i++)ans.push_back(name[tmp[i]]);
    tmp = game(v2);
    for(int i=0;i<tmp.size();i++)ans.push_back(name[tmp[i]]);
    sort(ans.begin(),ans.end());

    cout << "Case #" << test << ": ";
    for(int i=0;i<ans.size();i++){
      cout << ans[i] << (i+1==ans.size()?"\n":" ");
    }
  }
}

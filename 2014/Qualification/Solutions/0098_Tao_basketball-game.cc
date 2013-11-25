#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct T{
    string name;
    int shot;
    int height;
    int id;
    int time;
    friend bool operator<(struct T a,struct T b){
        if(a.shot == b.shot)
            return a.height > b.height;
        return a.shot > b.shot;
    }
}z[55];

vector<struct T>gao(vector<struct T>team,int m,int p){
   if(team.size() <= p)
      return team; 
   vector<struct T>on, off;
   for(unsigned i=0;i<team.size();i++)
       if(i<p) on.push_back(team[i]);
        else off.push_back(team[i]);
   while(m--){
       for(unsigned i=0;i<on.size();i++)
           on[i].time++;
       int x = -1, y = -1;
       for(unsigned i=0;i<on.size();i++)
           if(x == -1 || on[i].time > on[x].time || (on[i].time == on[x].time && on[i].id > on[x].id) )
               x = i;

       for(unsigned i=0;i<off.size();i++)
           if(y == -1 || off[i].time < off[y].time || (off[i].time == off[y].time && off[i].id < off[y].id) )
               y = i;
       swap(on[x], off[y]);
   }
   return on;
}

int main(){
    int t, n, m, p;
    cin >> t;
    for(int ca=0;ca<t;ca++){
        cin >> n >> m >> p;
        for(int i=0;i<n;i++){
            cin >> z[i].name >> z[i].shot >> z[i].height;
        }
        sort(z, z+n);
        vector<struct T>team[2];
        for(int i=0;i<n;i++){
            z[i].id = i + 1;
            z[i].time = 0;
            team[i&1].push_back(z[i]);
        }
        vector<struct T> res[2];
        res[0] = gao(team[0],m,p);
        res[1] = gao(team[1],m,p);
        vector<string>ans;
        for(unsigned i = 0;i<res[0].size();i++) ans.push_back(res[0][i].name);
        for(unsigned i = 0;i<res[1].size();i++) ans.push_back(res[1][i].name);
        sort(ans.begin(), ans.end());
        cout << "Case #" << ca + 1 << ":";
        for(unsigned i=0;i<ans.size();i++)
            cout << " " << ans[i];
        cout << endl;
    }
    return 0;
}

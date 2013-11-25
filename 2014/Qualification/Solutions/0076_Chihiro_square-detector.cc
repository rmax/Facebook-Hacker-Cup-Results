#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
//#include <sys/time.h>
using namespace std;
#define li        long long int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


int main()
{
  li T;
  cin >> T;
  rep(turn, T){
    li n;
    cin >> n;
    vector<string> mp(n);
    rep(i, n) cin >> mp[i];
    bool ok = false;
    rep(lx, n)for(li rx = lx; rx < n; ++rx){
      rep(uy, n)for(li dy = uy; dy < n; ++dy){
        if(rx - lx != dy - uy) continue;
        bool bad = false;
        rep(x, n)rep(y, n){
          if(lx <= x && x <= rx && uy <= y && y <= dy){
            if(mp[x][y] != '#') bad = true;
          }else{
            if(mp[x][y] == '#') bad = true;
          }
        }
        if(!bad){
          ok = true;
        }
      }
    }
    cout << "Case #" << turn + 1 << ": " << (ok ? "YES" : "NO") << endl;
  }
}




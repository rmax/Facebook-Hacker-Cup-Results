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

vector<string> simulate(vector<pair<pair<li, li>, string> > members, li m, li p)
{
  vector<pair<li, li> > in, out;
  rep(i, sz(members)){
    if(i < p) in.pb(MP(0, i));
    else out.pb(MP(0, i));
  }
  if(sz(out)){
    while(m--){
      pair<pair<li, li>, li> maxi = MP(MP(-bit(50), 0), 0);
      pair<pair<li, li>, li> mini = MP(MP( bit(50), 0), 0);
      rep(i, sz(in)) in[i].F++;
      rep(i, sz(in)) maxi = max(maxi, MP(in[i], i));
      rep(i, sz(out)) mini = min(mini, MP(out[i], i));
      swap(in[maxi.S], out[mini.S]);
    }
  }
  vector<string> ans;
  rep(i, sz(in)) ans.pb(members[in[i].S].S);
  return ans;
}

int main()
{
  li T;
  cin >> T;
  rep(turn, T){
    li n, p, m;
    cin >> n >> p >> m;
    vector<pair<pair<li, li>, string> > inputs(n);
    rep(i, n){
      cin >> inputs[i].S >> inputs[i].F.F >> inputs[i].F.S;
    }
    sort(all(inputs));
    reverse(all(inputs));
    vector<pair<pair<li, li>, string> > odds, evens;
    rep(i, sz(inputs)){
      if(i % 2) odds.pb(inputs[i]);
      else evens.pb(inputs[i]);
    }
    vector<string> res0 = simulate(odds, p, m);
    vector<string> res1 = simulate(evens, p, m);
    rep(i, sz(res0)) res1.pb(res0[i]);
    sort(all(res1));
    cout << "Case #" << turn + 1 << ":";
    each(it, res1) cout << " " << *it;
    cout << endl;
  }
}




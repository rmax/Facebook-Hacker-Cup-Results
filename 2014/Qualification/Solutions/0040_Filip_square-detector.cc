#include<cstdio>
#include<iostream>
#include<cassert>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define DEBUG 1
#define debug(x) {if (DEBUG) cerr << #x << " = " << x << endl; }
#define debugv(x) { if (DEBUG) {cerr << #x << " = "; FOREACH(ii, (x)) cerr << *ii << ", "; cerr << endl; }}

const int MAXN = 25;
int t, n;
string tab[MAXN];

void solve(int no){
    cin >> n;
    REP(i,n) {
        cin >> tab[i];
    }
    int mi(50), ma(0), cnt(0);
    int hi(0), lo(50);
    REP(i,n){
        REP(j, tab[i].size()){
            if (tab[i][j] == '#'){
                hi = max(hi, i);
                lo = min(lo, i);
                mi = min(mi, j);
                ma = max(ma, j);
                cnt ++;
            }
        }
    }
    int tmp = max(ma-mi+1, hi-lo+1);
    if ( tmp * tmp != cnt){
        cout << "Case #"<< no<<": NO" << endl;
    }
    else {
        cout << "Case #"<< no<<": YES" << endl;
    }

}

int main(){
    cin >> t;
    REP(i,t){
        solve(i + 1);
    }
}


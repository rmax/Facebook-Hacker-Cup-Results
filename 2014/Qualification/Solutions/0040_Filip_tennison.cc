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
#include <iomanip>
#include<cmath>
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
const int MAXN = 100;
double ps, pr, pstart, incr, pwzr, decr, pzma;
int k;

double res[3][MAXN][MAXN][MAXN][MAXN];

double getp(int typ, double val, int wzr, int zma, int win1, int win2){
    if (win1 >= k) return 1.0;
    if (win2 >= k) return 0.0;
    if (res[typ][wzr][zma][win1][win2] >= 0.0) return res[typ][wzr][zma][win1][win2];
    double s = val;
    if (val > 1.0){
        typ = 1;
        val = 1.0;
        double s = val;
        wzr = 0; zma = 0;
        res[typ][wzr][zma][win1][win2] = 
            (s * ps + (1.0 - s) * pr) * getp(typ, val, 0, 0, win1+1, win2) +
            //(s * ps + (1.0 - s) * pr) * (1.0 - pwzr) * getp(typ, val, 0, 0, win1+1, win2) +
            ((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * pzma * getp(typ, val - decr, 0, 1, win1, win2 + 1) +
            ((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * (1.0 - pzma) * getp(typ, val, 0, 0, win1, win2 + 1);
    }
    else if (val < 0.0){
        wzr = 0; zma = 0;
        typ = 2;
        val = 0.0;
        double s = val;
        res[typ][wzr][zma][win1][win2] = 
            (s * ps + (1.0 - s) * pr) * pwzr * getp(typ, val + incr, 1, 0, win1+1, win2) +
            (s * ps + (1.0 - s) * pr) * (1.0 - pwzr) * getp(typ, val, 0, 0, win1+1, win2) +
            ((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * getp(typ, val, 0, 0, win1, win2 + 1);
            //((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * (1.0 - pzma) * getp(typ, val, 0, 0, win1, win2 + 1);
    }
    else {
        res[typ][wzr][zma][win1][win2] = 
            (s * ps + (1.0 - s) * pr) * pwzr * getp(typ, val + incr, wzr + 1, zma, win1+1, win2) +
            (s * ps + (1.0 - s) * pr) * (1.0 - pwzr) * getp(typ, val, wzr, zma, win1+1, win2) +
            ((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * pzma * getp(typ, val - decr, wzr, zma+1, win1, win2 + 1) +
            ((1.0 - s) * (1.0 - pr) + s * (1.0 - ps)) * (1.0 - pzma) * getp(typ, val, wzr, zma, win1, win2 + 1);
    }
    return res[typ][wzr][zma][win1][win2];
}

void solve(int no){
    cin >> k;
    REP(xx,3) REP(i,k) REP(j,k) REP(i1,k) REP(j1,k) res[xx][i][j][i1][j1] = -1.0;
    cin >> ps >> pr >> pstart >> incr >> pwzr >> decr >>pzma;
    
    printf("Case #%d: %.6lf\n",no,getp(0, pstart, 0,0,0,0));
}
int main(){
    cerr << "Allocated" << endl;
    int t;
    cin >> t;
    REP(i,t){
        solve(i+1);
    }
}

//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

template<class T>
ostream& operator<<(ostream&o, const vector<T>&v) {
  o<<'{';
  FOREACH(it,v) o<<*it<<',';
  return o<<'}';
}
typedef long long LL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
//}}}

const int MAXN = 256;
const int MAXF = 11;
int N, F;
int weight[MAXN];
bool conn[MAXN][MAXN];
pair<int,int> dist[MAXN+1][MAXN];

void readInput() {
  N = rint();
  F = rint();
  int M = rint();
  REP(a,N) REP(b,N) conn[a][b] = false;
  REP(i,M) {
    int a = rint();
    int b = rint();
    conn[a][b] = true;
    conn[b][a] = true;
  }
  REP(i,N) weight[i] = rint();
}

inline pair<int,int> add(pair<int,int> a, pair<int,int> b) {
  return make_pair(a.first+b.first, a.second+b.second);
}

void calcDist() {
  REP(a,N) REP(b,N) dist[a][b] = make_pair(INF,INF);
  REP(a,N) dist[a][a] = make_pair(0,0);
  REP(a,N) REP(b,N) if(a!=b && conn[a][b]) dist[a][b] = make_pair(weight[b],1);
  REP(c,N) REP(a,N) REP(b,N) dist[a][b] = min(dist[a][b], add(dist[a][c], dist[c][b]));
  REP(a,N) dist[N][a] = make_pair(weight[a],1);
}

pair<int,int> cache[1<<MAXF][MAXN+1];

pair<int,int> calc(int s, int root) {
  pair<int,int> &res = cache[s][root];
  if(res.first != -1) return res;
  res = make_pair(INF,INF);
  if(s==0) {
    res = make_pair(0,0);
    return res;
  }
  REP(r,N) {
    bool real = (r<F && (s&(1<<r))!=0);
    int s2 = s;
    if(real) s2 &= ~(1<<r);
    int L = s2;
    for(;;) {
      int R = s2^L;
      if((!real && (L==0 || R==0)) || L>R) {} else {
        pair<int,int> resL = calc(L, r);
        pair<int,int> resR = calc(R, r);
        pair<int,int> vv;
        vv.first = dist[root][r].first + resL.first + resR.first;
        vv.second = dist[root][r].second + resL.second + resR.second;
        if(vv<res) res=vv;
      }
      if(!L) break;
      L = s2&(L-1);
    }
  }
  return res;
}

pair<int,int> calc() {
  calcDist();
  REP(a,1<<F) REP(b,MAXN+1) cache[a][b].first = -1;
  return calc((1<<F)-1, N);
}

int main(int argc, char **argv) {
  int ntc = rint();
  int tc0, tc1;
  if(argc==1) { tc0=0; tc1=ntc-1; }
  else if(argc==3) { tc0 = atoi(argv[1]); tc1 = atoi(argv[2]); }
  else {
    fprintf(stderr, "BAD\n"); return 1;
  }
  REP(tc,ntc) {
    readInput();
    if(tc<tc0 || tc>tc1) continue;
    pair<int,int> res = calc();
    printf("%d %d\n", res.first, res.second);
    fflush(stdout);
  }
}



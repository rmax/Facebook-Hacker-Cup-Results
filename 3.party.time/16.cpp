//#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<sstream>
#include<cstring>
#include<numeric>
using namespace std;

#define FOR(I,A,B) for(int I=(A);I<=(B);I++)
#define FORD(I,A,B) for(int I=(A);I>=(B);I--)
#define REP(I,N) for(int I=0;I<(N);I++)
#define ALL(X) (X).begin(),(X).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define INFTY 100000000
#define VAR(V,init) __typeof(init) V=(init)
#define FORE(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define SIZE(x) ((int)(x).size())

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long ll;
typedef vector<string> VS;

ll nwd(ll a,ll b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }
template <class T> inline T sqr(const T&a) { return a*a; }

VS parse(string s)
{
  string a;
  VS wyn;
  REP(i,(int)s.size())
    if (s[i]!=' ') a+=s[i];
    else if (!a.empty()) { wyn.PB(a); a=""; }
  if (!a.empty()) wyn.PB(a);
  return wyn;
}

int toi(char ch) { return int(ch)-int('0'); }

int chg(char ch) { return int(ch)-int('a'); }

int los(int m)
{
  return (int)((double)m*(rand()/(RAND_MAX+1.0)));
}

#define M 260

int ile,n,f,m;
int w[M];

PII t[M][M];

PII tab[1<<11][M];

void doit()
{
  int F=f;
  REP(mask,(1<<F)) REP(v,n) tab[mask][v]=MP(INFTY,INFTY);
  REP(v,n) tab[0][v]=t[v][v];
  REP(mask,(1<<F)) if (mask)
  {
    int ww=0,x=-1;
    REP(i,f) if (mask&(1<<i)) { x=i; ww++; }
    if (ww==1)
    {
      REP(v,n) tab[mask][v]=t[x][v];
      continue;
    }
    REP(v,n)
    {
      int mask1=mask;
      while (mask1>0)
      {
        mask1--;
        if (mask1<=0) break;
        mask1 &= mask;
        int m1=mask1; if (v<F) m1 ^= (1<<v);
        int m2=mask ^ mask1; if (v<F) m2 ^= (1<<v);
        tab[mask][v]=min(tab[mask][v],MP(tab[m1][v].FI+tab[m2][v].FI-w[v],tab[m1][v].SE+tab[m2][v].SE-1));
      }
    }
    REP(v,n) REP(u,n) tab[mask][v]=min(tab[mask][v],MP(tab[mask][u].FI+t[u][v].FI-w[u],tab[mask][u].SE+t[u][v].SE-1));
  }
  PII wyn=MP(INFTY,INFTY);
  REP(v,n) wyn=min(wyn,tab[(1<<f)-1][v]);
  printf("%d %d\n",wyn.FI,wyn.SE);
}

int main()
{
  scanf("%d",&ile);
  while (ile--)
  {
    vector<PII> pom;
    scanf("%d%d%d",&n,&f,&m);
    REP(i,n) REP(j,n) t[i][j]=MP(INFTY,INFTY);
    while (m--)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      pom.PB(MP(a,b));
    }
    REP(i,n) scanf("%d",w+i);
    REP(i,SIZE(pom))
    {
      int a=pom[i].FI,b=pom[i].SE;
      t[a][b]=t[b][a]=MP(w[a]+w[b],2);
    }
    REP(i,n) t[i][i]=MP(w[i],1);
    REP(k,n) REP(i,n) REP(j,n)
    {
      t[i][j]=min(t[i][j],MP(t[i][k].FI+t[k][j].FI-w[k],t[i][k].SE+t[k][j].SE-1));
    }
    doit();
  }
  return 0;
}

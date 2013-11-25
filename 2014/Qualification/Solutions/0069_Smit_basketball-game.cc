#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >


void precompute(void) {
}

vector < int > inMatch(vector < int > members, int p, int m) {
  vector < PII > in, out;
  int tim[32],sz = members.size();
  if(sz == p) 
    return members;
  vector < int > ret;
  for(int i=0;i<sz;i++) {
    tim[i] = 0;
    if(i<p) {
      in.PB(MP(-tim[i],-i));
    } else {
      out.PB(MP(tim[i],i));
    }
  }
  int innx[32];
  while(m--) {
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    memset(innx, 0, sizeof(innx));
    for(int i=0;i<p;i++) {
      tim[-in[i].second]++;
      innx[-in[i].second] = 1;
    }
    innx[-in[0].second] = 0;
    innx[out[0].second] = 1;
    in.clear();
    out.clear();
    for(int i=0;i<sz;i++) {
      if(innx[i]) {
        in.PB(MP(-tim[i],-i));
      } else {
        out.PB(MP(tim[i],i));
      }
    }
  }
  for(int i=0;i<p;i++) {
    ret.PB(members[-in[i].second]);
  }
  return ret;
}


int main() {
	int t;
	precompute();
  int n,m,p,shot[32],hei[32];
  string name[32];
  vector < string > lis;
  vector < VI > team;
  vector < pair < PII , int > > sorted;
	while(scanf("%d",&t)!=EOF) {
    int test = 1;
		while(t--) {
		  cin>>n>>m>>p;
      sorted.clear();
      for(int i=0;i<n;i++) {
        cin>>name[i]>>shot[i]>>hei[i];
        sorted.PB(MP(MP(shot[i], hei[i]),i));
      }
      sort(sorted.rbegin(), sorted.rend());
      team.clear();
      team.resize(2);
      for(int i=0;i<n;i++) {
        team[i%2].PB(sorted[i].second);
      }
      team[0] = inMatch(team[0],p,m);
      team[1] = inMatch(team[1],p,m);
      lis.clear();
      for(int i=0;i<p;i++) {
        lis.PB(name[team[0][i]]);
        lis.PB(name[team[1][i]]);
      }
      sort(lis.begin(), lis.end());
      printf("Case #%d:",test++);
      for(int i=0;i<2*p;i++) {
        printf(" %s",lis[i].c_str());
      }
      printf("\n");
    }
	}
	return 0;
}

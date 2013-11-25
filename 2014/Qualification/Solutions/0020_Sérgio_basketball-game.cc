#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define iter(a) typeof((a).begin())
#define Tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1; a>=b ; --a )
#define Rp(a,b) Fr(a,0,b)
#define fr Fr
#define rp Rp
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define dbg if(0)




struct P{
	string nome;
	int sp, h;
	bool operator <(const struct P &lhs) const{
		if(sp != lhs.sp) return sp > lhs.sp;
		return h > lhs.h;
	}
}p[220];

string rs[220];


int tempo[220];
int n,m,t,pp;

bool ta[220];


int who(int st){
	int pn = -1, tpn = INF;
	for(int i = st; i < n; i += 2){
		if(ta[i] == false && tempo[i] < tpn) tpn = tempo[i], pn = i;
	}
	return pn;
}

int out(int st){
	int pn = -1, tpn = -1;
	for(int i = st; i < n; i += 2){
		if(ta[i] == true && tempo[i] >= tpn) tpn = tempo[i], pn = i;
	}
	return pn;
}


int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		printf("Case #%d:",cas);
		scanf("%d %d %d",&n,&m,&pp);
		fr(i,0,n){
			cin>>p[i].nome;
			scanf("%d %d",&p[i].sp,&p[i].h);
		}
		sort(p,p+n);
		memset(tempo, 0, sizeof tempo);
		memset(ta,false,sizeof ta);
		fr(i,0,2*pp) ta[i] = true;
		fr(i,0,m){
			fr(j,0,n) if(ta[j]) tempo[j]++;
			int ot1 = out(0), ot2 = out(1);
			ta[ot1] = ta[ot2] = false;
			int it1 = who(0), it2 = who(1);
			ta[it1] = ta[it2] = true;
			//printf(">%d %d %d %d\n",it1,it2,ot1,ot2);
		}
		int nrs = 0;
		fr(i,0,n) if(ta[i]) rs[nrs++] = p[i].nome;
		sort(rs,rs+nrs);
		fr(i,0,nrs) printf(" %s",rs[i].c_str());
		puts("");
	}
	return 0;
}















































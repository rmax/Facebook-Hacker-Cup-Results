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

int arr[100];
int t,n;
char gr[100][100];

bool valid(int a, int b){
	return a >= 0 && a < n && b >= 0 && b < n;
}


int main(){
	scanf("%d",&t);
	fr(i,0,100) arr[i] = i*i;
	fr(cas,1,t+1){
		scanf("%d",&n);
		int qt = 0;
		int fx = -1, fy = -1;
		fr(i,0,n){ 
			scanf("%s",gr[i]);
			fr(j,0,n){ 
				if(gr[i][j] == '#'){ 
					qt++;
					if(fx == -1) fx = i, fy = j;
				}
			}
		}
		int tam = -1;
		fr(i,0,100){
			if(qt == arr[i]) tam = i;
		}
		bool im = tam == -1;
		fr(i,0,tam){
			fr(j,0,tam){
				if(!valid(i+fx,j+fy) || gr[i+fx][j+fy] == '.') im = true;
			}
		}
		if(im) printf("Case #%d: NO\n",cas);
		else printf("Case #%d: YES\n",cas);
	}
	return 0;
}




































#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define MP make_pair
#define fi first
#define se second

int a[255][255];
int g[255];
int d[255][255];
int e[255][255];
pair<int,int> F[255][1<<11];
int n, m, k;

int main() {
	int ntest;
	scanf("%d", &ntest);
	Rep(test,ntest) {
		cerr << "run test = " << test << endl;
		scanf("%d%d%d", &n, &k, &m);
		memset(a,0,sizeof(a));
		Rep(i,m) {
			int u, v;
			scanf("%d%d", &u, &v);	
			a[u][v] = a[v][u] = 1;
		}	
		Rep(i,n) scanf("%d", g+i);
		memset(d,0x1f,sizeof(d));
		memset(e,0x1f,sizeof(e));
		Rep(i,n) d[i][i] = g[i], e[i][i] = 1;
		Rep(i,n) Rep(j,n) if(a[i][j]) {
			d[i][j] = g[i] + g[j];
			e[i][j] = 2;
		}
		Rep(k,n) Rep(i,n) Rep(j,n) {
			if(d[i][j] > d[i][k] + d[k][j] - g[k] || (d[i][j] == d[i][k] + d[k][j] - g[k] && e[i][j] > e[i][k] + e[k][j] - 1))
			{
				d[i][j] = d[i][k] + d[k][j] - g[k];
				e[i][j] = e[i][k] + e[k][j] - 1;	
			}
		}
		memset(F,0x1f,sizeof(F));
		pair<int,int> p;
		for(int b=1;b<1<<k;++b) {
			int bc = 0;
			int id = -1;
			Rep(i,k) if((b&(1<<i))!=0) ++bc, id = i;
			if(bc == 1) {
				Rep(i,n) F[i][b] = MP(d[i][id], e[i][id]);
			}
			else {
				int s = b;
				s = (s - 1) & b;	
				while(s > 0) {
					Rep(i,n) {
						p.fi = F[i][s].fi + F[i][b^s].fi - g[i];
						p.se = F[i][s].se + F[i][b^s].se - 1;
						F[i][b] = min( F[i][b], p);
					}
					s = (s - 1) & b;	
				}
				Rep(i,n) Rep(j,n) {
					p.fi = F[i][b].fi + d[i][j] - g[i];
					p.se = F[i][b].se + e[i][j] - 1;
					F[j][b] = min( F[j][b], p);
				}
			}
		}
		cout << F[0][(1<<k)-1].fi << " " << F[0][(1<<k)-1].se << endl;
	}
    return 0;    
}

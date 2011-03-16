#include <iostream>
#include <vector>
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

#define sqr(x) ((x)*(x))

const int MAX = 50;

struct data {
	int x, y, z;
	int val;
	bool operator<(data d)const{
		return val > d.val;	
	}	
};

int n;
int X[222], Y[222], Z[222];
vector<data> res;
int result;

int calc(int x, int y, int z) {
	int dmin = 1000000000;
	Rep(i,n) {
		int d = sqr(X[i]-x) + sqr(Y[i]-y) + sqr(Z[i]-z);
		dmin = min(d,dmin);
	}	
	return dmin;
}

void process(int x, int y, int z, int ax, int ay, int az) {
	int best = -1;
	int xb, yb, zb;
	Rep(k,15) {
		int bx = rand() % ax;
		int by = rand() % ay;
		int bz = rand() % az;
		int cur = calc(x + bx, y + by, z + bz);
		if(cur > best) {
			best = cur;
			xb = x + bx;
			yb = y + by;
			zb = z + bz;
		}
	}	
	data d; d.x = xb, d.y = yb, d.z = zb;
	d.val = best;
	res.pb(d);
	sort(res.begin(),res.end());
	if(res.size() > MAX) res.pop_back();
}

void pro2(data d) {
	For(x,-15,15) For(y,-15,15) For(z,-15,15) {
		int u = d.x + x;
		int v = d.y + y;
		int t = d.z + z;
		if(0 <= u && u <= 1000 && 0 <= v && v <= 1000 && 0 <= t && t <= 1000) {
			int val = calc(u,v,t);
			if(val > result) result = val;	
		}
	}	
}

int main() {
	int tbegin = clock();
	srand(time(0));
	int ntest;
	scanf("%d", &ntest);
	Rep(test,ntest) {
		cerr << "run test = " << test << endl;
		scanf("%d", &n);	
		Rep(i,n) scanf("%d%d%d", X+i, Y+i, Z+i);
		res.clear();
		result = -1;
		Rep(x,50)Rep(y,50)Rep(z,50) {
			int ax, ay, az;
			ax = ay = az = 20;
			if(x == 49) ax = 21;
			if(y == 49) ay = 21;
			if(z == 49) az = 21;
			process( x * 20, y * 20, z * 20, ax, ay, az);	
		}
		Rep(i,res.size()) {
			pro2(res[i]);	
		}
		cout << result << endl;
	}
	cerr << clock() - tbegin << endl;
    return 0;    
}

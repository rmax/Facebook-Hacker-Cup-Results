#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

#define INF 1000
#define MAXN 30
char A[MAXN][MAXN];
int main () {
	int TEST,N;
	cin >> TEST;
	FOR(test,TEST) {
		cin >> N;
		FOR(i,N) scanf("%s",A[i]);
		int minr = INF, maxr = -1, minc = INF, maxc = -1;
		
		FOR(i,N) FOR(j,N) if (A[i][j] == '#')
			minr = min(minr,i), maxr = max(maxr,i),
			minc = min(minc,j), maxc = max(maxc,j);
		
		bool good = true;
		FORALL(i,minr,maxr) FORALL(j,minc,maxc)
			if (A[i][j] == '.') good = false;
		
		if (maxr-minr != maxc-minc) good = false;
		
		printf("Case #%d: %s\n", (test+1), (good?"YES":"NO"));
	}
}












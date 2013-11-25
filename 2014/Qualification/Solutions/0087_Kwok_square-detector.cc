#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, ans;
char a[100][100];

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d: ", rr);
		scanf("%d", &m);
		for (int i=0; i<m; i++)
			scanf("%s", a[i]);
		cnt = 0;
		for (int i=0; i<m; i++)
			for (int j=0; j<m; j++)
				if (a[i][j] == '#')
					cnt++;
		q = -1;
		for (int i=0; i<m; i++){
			for (int j=0; j<m; j++)
				if (a[i][j] == '#'){
					q = i, w = j;
					break;
				}
			if (q != -1)
				break;
		}
		e = -1;
		for (int i=m-1; i>=0; i--){
			for (int j=m-1; j>=0; j--)
				if (a[i][j] == '#'){
					e = i, r = j;
					break;
				}
			if (e != -1)
				break;
		}
		s = 0;				
		for (int i=q; i<=e; i++)
			for (int j=w; j<=r; j++)
				if (a[i][j] == '#')
					s++;
		if (s == cnt && s == (e-q+1)*(r-w+1) && r-w == e-q)
			puts("YES");
		else puts("NO");

	}
	return 0;
}

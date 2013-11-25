#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

struct playerType{
	int id;
	int h, s;
};

playerType player[50];

struct playerTypeCourt{
	int id;
	int draft;
	int time;
};

playerTypeCourt a[4][50];

bool ss(playerType q, playerType w){
	return q.s < w.s || q.s == w.s && q.h < w.h;
};

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, p;
char tempString[100];
string ans[20];
map<int, string> map1;

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		map1.clear();
		printf("Case #%d:", rr);
		scanf("%d %d %d", &n, &m, &p);
		for (int i=0; i<n; i++){
			scanf("%s %d %d", tempString, &q, &w);
			player[i].id = i;
			player[i].s = q;
			player[i].h = w;
			string tt;
			tt.assign(tempString);
			map1[i] = tt;
		}
		sort(player, player + n, ss);
		for (int i=0; i<4; i++)
			for (int j=0; j<50; j++)
				a[i][j].time = -1;
		for (int i=0; i<n-2*p; i++){
			a[i%2][i/2].id = player[i].id;
			a[i%2][i/2].draft = n - i - 1;
			a[i%2][i/2].time = 0;
		}
		for (int i=n-2*p; i<n; i++){
			a[i%2+2][(i-(n-2*p))/2].id = player[i].id;
			a[i%2+2][(i-(n-2*p))/2].draft = n - i - 1;
			a[i%2+2][(i-(n-2*p))/2].time = 1;
		}
		for (int k=1; k<=m; k++){
			/*			
							printf("%d\n", k);
							for (int i=0; i<2; i++){
							for (int j=0; j<p; j++)
							printf("%s ", map1[a[i+2][j].id].c_str());
							puts("");
							}
			 */			
			for (int i=0; i<2; i++){
				int maxTime = -1;
				int maxDraft = -1;
				int maxIndex;
				for (int j=0; j<p; j++)
					if (a[i+2][j].time > maxTime || a[i+2][j].time == maxTime && a[i+2][j].draft > maxDraft)
						maxTime = a[i+2][j].time, maxDraft = a[i+2][j].draft, maxIndex = j;
				int minTime = oo;
				int minDraft = oo;
				int minIndex;
				for (int j=0; a[i][j].time != -1; j++)
					if (a[i][j].time < minTime || a[i][j].time == minTime && a[i][j].draft < minDraft)
						minTime = a[i][j].time, minDraft = a[i][j].draft, minIndex = j;
				if (minTime != oo)
					swap(a[i+2][maxIndex], a[i][minIndex]);
				for (int j=0; j<p; j++)
					a[i+2][j].time++;
			}
		}
		LL ansCnt = 0;
		for (int i=0; i<2; i++)
			for (int j=0; j<p; j++)
				ans[ansCnt++] = map1[a[i+2][j].id];
		sort(ans, ans + ansCnt);
		for (int i=0; i<ansCnt; i++)
			printf(" %s", ans[i].c_str());
		puts("");
	}
	return 0;
}

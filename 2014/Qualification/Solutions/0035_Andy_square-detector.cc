#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int Nc, N;
char grid[32][32];
char cline[1024];
int lower_bounds[2], upper_bounds[2];

int main() {
	scanf("%d",&Nc);
	for(int cc = 1; cc <= Nc; cc++)	{
		scanf("%d",&N);
		memset(grid,'.',sizeof(grid));
		for(int i = 0; i < N; i++) { 
			scanf("%s",cline);
			for(int j = 0; j < N; j++)
				grid[i+1][j+1] = cline[j];
		}
		lower_bounds[0] = lower_bounds[1] = 1<<20;
		upper_bounds[0] = upper_bounds[1] = -1*(1<<20);
		int cnt = 0;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++) {
				if(grid[i][j] == '#') {
					lower_bounds[0] = min(lower_bounds[0],i);
					lower_bounds[1] = min(lower_bounds[1],j);
					upper_bounds[0] = max(upper_bounds[0],i);
			 		upper_bounds[1] = max(upper_bounds[1],j);
					cnt++;
				}
			}
		int w = upper_bounds[0] - lower_bounds[0] + 1;
		int h = upper_bounds[1] - lower_bounds[1] + 1;
		char ok = (w == h) && (cnt == (w*h));
		printf("Case #%d: %s\n",cc,ok?"YES":"NO");
		
	}
	return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int T,N,M,P;
string names[30];
int players[30][2];
int order[30];
char onfield[30];
int played[30];
string playing[30];

int main() {
	scanf("%d",&T);
	for(int cc = 1; cc <= T; cc++) {
		scanf("%d%d%d",&N,&M,&P);
		for(int i = 0; i < N; i++) {
			char cn[32];
			scanf("%s%d%d",cn,&players[i][0],&players[i][1]);
			names[i] = string(cn);
			order[i] = i;
		}	
		for(int i = 0; i < N; i++)
			for(int j = 1; j < N; j++) {
				if((players[order[j-1]][0] < players[order[j]][0]) ||
					(players[order[j-1]][0] == players[order[j]][0] && players[order[j-1]][1] < players[order[j]][1]))
					swap(order[j-1],order[j]);
			}
		memset(played,0,sizeof(played));
		memset(onfield,0,sizeof(onfield));
		for(int i = 0; i < P; i++)
			onfield[order[2*i]] = onfield[order[2*i+1]] = 1;
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < N; j++)
				if(onfield[j]) played[j]++;
			int bench[2], send[2];
			bench[0] = bench[1] = send[0] = send[1] = -1;
			for(int j = 0; j < N; j++) {
				if(onfield[order[j]]) {
					if(bench[j%2] == -1)
						bench[j%2] = order[j];
					else if(played[order[j]] >= played[bench[j%2]])
						bench[j%2] = order[j];
				}
			}
			onfield[bench[0]] = onfield[bench[1]] = 0;
			for(int j = 0; j < N; j++) {
				if(!onfield[order[j]]) {
					if(send[j%2] == -1)
						send[j%2] = order[j];
					else if(played[order[j]] < played[send[j%2]])
						send[j%2] = order[j];
				}
			}
			onfield[send[0]] = onfield[send[1]] = 1;
			//printf("T: %d\n",i);
			//for(int j = 0; j < N; j++)
			//	if(onfield[j]) printf("%s\n",names[j].c_str());
		}
		int p = 0;
		for(int i = 0; i < N; i++)
			if(onfield[i]) playing[p++] = names[i];
		sort(playing,playing+2*P);
		printf("Case #%d:",cc);
		for(int i = 0; i < p; i++)
			printf(" %s",playing[i].c_str());
		printf("\n");	
	}
	return 0;
}

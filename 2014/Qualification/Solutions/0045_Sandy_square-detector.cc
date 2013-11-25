#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

#define PI M_PI
#define LL long long
#define INF 2123123123
#define MP(a,b) make_pair(a,b)

using namespace std;

struct data{
	int black;
	int top,left,right,bot;
	data()
	{
		black = 0;
	}
}rect[500];

int t,n;
char ar[25][25];
int ctr;

void dfs(int i,int j)
{
	ar[i][j] = '.';
	rect[ctr].black++;
	rect[ctr].top = min(rect[ctr].top,i);
	rect[ctr].bot = max(rect[ctr].bot,i);
	rect[ctr].left = min(rect[ctr].left,j);
	rect[ctr].right = max(rect[ctr].right,j);
	if (i+1<n && ar[i+1][j]=='#') dfs(i+1,j);
	if (i-1>=0 && ar[i-1][j]=='#') dfs(i-1,j);
	if (j+1<n && ar[i][j+1]=='#') dfs(i,j+1);
	if (j-1>=0 && ar[i][j-1]=='#') dfs(i,j-1);
}

bool check(int idx)
{
//	printf("%d = %d\n",rect[idx].black,(rect[idx].bot-rect[idx].top+1)*(rect[idx].right-rect[idx].left+1));
	if ((rect[idx].black==(rect[idx].bot-rect[idx].top+1)*(rect[idx].right-rect[idx].left+1)) && ((rect[idx].bot-rect[idx].top+1)==(rect[idx].right-rect[idx].left+1)) ) return true;
	return false;
}

void reset()
{
	ctr = 0;
}

int main()
{
	//freopen("square_detector.txt","r",stdin);
	//freopen("square_detector_out.txt","w",stdout);
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		reset();
		scanf("%d",&n);
		
		for (int i=0;i<n;i++) scanf("%s",ar[i]);
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (ar[i][j]=='#')
				{
					rect[ctr].black = 0;
					rect[ctr].bot = rect[ctr].right = -1;
					rect[ctr].top = rect[ctr].left = INF;
					dfs(i,j);
					ctr++;
				}
			}
		}
	//	printf("%d\n",ctr);
		if (ctr>1) printf("Case #%d: NO\n",tc);
		else
		{
			if (check(0)) printf("Case #%d: YES\n",tc);
			else printf("Case #%d: NO\n",tc);
		}
	}
	
 	return 0;
}


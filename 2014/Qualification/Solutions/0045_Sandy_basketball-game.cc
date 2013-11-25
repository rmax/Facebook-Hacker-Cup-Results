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
	string name;
	int shot;
	int height;
	int draft;
	int time;
}player[100];

struct orderByLowTimeDraft
{
	bool operator ()(data i,data j)
	{
		if (i.time < j.time) return false;
		else if (i.time == j.time)
		{
			if (i.draft < j.draft) return false;
		}
		return true;
	}	
};

struct orderByHighTimeDraft
{
	bool operator () (data i,data j)
	{
		if (i.time > j.time) return false;
		else if (i.time == j.time)
		{
			if (i.draft > j.draft) return false;
		}
		return true;
	}
};

priority_queue<data, vector<data>, orderByLowTimeDraft> pq1bench,pq2bench;
priority_queue<data, vector<data>, orderByHighTimeDraft> pq1field,pq2field,pqfieldtemp;

bool f(data i, data j)
{
	if (i.shot > j.shot) return true;
	else if (i.shot==j.shot)
	{
		if (i.height > j.height) return true;
	}
	return false;
}

int t,n,m,p;
data temp;
vector<string> ans;

void reset()
{
	while(!pq1bench.empty()) pq1bench.pop();
	while(!pq2bench.empty()) pq2bench.pop();
	while(!pq1field.empty()) pq1field.pop();
	while(!pq2field.empty()) pq2field.pop();
	ans.clear();
}

void updatePQ1field()
{
	while(!pqfieldtemp.empty()) pqfieldtemp.pop();
	
	for (int i=0;i<p;i++)
	{
		temp = pq1field.top();
		pq1field.pop();
		temp.time++;
		pqfieldtemp.push(temp);
	}
	
	pq1field = pqfieldtemp;
}

void updatePQ2field()
{
	while(!pqfieldtemp.empty()) pqfieldtemp.pop();
	
	for (int i=0;i<p;i++)
	{
		temp = pq2field.top();
		pq2field.pop();
		temp.time++;
		pqfieldtemp.push(temp);
	}
	
	pq2field = pqfieldtemp;
}

int main()
{
	freopen("basketball_game.txt","r",stdin);
	freopen("basketball_game_out.txt","w",stdout);
	
	scanf("%d",&t);
	
	for (int tc=1;tc<=t;tc++)
	{
		reset();
		
		scanf("%d %d %d",&n,&m,&p);
		
		for (int i=0;i<n;i++)
		{
			cin >> player[i].name >> player[i].shot >> player[i].height;
		}
		sort(player,player+n,f);
		for (int i=0;i<n;i++)
		{
			player[i].draft = i+1;
			player[i].time = 0;
		}
		
		for (int i=0;i<n;i++)
		{
			if (player[i].draft%2==1) pq1bench.push(player[i]);
			else pq2bench.push(player[i]);
		}
		
		//start
		for (int i=0;i<p;i++)
		{
			temp = pq1bench.top();
			pq1bench.pop();
			pq1field.push(temp);
			
			temp = pq2bench.top();
			pq2bench.pop();
			pq2field.push(temp);
		}
		
		//rotation
		for (int i=1;i<=m;i++)
		{
			//update
			updatePQ1field();
			updatePQ2field();
			
			//leave
			temp = pq1field.top();
			pq1field.pop();
			pq1bench.push(temp);
			
			temp = pq2field.top();
			pq2field.pop();
			pq2bench.push(temp);
			
			//in
			temp = pq1bench.top();
			pq1bench.pop();
			pq1field.push(temp);
			
			temp = pq2bench.top();
			pq2bench.pop();
			pq2field.push(temp);
		}
		
		while(!pq1field.empty())
		{
			temp = pq1field.top();
			pq1field.pop();
			ans.push_back(temp.name);
		}
		while(!pq2field.empty())
		{
			temp = pq2field.top();
			pq2field.pop();
			ans.push_back(temp.name);
		}
		
		sort(ans.begin(),ans.end());
		
		printf("Case #%d:",tc);
		for (int i=0;i<ans.size();i++) printf(" %s",ans[i].c_str());
		printf("\n");
	}
	
 	return 0;
}


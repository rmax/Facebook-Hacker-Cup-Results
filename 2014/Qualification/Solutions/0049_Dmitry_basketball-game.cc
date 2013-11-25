#pragma comment (linker, "/STACK:268435456")
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <functional>
#include <complex>
#include <numeric>
#include <utility>
#include <cstdlib>

using namespace std;

struct player
{
	string name;
	int perc, h, on;

	bool operator< (const player &p) const
	{
		if (perc != p.perc)
			return perc > p.perc;
		return h > p.h;
	}

	void scan()
	{
		cin >> name >> perc >> h;
		on = 0;
	}
};

int n, m, team;
player p[40];
int d[40];
int t[40];

void solve(int n)
{
	memset(d, 0, sizeof d);
	memset(t, 0, sizeof t);
	for (int i = 0; i < team; i++)
		d[i] = 1;
	if (team == n)
		return;
	for (int i = 0; i < m; i++)
	{
		int leave = -1;
		int enter = -1;
		for (int j = 0; j < n; j++)
			if (d[j])
			{
				t[j]++;
				if (leave == -1 || t[j] >= t[leave])
					leave = j;
			}
			else if (enter == -1 || t[j] < t[enter])
				enter = j;
		d[leave] = 0;
		d[enter] = 1;
	}
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	cin >> n >> m >> team;
    	for (int i = 0; i < n; i++)
    		p[i].scan();
    	sort(p, p + n);

    	solve(n - n / 2);
    	for (int i = 0; i < n - n / 2; i++)
    		p[i * 2].on = d[i];
    	solve(n / 2);
    	for (int i = 0; i < n / 2; i++)
    		p[i * 2 + 1].on = d[i];

    	vector<string> result;
    	for (int i = 0; i < n; i++)
    		if (p[i].on)
    			result.push_back(p[i].name);

    	sort(result.begin(), result.end());
    	cout << "Case #" << tc + 1 << ":";
    	if (2 * team != result.size())
    		cout << "ERROR";
    	for (int i = 0; i < 2 * team; i++)
    		cout << " " << result[i];
    	cout << endl;
    }
    return 0;
}

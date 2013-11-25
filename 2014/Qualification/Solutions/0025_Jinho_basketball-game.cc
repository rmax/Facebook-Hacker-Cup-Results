#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

struct Player
{
	string name;
	int percent;
	int height;

	bool operator < (const Player &p) const
	{
		if (percent != p.percent)
			return percent < p.percent;
		return height < p.height;
	}
};

vector<int> getRemain(int n, int m, int p)
{
	vector<int> ret;
	if (n == p)
	{
		for (int i = 0; i < n; ++i)
			ret.push_back(i);
		return ret;
	}
	vector<int> time(n, 0);
	vector<int> playing(n, 0);

	// at first, only p players playing at a time.
	for (int i = 0; i < p; ++i)
		playing[i] = 1;
	// total game - m minutes
	for (int i = 0; i < m; ++i) 
	{
		// one minutes
		for (int j = 0; j < n; ++j)
			if (playing[j]) time[j]++;

		int outplayer = -1, inplayer = -1;
		for (int j = 0; j < n; ++j) {
			if (playing[j] == 1)
			{
				// choose out player.
				if (outplayer == -1) outplayer = j;
				if (time[j] >= time[outplayer]) outplayer = j;
			}
			else
			{
				// choose in player.
				if (inplayer == -1) inplayer = j;
				if (time[j] < time[inplayer]) inplayer = j;
			}
		}

		playing[inplayer] = 1;
		playing[outplayer] = 0;
	}

	for (int i = 0; i < n; ++i) 
	{
		if (playing[i] == 1)
		{
			ret.push_back(i);
		}
	}

	return ret;
}

int main() {
	int T;
	cin >> T;
	for (int cn = 1; cn <= T; ++cn) 
	{
		printf("Case #%d:", cn);
		int n, m, p;
		cin >> n >> m >> p;
		vector<Player> a(n);
		for (int i = 0; i < n; ++i) 
		{
			cin >> a[i].name >> a[i].percent >> a[i].height;
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		vector<string> ret;

		vector<Player> team1, team2;
		for (int i = 0; i < n; ++i)
		{
			if (i % 2 == 0) 
				team1.push_back(a[i]);
			else
				team2.push_back(a[i]);
		}

		vector<int> remain1 = getRemain(team1.size(), m, p);
		for (int i = 0; i < remain1.size(); ++i)
			ret.push_back(team1[remain1[i]].name);

		vector<int> remain2 = getRemain(team2.size(), m, p);
		for (int i = 0; i < remain2.size(); ++i)
			ret.push_back(team2[remain2[i]].name);
			
		sort(ret.begin(), ret.end());
		for (int i = 0; i < ret.size(); ++i)
			printf(" %s", ret[i].c_str());
		printf("\n");
	}
}

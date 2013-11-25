#include <bits/stdc++.h>
using namespace std;

struct player
{
	string name;
	int shotPer, height, timePlayed, isPlaying;
		
	bool operator < (player u) const
	{
		if (shotPer != u.shotPer) return shotPer > u.shotPer;
		return height > u.height;
	}
} a[33];

int n, m, p;

int comp(int u, int v)
{
	if (a[u].timePlayed != a[v].timePlayed) return a[u].timePlayed > a[v].timePlayed;
	return u > v;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int test;
	cin >> test;
	for (int idTest = 1; idTest <= test; idTest++)
	{
		cin >> n >> m >> p;
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i].name >> a[i].shotPer >> a[i].height;
			a[i].timePlayed = a[i].isPlaying = 0;
		}
		sort(a + 1, a + n + 1);
		
		vector <int> oddTeam, evenTeam;
		for (int i = 0; i < p; i++)
		{
			oddTeam.push_back(i * 2 + 1);
			a[i * 2 + 1].isPlaying = 1;
			evenTeam.push_back(i * 2 + 2);
			a[i * 2 + 2].isPlaying = 1;
		}
		
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < p; j++) 
			{
				a[oddTeam[j]].timePlayed++;
				a[evenTeam[j]].timePlayed++;
			}
			
			int oddOut = 0, evenOut = 0;
			for (int j = 1; j < p; j++)
			{
				if (comp(oddTeam[j], oddTeam[oddOut])) oddOut = j;
				if (comp(evenTeam[j], evenTeam[evenOut])) evenOut = j;
			}
			
			a[oddTeam[oddOut]].isPlaying = 0;
			oddTeam.erase(oddTeam.begin() + oddOut);
			
			a[evenTeam[evenOut]].isPlaying = 0;
			evenTeam.erase(evenTeam.begin() + evenOut);
			
			int oddIn = 0, evenIn = 0;
			for (int j = 1; j <= n; j++)
			{
				if (a[j].isPlaying) continue;
				if (j % 2)
				{
					if (!oddIn || comp(oddIn, j)) oddIn = j;
				}
				else
				{
					if (!evenIn || comp(evenIn, j)) evenIn = j;
				}
			}
			
			oddTeam.push_back(oddIn);
			a[oddIn].isPlaying = 1;
			
			evenTeam.push_back(evenIn);
			a[evenIn].isPlaying = 1;
		}
		
		vector <string> ans;
		for (int i = 1; i <= n; i++)
			if (a[i].isPlaying)
				ans.push_back(a[i].name);
		
		sort(ans.begin(), ans.end());
		cout << "Case #" << idTest << ":";
		for (int i = 0; i < p * 2; i++) cout << ' ' << ans[i];
		cout << endl;
		
	}
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
struct Rank
{
	int percentage, height;
	void read()
	{
		cin >> percentage >> height;
	}
	bool operator<(const Rank &rank) const
	{
		if (percentage != rank.percentage)
			return percentage > rank.percentage;
		return height > rank.height;
	}
};
struct Player
{
	string name;
	Rank rank;
	int minutes_played;
	Player()
	{
		cin >> name;
		rank.read();
		minutes_played = 0;
	};
	bool operator<(const Player &player) const
	{
		return rank < player.rank;
	}
};
struct cmp_field
{
	bool operator()(const Player &a, const Player &b) const
	{
		if (a.minutes_played != b.minutes_played)
			return a.minutes_played > b.minutes_played;
		return b.rank < a.rank;
	}
};
struct cmp_substitute
{
	bool operator()(const Player &a, const Player &b) const
	{
		if (a.minutes_played != b.minutes_played)
			return a.minutes_played < b.minutes_played;
		return a.rank < b.rank;
	}
};
void split(const vector<Player> &players,
	vector<Player> &team_a,
	vector<Player> &team_b)
{
	for (int i = 0; i < (int)players.size(); i++)
	{
		(i % 2 == 0 ? team_a : team_b).push_back(players[i]);
	}
}
void solve(const vector<Player> &team, int m, int p, vector<string> &output)
{
	vector<Player> field(team.begin(), team.begin() + p);
	vector<Player> substitute(team.begin() + p, team.end());
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < p; j++)
			field[j].minutes_played++;
		if (!substitute.empty())
		{
			vector<Player>::iterator in = min_element(
				substitute.begin(), substitute.end(), cmp_substitute());
			vector<Player>::iterator out = min_element(
				field.begin(), field.end(), cmp_field());
			swap(*in, *out);
		}
	}
	for (int i = 0; i < p; i++)
		output.push_back(field[i].name);
}
int main()
{
	int n_cases;
	cin >> n_cases;
	for (int t = 0; t < n_cases; t++)
	{
		int n, m, p;
		cin >> n >> m >> p;
		vector<Player> players;
		for (int i = 0; i < n; i++)
			players.push_back(Player());
		sort(players.begin(), players.end());
		vector<Player> team_a, team_b;
		split(players, team_a, team_b);
		vector<string> output;
		solve(team_a, m, p, output);
		solve(team_b, m, p, output);
		sort(output.begin(), output.end());
		cout << "Case #" << t + 1 << ":";
		for (int i = 0; i < 2 * p; i++)
			cout << " " << output[i];
		cout << endl;
	}
	return 0;
}

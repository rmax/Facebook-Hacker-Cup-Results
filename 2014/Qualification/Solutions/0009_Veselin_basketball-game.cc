#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

struct Player {
	string name;
	int minutesPlayed;
	int draft;
};

ostream& operator << (ostream& os, const Player& player)
{
	os << "(" << player.name << ", " << player.minutesPlayed << ", " << player.draft << ")";
	return os;
}

template <typename T> ostream& operator << (ostream& os, const vector<T>& vec)
{
	os << "{ "; for (size_t i = 0; i < vec.size(); i++) { if (i) os << ", "; os << vec[i]; }
	os << " }";
	return os;
}


inline bool higherMinutesHigherDraft(const Player& a, const Player& b)
{
	if (a.minutesPlayed != b.minutesPlayed) return a.minutesPlayed < b.minutesPlayed;
	return a.draft < b.draft;
}

inline bool lowerMinutesLowerDraft(const Player& a, const Player& b)
{
	if (a.minutesPlayed != b.minutesPlayed) return a.minutesPlayed > b.minutesPlayed;
	return a.draft > b.draft;
}

void solve(void)
{
	typedef pair<string, int> PSI;
	vector<PSI> players;
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	FOR(i, n) {
		char t[32];
		int shotPerc, height;
		scanf("%s%d%d", t, &shotPerc, &height);
		players.push_back(make_pair(string(t), shotPerc * 1000 + height));
	}
	// higher-rated players first:
	sort(players.begin(), players.end(), [](const PSI& a, const PSI& b) { return a.second > b.second; });
	
	// remap ranks:
	REP(i, players) players[i].second = i + 1; // 1..N
	
	vector<Player> teams[2];
	vector<Player> benches[2];
	
	FOR(i, n) {
		Player plr = { players[i].first, 0, players[i].second };
		if (i < 2*p)
			teams[i % 2].push_back(plr);
		else
			benches[i % 2].push_back(plr);
	}
	
	FOR(mv, m) {
/*		cout << "Before move #" << mv << ":" << endl;
		cout << "Team 1: " << teams[0] << ", on the bench: " << benches[0] << endl;
		cout << "Team 2: " << teams[1] << ", on the bench: " << benches[1] << endl;*/
		
		FOR(tm, 2) {
			vector<Player>& team = teams[tm];
			vector<Player>& bench = benches[tm];
			
			if (bench.empty()) continue;
			
			for (auto i = team.begin(); i != team.end(); ++i) i->minutesPlayed++;
			sort(team.begin(), team.end(), higherMinutesHigherDraft);
			sort(bench.begin(), bench.end(), lowerMinutesLowerDraft);
			
			Player out = team.back();
			team.pop_back();
			Player repl = bench.back();
			bench.pop_back();
			team.push_back(repl);
			bench.push_back(out);
		}
	}
	vector<string> finalPlayers;
	FOR(tm, 2) {
		REP(i, teams[tm]) {
			finalPlayers.push_back(teams[tm][i].name);
		}
	}
	sort(finalPlayers.begin(), finalPlayers.end());
	REP(i, finalPlayers) {
		if (i) printf(" ");
		printf("%s", finalPlayers[i].c_str());
	}
	printf("\n");
}

int main(void)
{
// 	freopen("/home/vesko/hackercup/b.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	FOR(tc, T) {
		printf("Case #%d: ", tc + 1);
		solve();
	}
	return 0;
}


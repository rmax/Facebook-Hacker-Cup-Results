#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Basketball_Player{
	string name;
	int index;
	int shot_percentage;
	int height;
	int minute;
	bool on_court;
	Basketball_Player(string name, int shot_percentage, int height) : name(name), shot_percentage(shot_percentage), height(height), minute(0), on_court(false), index(0) {};
	bool operator < (const Basketball_Player &p) const {
		if (shot_percentage != p.shot_percentage) {
			return shot_percentage > p.shot_percentage;
		}
		return height > p.height;
	}
};

bool compare(const Basketball_Player &p, const Basketball_Player &q) {
	if (p.minute != q.minute) {
		return p.minute < q.minute;
	}
	return p.index < q.index;
}

int find_leave(vector<Basketball_Player> &player) {
	int leave = -1;
	for (int i = 0; i < player.size(); i++) {
		if (player[i].on_court) {
			if (leave == -1 || compare(player[leave], player[i])) {
				leave = i;
			}
		}
	}
	return leave;
}

int find_in(vector<Basketball_Player> &player) {
	int in = -1;
	for (int i = 0; i < player.size(); i++) {
		if (!player[i].on_court) {
			if (in == -1 || compare(player[i], player[in])) {
				in = i;
			}
		}
	}
	return in;
}

void update(vector<Basketball_Player> &player, int leave, int in) {
	if (in != -1) {
		player[leave].on_court = false;
		player[in].on_court = true;
	}
	for (int i = 0; i < player.size(); i++) {
		if (player[i].on_court) {
			player[i].minute++;
		}
	}
}

int main() {
	freopen("basketball_game.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	cin >> T;
	for (int task = 1; task <= T; task++) {
		int n, m, p;
		scanf("%d %d %d\n", &n, &m, &p);
		vector<Basketball_Player> player;
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			int shot_percentage, height;
			scanf("%d %d\n", &shot_percentage, &height);
			player.push_back(Basketball_Player(name, shot_percentage, height));
		}
		sort(player.begin(), player.end());
		vector<Basketball_Player> first, second;
		for (int i = 0; i < n; i++) {
			player[i].index = i;
			if (i & 1) {
				second.push_back(player[i]);
			} else {
				first.push_back(player[i]);
			}
		}
		for (int i = 0; i < p; i++) {
			first[i].minute = second[i].minute = 1;
			first[i].on_court = second[i].on_court = true;
		}
		for (int minute = 1; minute <= m; minute++) {
			int first_leave = find_leave(first);
			int second_leave = find_leave(second);
			int first_in = find_in(first);
			int second_in = find_in(second);
			update(first, first_leave, first_in);
			update(second, second_leave, second_in);
		}
		vector<string> ans;
		for (int i = 0; i < first.size(); i++) {
			if (first[i].on_court) {
				ans.push_back(first[i].name);
			}
		}
		for (int i = 0; i < second.size(); i++) {
			if (second[i].on_court) {
				ans.push_back(second[i].name);
			}
		}
		sort(ans.begin(), ans.end());
		
		printf("Case #%d:", task);
		for (int i = 0; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
		cout << endl;
	}
	
	return 0;
}

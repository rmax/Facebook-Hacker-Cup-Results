#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Player {
	string name;
	int order, shot, height, played;
};
bool operator<(const Player& a, const Player& b) {
	return make_pair(a.shot, a.height) > make_pair(b.shot, b.height);
}

bool comp(Player* a, Player* b) {
	return make_pair(a->played, a->order) < make_pair(b->played, b->order);
}

void solve() {
	int N, M, P;
	cin >> N >> M >> P;
	vector<Player> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i].name >> p[i].shot >> p[i].height;
		p[i].played = 0;
	}
	sort(p.begin(), p.end());
	vector<Player*> notplaying[2];
	vector<Player*> playing[2];
	for (int i = 0; i < N; ++i) {
		p[i].order = i;
		if (i < 2*P)
			playing[i%2].push_back(&p[i]);
		else
			notplaying[i%2].push_back(&p[i]);
	}
	for (int i = 0; i < M; ++i) {
		for (int t = 0; t < 2; ++t) {
			vector<Player*>& npl = notplaying[t];
			vector<Player*>& pl = playing[t];
			for (int j = 0; j < P; ++j)
				++pl[j]->played;
			if (npl.empty()) continue;
			int out = max_element(pl.begin(), pl.end(), comp) - pl.begin();
			int in = min_element(npl.begin(), npl.end(), comp) - npl.begin();
			Player* pout = pl[out];
			Player* pin = npl[in];
			pl.erase(pl.begin() + out);
			npl.erase(npl.begin() + in);
			pl.push_back(pin);
			npl.push_back(pout);
		}
	}

	vector<string> names;
	for (int i = 0; i < P; ++i) {
		for (int t = 0; t < 2; ++t)
			names.push_back(playing[t][i]->name);
	}
	sort(names.begin(), names.end());
	for (int i = 0; i < 2*P; ++i)
		cout << ' ' << names[i];
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << (i+1) << ":";
		solve();
	}
}

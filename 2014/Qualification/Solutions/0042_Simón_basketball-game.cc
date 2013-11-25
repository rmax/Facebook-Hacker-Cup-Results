#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
using namespace std;
int T, N, P, M;
int TT;
struct player {
    int shot, height, play_time, add_time, draft;
    string nombre;

    bool operator<(const player& rhs) const {
	return shot > rhs.shot ||
		  (shot == rhs.shot && height > rhs.height);
    }
};

struct compplaying {
    bool operator()(const player& lhs, const player& rhs) const {
	// return true;
	return (lhs.play_time+(TT-lhs.add_time) < rhs.play_time + (TT-rhs.add_time)) ||
	    (lhs.play_time+(TT-lhs.add_time)== rhs.play_time + (TT-rhs.add_time) &&
	     lhs.draft < rhs.draft);
    }
};

struct compbench {
    bool operator()(const player& lhs, const player& rhs) const {
	return lhs.play_time > rhs.play_time ||
			       (lhs.play_time == rhs.play_time &&
				(lhs.draft > rhs.draft));
    }
};

player players[50];
typedef priority_queue<player, vector<player>, compplaying> pqueue;
typedef priority_queue<player, vector<player>, compbench> bqueue;
pqueue playing1, playing2;
bqueue bench1, bench2;


int main() {
    // scanf("%d\n", &T);
    cin >> T;
    for (int t=1; t<=T; t++) {
	cin >> N >> M >> P;
	while (!bench1.empty()) bench1.pop();
	while (!bench2.empty()) bench2.pop();

	// scanf("%d%d%d\n", &N, &M, &P);
	for (int i=0; i<N; i++) {
	    cin  >> players[i].nombre >> players[i].shot >> players[i].height;
	    players[i].play_time = 0;
	}
	sort(players, players+N);
	for (int i=0; i<N; i++)
	    players[i].draft = i;

	TT = 0;
	for (int i=0, j=0; i<N; i+= 2, j++) {
	    if (j < P) {
		players[i].add_time = 0;
		if (i+1 < N) {
		    players[i+1].add_time = 0;
		    playing2.push(players[i+1]);
		}
		playing1.push(players[i]);
	    } else {
		bench1.push(players[i]);
		if (i+1 < N)
		    bench2.push(players[i+1]);
	    }
	}
	for (TT = 1; TT<=M; TT++) {
	    if (!bench1.empty()) {
		player p1 = playing1.top();
		playing1.pop();
		p1.play_time += TT-p1.add_time;

		player p3 = bench1.top();
		bench1.pop();
		p3.add_time = TT;
		playing1.push(p3);
		bench1.push(p1);
	    }

	    if (!bench2.empty()) {
		player p2 = playing2.top();
		playing2.pop();
		p2.play_time += TT-p2.add_time;

		player p4 = bench2.top();
		bench2.pop();
		p4.add_time = TT;

		playing2.push(p4);
		bench2.push(p2);

	    }

	}
	vector<string> ans;

	while(!playing1.empty()) {
	    ans.push_back(playing1.top().nombre); playing1.pop();
	}

	while(!playing2.empty()) {
	    ans.push_back(playing2.top().nombre); playing2.pop();
	}
	sort(ans.begin(), ans.end());
	cout << "Case #" << t << ": ";
	for (int i=0; i<ans.size(); i++) {
	    cout << ans[i] << " ";
	}
	cout << endl;
    }
}

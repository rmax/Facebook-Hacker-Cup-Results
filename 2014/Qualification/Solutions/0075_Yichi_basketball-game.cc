#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Player {
public:
  int spct;
  int height;
  string name;
  int minutesplayed;
  bool playing;
  Player(int s, int h, string n) : spct(s), height(h), name(n), playing(false),
				   minutesplayed(0) {}
  bool operator<(const Player &other) const {
    if (spct < other.spct)
      return true;
    else if (spct > other.spct)
      return false;
    else if (height < other.height)
      return true;
    else
      return false;
  }
  bool operator>(const Player &other) const { // not really necessary
    return (other < *this);
  }
};

int main() {
  int T, N, M, P;
  vector<Player> players;
  vector<string> playingplayers;
  cin >> T;
  for (int k = 0; k < T; ++k) {
    cin >> N >> M >> P;
    string n;
    int s, h;
    for (int j = 0; j < N; ++j) {
      cin >> n >> s >> h;
      players.push_back(Player(s, h, n));
    }
    // Sort the players
    sort(players.begin(), players.end());
    // The way I've defined < makes it so that players[0] is the last draft
    // pick (i.e. N). I could sort it the other way (by giving the reverse
    // iterators) but this works fine
    cout << "Case #" << k+1 << ": ";
    // Check one trivial case (if 2*P == N everyone is playing)
    if (2 * P == N) {
      // Add all players
      for (int j = 0; j < N; ++j) {
        playingplayers.push_back(players[j].name);
      }
      sort(playingplayers.begin(), playingplayers.end());
      for (int j = 0; j < N; ++j) {
	cout << playingplayers[j] << ' ';
      }
    }
    else {
      // The starting players are players[N-1] through players[N-2*P]
      for (int j = N-2*P; j < N; ++j)
	players[j].playing = true;
      for (int t = 0; t < M; ++t) {
	int maxtimee = 0, maxtimeo = 0;
	int mintimee = 999, mintimeo = 999;
	int maxtidxe = -2, maxtidxo = -1;
	int mintidxe = N, mintidxo = N+1;
	// We're doing several things in this loop - increasing time for
	// playing players, and finding the players being replaced and
	// the replacing players
	
        for (int j = 0; j < N; ++j) {
	  if (j&1) {
	    // Check the odd player
	    if (players[j].playing) {
	      players[j].minutesplayed++;
	      if (players[j].minutesplayed > maxtimeo) {
		maxtimeo = players[j].minutesplayed;
		maxtidxo = j;
	      }
	    }
	    else {
	      if (players[j].minutesplayed <= mintimeo) { // yes, <=
		mintimeo = players[j].minutesplayed;
		mintidxo = j;
	      }
	    }
	  }
	  else {
	    // Check the even player
	    if (players[j].playing) {
	      players[j].minutesplayed++;
	      if (players[j].minutesplayed > maxtimee) {
		maxtimee = players[j].minutesplayed;
		maxtidxe = j;
	      }
	    }
	    else {
	      if (players[j].minutesplayed <= mintimee) { // yes, <=
		mintimee = players[j].minutesplayed;
		mintidxe = j;
	      }
	    }
	  }
	}
	// Do substitutions
	// sub out maxtidxe and maxtidxo, sub in mintidxe and mintidxo
	players[maxtidxe].playing = false;
	players[mintidxe].playing = true;
	players[maxtidxo].playing = false;
	players[mintidxo].playing = true;
      }
      for (int j = 0; j < N; ++j) {
	if (players[j].playing)
	  playingplayers.push_back(players[j].name);
      }
      sort(playingplayers.begin(), playingplayers.end());
      for (int j = 0; j < 2*P; ++j) {
	cout << playingplayers[j] << ' ';
      }
    }
    cout << endl;
    players.clear();
    playingplayers.clear();
  }
  return 0;
}

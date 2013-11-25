#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    int n, m, p; cin >> n >> m >> p;
    // shot percentage, height, name
    vector<pair<pair<int, int>, string> > players;
    for (int i = 0; i < n; ++i) {
      pair<pair<int, int>, string> player;
      cin >> player.second >> player.first.first >> player.first.second;
      players.push_back(player);
    }
    sort(players.begin(), players.end());
    reverse(players.begin(), players.end());

    set<int> even_players, even_reserve, odd_players, odd_reserve;
    for (int i = 0; i < 2*p; i += 2) {
      even_players.insert(i);
      odd_players.insert(i+1);
    }
    for (int i = 2*p; i < n; ++i) {
      if (i % 2 == 0) {
        even_reserve.insert(i);
      } else {
        odd_reserve.insert(i);
      }
    }

    vector<int> time_played(players.size());
    for (int i = 0; i < m; ++i) {
      // update time played
      for (set<int>::iterator it = even_players.begin();
           it != even_players.end(); ++it) {
        time_played[*it]++;
      }
      for (set<int>::iterator it = odd_players.begin();
           it != odd_players.end(); ++it) {
        time_played[*it]++;
      }
      // swap out players
      if (!even_reserve.empty()) {
        int to_remove = -1;
        for (set<int>::reverse_iterator it = even_players.rbegin();
             it != even_players.rend(); ++it) {
          if (to_remove == -1 || time_played[*it] > time_played[to_remove])
            to_remove = *it;
        }
        even_players.erase(to_remove);

        int to_add = -1;
        for (set<int>::iterator it = even_reserve.begin();
             it != even_reserve.end(); ++it) {
          if (to_add == -1 || time_played[*it] < time_played[to_add])
            to_add = *it;
        }
        even_players.erase(to_remove);
        even_reserve.insert(to_remove);
        even_reserve.erase(to_add);
        even_players.insert(to_add);
      }
      if (!odd_reserve.empty()) {
        int to_remove = -1;
        for (set<int>::reverse_iterator it = odd_players.rbegin();
             it != odd_players.rend(); ++it) {
          if (to_remove == -1 || time_played[*it] > time_played[to_remove])
            to_remove = *it;
        }
        odd_players.erase(to_remove);

        int to_add = -1;
        for (set<int>::iterator it = odd_reserve.begin();
             it != odd_reserve.end(); ++it) {
          if (to_add == -1 || time_played[*it] < time_played[to_add])
            to_add = *it;
        }
        odd_players.erase(to_remove);
        odd_reserve.insert(to_remove);
        odd_reserve.erase(to_add);
        odd_players.insert(to_add);
      }
    }

    vector<string> curr_players;
    for (set<int>::iterator it = even_players.begin();
         it != even_players.end(); ++it) {
      curr_players.push_back(players[*it].second);
    }
    for (set<int>::iterator it = odd_players.begin();
         it != odd_players.end(); ++it) {
      curr_players.push_back(players[*it].second);
    }
    sort(curr_players.begin(), curr_players.end());

    cout << "Case #" << test << ":";
    for (int i = 0; i < curr_players.size(); ++i) {
      cout << " " << curr_players[i];
    }
    cout << endl;
  }
  
  return 0;
}
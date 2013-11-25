#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

struct Player {
  string name;
  int shot;
  int h;
  int time;
  bool playing;

  bool operator> (const Player& other) const {
    if (shot != other.shot)
      return shot > other.shot;
    return h > other.h;
  }

  bool operator< (const Player& other) const {
    if (shot != other.shot)
      return shot < other.shot;
    return h < other.h;
  }
};

bool wait_cmp(const Player* a, const Player* b) {
  if (a->time != b->time) {
    return a->time < b->time;
  }
  return *a > *b;
}

bool field_cmp(const Player* a, const Player* b) {
  if (a->time != b->time) {
    return a->time > b->time;
  }
  return *a < *b;
}

int main(int argc, char* argv[]) {
  int T;
  cin >> T;

  for (auto t = 1; t <= T; ++ t) {
    int n, m, p;

    cin >> n >> m >> p;
    vector<Player> players(n);

    for (auto i = 0; i < n; ++ i) {
      cin >> players[i].name;
      cin >> players[i].shot;
      cin >> players[i].h;
      players[i].time = 0;
      players[i].playing = 0;
    }

    sort(players.begin(), players.end(), std::greater<Player>());

//    for (auto p : players) {
//      cout << p.name << ' ' << p.shot << ' ' << p.h << endl;
//    }

    for (auto i = 0; i < 2 * p; ++ i) {
      players[i].playing = 1;
    }

    if (2 * p < n) {
      while (m --) {
        Player* p1 = NULL;
        Player* p2 = NULL;
        Player* w1 = NULL;
        Player* w2 = NULL;
        for (auto i = 0; i < n; ++ i) {
          if (players[i].playing) {
            players[i].time ++;
            if (i % 2 == 0) {
              if (p1 == NULL || field_cmp(&players[i], p1)) {
                p1 = &players[i];
              }
            } else {
              if (p2 == NULL || field_cmp(&players[i], p2)) {
                p2 = &players[i];
              }
            }
          } else {
            if (i % 2 == 0) {
              if (w1 == NULL || wait_cmp(&players[i], w1)) {
                w1 = &players[i];
              }
            } else {
              if (w2 == NULL || wait_cmp(&players[i], w2)) {
                w2 = &players[i];
              }
            }
          }
        }
        assert(p1 != NULL);
        assert(p2 != NULL);
        assert(w1 != NULL);
        assert(w2 != NULL);
        p1->playing = false;
        p2->playing = false;
        w1->playing = true;
        w2->playing = true;
      }
    }
    vector<string> names;
    for (int i = 0; i < n; ++ i) {
      if (players[i].playing) {
        names.push_back(players[i].name);
      }
    }

    sort(names.begin(), names.end());

    cout << "Case #" << t << ":";
    for (auto s : names) {
      cout << ' ' << s;
    }
    cout << endl;
  }

  return 0;
}


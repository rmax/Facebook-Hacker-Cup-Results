//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
struct Player{
  string name;
  int shot_percentage;
  int height;
  int total_time;
  int draft_num;
  Player():name(), shot_percentage(0), height(0), total_time(0), draft_num(0){}
};

int T;

void simulate(vector<Player> players, int M, int P, vector<Player> &acc){
  //auto lessOnField = [&players](int i, int j){
    //const Player &pi = players[i];
    //const Player &pj = players[j];
    //if (pi.total_time != pj.total_time) return pi.total_time < pj.total_time;
    //return pi.draft_num < pj.draft_num;
  //}
  //auto lessOnBench = [&players](int i, int j){
    //const Player &pi = players[i];
    //const Player &pj = players[j];
    //if (pi.total_time != pj.total_time) return pi.total_time > pj.total_time;
    //return pi.draft_num > pj.draft_num;
  //}
  //priority_queue<int, vector<int>, decltype(lessOnField)> onField(lessOnField);
  //priority_queue<int, vector<int>, decltype(lessOnBench)> onBench(lessOnBench);
  vector<bool> isOnField(players.size());
  for (size_t i = 0; i < players.size(); i++){
    if ((int)i < P){
      isOnField[i] = true;
      //onField.push(i);
    }else{
      //onBench.push(i);
    }
  }

  while (M--){
    if (P == (int)players.size()) break;
    for (size_t i = 0; i < players.size(); i++){
      if (isOnField[i]) players[i].total_time++;
    }
    int out = -1;
    for (size_t i = 0; i < players.size(); i++){
      if (!isOnField[i])continue;
      if (out == -1) out = i;
      else{
        if (players[i].total_time > players[out].total_time ||
          (players[i].total_time == players[out].total_time &&
           players[i].draft_num > players[out].draft_num)){
          out = i;
        }
      }
    }
    int in = -1;
    for (size_t i = 0; i < players.size(); i++){
      if (isOnField[i])continue;
      if (in == -1) in = i;
      else{
        if (players[i].total_time < players[in].total_time ||
          (players[i].total_time == players[in].total_time &&
           players[i].draft_num < players[in].draft_num)){
          in = i;
        }
      }
    }
    isOnField[out] = false;
    isOnField[in] = true;
  }
  for (size_t i = 0; i < players.size(); i++){
    if (isOnField[i]) acc.push_back(players[i]);
  }
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  cin >> T;
  while (T--){
    int N, P, M;
    cin >> N >> M >> P;
    vector<Player> players(N);
    for (auto &p: players){
      cin >> p.name >> p.shot_percentage >> p.height;
    }
    sort(players.begin(), players.end(), 
      [](const Player &a, const Player &b){
        if (a.shot_percentage != b.shot_percentage) return a.shot_percentage > b.shot_percentage;
        return a.height > b.height;
        }
    );
    for (int i = 0; i < N; i++) players[i].draft_num = i + 1;
    vector<Player> team1, team2;  
    for (int i = 0; i < N; i++){
      if (i % 2 == 0) team1.push_back(players[i]);
      else team2.push_back(players[i]);
    }
    vector<Player> res;
    simulate(team1, M, P, res);
    simulate(team2, M, P, res);

    vector<string> names;
    for (auto &p: res) names.push_back(p.name);

    sort(names.begin(), names.end());
    cout << "Case #" << ++TestNum << ":";
    for (auto &s: names) cout << " " << s;
    cout << endl;
  }
}


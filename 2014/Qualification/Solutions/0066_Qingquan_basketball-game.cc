#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

typedef pair<pair<int,int>, int> pack;
vector<string> name;
// -shot, -height, id
vector<pack> rating;
// bench minutes, -draft, id
set<pack> play;
// -(bench minutes-current time), draft, id
set<pack> bench;

vector<string> ans;

int T, N, M, P;

int main() {
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> N >> M >> P;
        name.resize(N);
        rating.resize(N);
        REP(i, N) {
            int s, h;
            cin >> name[i] >> s >> h;
            rating[i] = make_pair(make_pair(-s, -h), i);
        }
        sort(rating.begin(), rating.end());
        ans.clear();
        for (int i = 0; i < 2; i++) {
            play.clear(), bench.clear();
            for (int j = i; j < N; j+=2) {
                if (play.size() < P) {
                    play.insert(make_pair(make_pair(0, -j), rating[j].second));
                } else {
                    bench.insert(make_pair(make_pair(0, j), rating[j].second));
                }
            }
            for (int t = 1; t <= M; t++) {
                if (!bench.empty()) {
                    pack off = *(play.begin());
                    play.erase(play.begin());
                    pack on = *(bench.begin());
                    bench.erase(bench.begin());
                    // on
                    on.first.first = -on.first.first+t;
                    on.first.second = -on.first.second;
                    play.insert(on);
                    // off
                    off.first.first = -(off.first.first-t);
                    off.first.second = -off.first.second;
                    bench.insert(off);
                }
            }
            for (set<pack>::iterator it = play.begin(), eit = play.end();
                    it != eit; ++it) {
                ans.push_back(name[it->second]);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case #" << cas << ":";
        REP(i, ans.size()) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}


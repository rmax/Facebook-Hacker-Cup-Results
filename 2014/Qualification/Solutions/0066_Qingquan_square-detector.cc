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

int T, N;
string M;

int main() {
    cin >> T;
    for(int cas = 1; cas <= T; ++cas) {
        cin >> N;
        pair<int,int> ul = make_pair(N, N), lu = make_pair(N, N);
        pair<int,int> br = make_pair(-1, -1), rb = make_pair(-1, -1);
        int cnt = 0;
        REP(i, N) {
            cin >> M;
            REP(j, N) {
                if (M[j] == '#') {
                    ul = min(ul, make_pair(i,j));
                    lu = min(lu, make_pair(j,i));
                    br = max(br, make_pair(i,j));
                    rb = max(rb, make_pair(j,i));
                    cnt++;
                }
            }
        }
        swap(lu.first, lu.second);
        swap(rb.first, rb.second);
        bool ans = (ul == lu && br == rb)
            && (br.first-ul.first == br.second-ul.second)
            && (cnt == (br.first-ul.first+1)*(br.second-ul.second+1));
        cout << "Case #" << cas << ": " << (ans ? "YES" : "NO") << endl;
    }
	return 0;
}


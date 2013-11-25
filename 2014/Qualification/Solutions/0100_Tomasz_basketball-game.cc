
#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef vector<int> VI;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

struct player {
    string name;
    int shot;
    int height;

    player(string _name, int _shot, int _height): name(_name), shot(_shot), height(_height) {}

    bool operator < (player const &p) const {
        return (shot > p.shot || (shot == p.shot && height > p.height));
    }
};
vector<string> simulate(vector<player> P, int m, int p) {
    reverse(P.begin(), P.begin()+p);
    int n = SZ(P);
    vector<string> res;
    REP(i,p) {
        res.PB(P[(m+i)%n].name);
    }
    return res;
}
void solve(int tc) {
    cout << "Case #" << tc << ":";
    int n,m,p;
    cin >> n >> m >> p;
    vector<player> P;
    REP(i, n) {
        string s;
        int sh,h;
        cin >> s >> sh >> h;
        P.PB(player(s,sh,h));
    }
    sort(ALL(P));
    vector<player> A,B;
    REP(i, n) {
        if (i&1) A.PB(P[i]);
        else B.PB(P[i]);
    }
    vector<string> rA, rB;
    rA = simulate(A,m,p);
    rB = simulate(B,m,p);
    rA.insert(rA.end(), ALL(rB));
    sort(ALL(rA));
    FORE(it, rA) cout << " " << *it;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int t;
    cin >> t;
    REP(i,t) solve(i+1);
    
    return 0;
}


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
const int MX = 100;
const int RG = 1000;
LD tab[MX][MX][RG+1];

int read() {
    double a;
    cin >> a;
    a *= RG;
    return (int) round(a);
}

void solve(int tc) {
    cout << "Case #" << tc << ": ";
    int k;
    cin >> k;
    LD ps,pr,pw,pl;
    int pi,pu,pd;
    cin >> ps >> pr;
    pi = read();
    pu = read();
    cin >> pw;
    pd = read();
    cin >> pl;
    REP(w, k+1) REP(l,k+1) REP(p, RG+1) {
        if (w == 0) tab[w][l][p] = 1;
        else if (l == 0) tab[w][l][p] = 0;
        else {
            LD pwin = (p*ps+(RG-p)*pr)/RG;
            tab[w][l][p] = pwin*(pw*tab[w-1][l][min(RG, p+pu)] + (1-pw)*tab[w-1][l][p]) + (1-pwin)*(pl*tab[w][l-1][max(0, p-pd)] + (1-pl)*tab[w][l-1][p]);
        }
    }
    cout << tab[k][k][pi] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    REP(i,t) solve(i+1);

    return 0;
}


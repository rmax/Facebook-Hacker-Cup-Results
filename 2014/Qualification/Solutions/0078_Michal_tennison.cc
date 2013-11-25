#include <iostream>
#include <tuple>
#include <map>
using namespace std;

struct state { int setsa, setsb, sunnypp; state(int a, int b, int p) : setsa(a), setsb(b), sunnypp(p) {} };
bool operator< (const state &A, const state &B) { return make_tuple(A.setsa,A.setsb,A.sunnypp) < make_tuple(B.setsa,B.setsb,B.sunnypp); }

int read_double() { double x; cin >> x; return int(1000*x+0.5); }
int clip(int x) { return x<0 ? 0 : x>1000 ? 1000 : x; }

map<state,double> memo;
double ps, pr, pw, pl;
int pi, pu, pd;

double solve(const state &curr) {
    if (curr.setsa == 0) return 1.;
    if (curr.setsb == 0) return 0.;
    if (!memo.count(curr)) {
        state next1 ( curr.setsa-1, curr.setsb, curr.sunnypp );
        state next2 ( curr.setsa-1, curr.setsb, clip(curr.sunnypp+pu) );
        state next3 ( curr.setsa, curr.setsb-1, curr.sunnypp );
        state next4 ( curr.setsa, curr.setsb-1, clip(curr.sunnypp-pd) );
        
        double wins = ( curr.sunnypp * ps + (1000-curr.sunnypp) * pr ) * 1e-3;
        
        memo[curr] = 0.;
        memo[curr] += wins * (1-pw) * solve(next1);
        memo[curr] += wins * pw * solve(next2);
        memo[curr] += (1-wins) * (1-pl) * solve(next3);
        memo[curr] += (1-wins) * pl * solve(next4);
    }
    return memo[curr];
}

int main() {
    int T; cin >> T;
    for (int t=1; t<=T; ++t) {
        int K; cin >> K;
        cin >> ps >> pr;
        pi = read_double();
        pu = read_double();
        cin >> pw;
        pd = read_double();
        cin >> pl;
        memo.clear();
        printf("Case #%d: %.6f\n",t,solve(state(K,K,pi)));
    }
}

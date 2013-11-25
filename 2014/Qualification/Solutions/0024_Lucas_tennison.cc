#include <bits/stdc++.h>
#define Fr(i,a,b) for(int i = (a); i < (b); ++i)
#define Rp(i,n) Fr(i,0,n)
#define all(c) (c).begin(), (c).end()
#define pb push_back

using namespace std;

double p_s, p_r, p_w, p_l;
int p_u, p_d, K;

double memo[111][111][1010];

double solve(int k, int nk, int pint) {
    if(pint < 0) pint = 0;
    if(pint > 1000) pint = 1000;
    if(k == K) return 1;
    if(nk == K) return 0;
    //cout << k << " " << pint << endl;
    if(memo[k][nk][pint] > -1.0) return memo[k][nk][pint];
    double p = ((double)pint)/1000.0;
   
    double ret = p*p_s*( p_w*solve(k+1,nk, pint + p_u) + (1.0-p_w) * solve(k+1, nk, pint) ); //ganha sol
    
    ret += (1-p)*p_r*( p_w*solve(k+1, nk, pint + p_u) + (1.0-p_w) * solve(k+1, nk, pint) ); //ganha chuva
    
     ret += p*(1-p_s)*( p_l*solve(k, nk+1, pint - p_d) + (1.0-p_l) * solve(k, nk+1, pint) ); //perde sol
     
     ret += (1-p)*(1-p_r)*( p_l*solve(k, nk+1, pint - p_d) + (1.0-p_l) * solve(k, nk+1, pint) ); //perde sol
    
    //printf("memo[%d][%d] = %.3lf\n", k, pint, ret);
    return memo[k][nk][pint] = ret;
}

int main() {
    int tc; cin >> tc; ++tc;
    Fr(_,1,tc) {
        double pu,pd,pi;
        cin >> K >> p_s >> p_r >> pi >> pu >> p_w >> pd >> p_l;
        int p_i = round(pi*1000.0);
        p_u = round(pu*1000.0);
        p_d = round(pd*1000.0);
        Rp(i,K) Rp(bla,K) Rp(j,1001) memo[i][bla][j] = -2.0;
        printf("Case #%d: %.6lf\n", _, solve(0,0,p_i));
    }
    return 0;
}

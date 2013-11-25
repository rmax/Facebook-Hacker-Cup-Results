#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<map>
using namespace std;

int T;
int K;
double ps,pr,pi,pu,pw,pd,pl;
map<pair<int, pair<int, int> >, double> memo;
// double memo[101][101][1000010];


double dp(int w, int l, int sunProb) {
    if (l == K) return 0.0;
    if (w == K) return 1.0;
    if (memo.count(make_pair(w, make_pair(l, sunProb)))) return memo[make_pair(w, make_pair(l, sunProb))];
    // printf("(%d, %d, %d)\n", w, l, sunProb);
    // visit[w][l][sunProb] = true;
    double sp = (sunProb+0.0)/1000000.0;
    double& prob = memo[make_pair(w, make_pair(l, sunProb))]; //[w][l][sunProb];
    prob = 0;
    int ppu = (int)(pu*1000000);
    int ppd = (int)(pd*1000000);
    int newProb1 = min(ppu+sunProb, 1000000);
    int newProb2 = max(-ppd+sunProb, 0);
    double pg = (pw*dp(w+1, l, newProb1) + (1-pw)*dp(w+1, l, sunProb));
    double pp = (pl*dp(w, l+1, newProb2) + (1-pl)*dp(w, l+1, sunProb));
    double gs = ps*pg;
    double ls = (1-ps)*pp;
    double gr = pr*pg;
    double lr = (1-pr)*pp;
    prob = sp*(gs+ls) + (1-sp)*(gr+lr);
    return prob;
}

int main() {
    scanf("%d", &T);
    for (int t=1; t<=T; t++) {
	scanf("%d", &K);
	scanf("%lf%lf%lf%lf%lf%lf%lf", &ps, &pr, &pi, &pu,&pw,&pd,&pl);
	memo.clear();
	printf("Case #%d: %.6lf\n", t, dp(0, 0, (int)(pi*1000000)));
    }
    return 0;
}

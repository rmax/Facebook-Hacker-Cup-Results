#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct el {
	int x, y;
	double prob;
	
	bool operator < (const el &b) const {
		if (x != b.x) return x < b.x;
		if (y != b.y) return y < b.y;
		if (fabs(prob - b.prob) < 1e-9) return 0;
		return prob < b.prob;
	};
};

int k;
double ps, pr, pi, pu, pw, pd, pl;

map < el , double > mp;

double go(int x, int y, double p) {
	if (p > 1) p = 1;
	if (p < 0) p = 0;
	
	if (x >= k) return 1;
	if (y >= k) return 0;
	
	el t;
	t.x = x; t.y = y; t.prob = p;
	
	if (mp.find(t) != mp.end()) return mp[t];
	double ans = 0;
	
	//sunny, win, inc
	ans += go(x + 1, y, p + pu) * p * ps * pw;
	//sunny, win
	ans += go(x + 1, y, p) * p * ps * (1 - pw);
	//sunny, lose, dec
	ans += go(x, y + 1, p - pd) * p * (1 - ps) * pl;
	//sunny, lose
	ans += go(x, y + 1, p) * p * (1 - ps) * (1 - pl);
	
//	printf ("%lf\n", ans);
	
	ans += go(x + 1, y, p + pu) * (1 - p) * pr * pw;
	ans += go(x + 1, y, p) * (1 - p) * pr * (1 - pw);
	ans += go(x, y + 1, p - pd) * (1 - p) * (1 - pr) * pl;
	ans += go(x, y + 1, p) * (1 - p) * (1 - pr) * (1 - pl);
	
	return mp[t] = ans;
}

int main() {
	int q, cases;
	
	scanf("%d", &cases);
	for (q = 1; q <= cases; q++) {
		scanf("%d%lf%lf%lf%lf%lf%lf%lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
		mp.clear();
		
	//	printf ("%lf %lf %lf\n", pi , ps , pw);
		
		//round pls
		double ans = go(0,0, pi);
		/*
		ans = ans * 1000000;
		
		ans = (int)(ans + 0.5 + 1e-9);
		ans /= 1000000;
		 */
		printf ("%.10lf\n", ans);
		printf ("Case #%d: %.6lf\n", q, ans);
	}
	
	return 0;
}
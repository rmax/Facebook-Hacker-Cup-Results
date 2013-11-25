#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double dps, dpr, dpi, dpu, dpw, dpd, dpl;
int ps, pr, pu, pw, pd, pl;

vector<vector<vector<double> > > mem;
double f(int left, int otherleft, int now) {
	double& ret = mem[left][otherleft][now];
	if (ret >= 0)
		return ret;
	if (left == 0) return 1;
	if (otherleft == 0) return 0;
	double win = dpw * f(left-1, otherleft, min(now + pu, 1000)) + (1 - dpw) * f(left-1, otherleft, now);
	double lose = dpl * f(left, otherleft-1, max(now - pd, 0)) + (1 - dpl) * f(left, otherleft-1, now);
	return ret = (now / 1000.0) * (dps * win + (1-dps) * lose) + ((1000-now) / 1000.0) * (dpr * win + (1-dpr) * lose);
}

double solve() {
	int K;
	cin >> K >> dps >> dpr >> dpi >> dpu >> dpw >> dpd >> dpl;
	int pi;
	ps = (int)(dps * 1000 + 0.5), pr = (int)(dpr * 1000 + 0.5), pi = (int)(dpi * 1000 + 0.5), pu = (int)(dpu * 1000 + 0.5), pw = (int)(dpw * 1000 + 0.5), pd = (int)(dpd * 1000 + 0.5), pl = (int)(dpl * 1000 + 0.5);
	mem.assign(K+1, vector<vector<double> >(K+1, vector<double>(1001, -1.0)));
	return f(K, K, pi);
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << (i+1) << ": " << fixed << setprecision(6) << solve() << endl;
	}
}

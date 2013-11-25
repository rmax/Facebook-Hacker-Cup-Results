#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
using namespace std;
double read_double()
{
	double d;
	cin >> d;
	return d;
}
int read_thousandth()
{
	double d = read_double();
	int ret = (int)round(d * 1000.0);
	assert(fabs(ret * 1e-3 - d) < 1e-9);
	return ret;
}
inline int fix(int p) { return max(min(p, 1000), 0); }
double mem[128][128][1024];
#define ASSERT_PROB(p) assert((p) >= 0.0 && p <= 1.0);
double solve(int k, int won, int lost, double p_s, double p_r, int p_i, int p_u,
	double p_w, int p_d, double p_l)
{
	if (won >= k)
		return 1.0;
	if (lost >= k)
		return 0.0;
	double &ret = mem[won][lost][p_i];
	if (!std::isnan(ret))
		return ret;
	double p_sunny = p_i * 1e-3;
	double p_win_set = p_sunny * p_s + (1.0 - p_sunny) * p_r;
#define _(dw, dl, ds) solve(k, won + (dw), lost + (dl), p_s, p_r, fix(p_i + (ds)), p_u, p_w, p_d, p_l)
    return ret =
        p_win_set
          * (
                        p_w * _(1, 0, p_u)
              + (1.0 - p_w) * _(1, 0, 0)   
            )
        + (1.0 - p_win_set)
          * (
                        p_l * _(0, 1, -p_d)
              + (1.0 - p_l) * _(0, 1, 0)   
            );
#undef _
}
int main()
{
	int n_cases;
	cin >> n_cases;
	for (int t = 0; t < n_cases; t++)
	{
		memset(mem, -1, sizeof mem);
		int k;
		cin >> k;
		double p_s = read_double();
		double p_r = read_double();
		int p_i = read_thousandth();
		int p_u = read_thousandth();
		double p_w = read_double();
		int p_d = read_thousandth();
		double p_l = read_double();
		double p_win = solve(k, 0, 0, p_s, p_r, p_i, p_u, p_w, p_d, p_l);
		printf("Case #%d: %.6lf\n", t + 1, p_win);
	}
	return 0;
}

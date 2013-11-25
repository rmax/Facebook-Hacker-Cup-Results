#include <cstdio>
#include <cstring>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define foreach(it,v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)
typedef long long ll;
typedef pair <int, int> PII;

int Tc;
int m;
double psun, prain, pinitsun, dsun, pdsun, drain, pdrain;
double f[205][105][3][105][105];

int main() {
//	freopen("C.in", "r", stdin);
//	cout << sizeof(f) << endl;
	scanf("%d", &Tc);
	rep (ri, Tc) {
		printf("Case #%d: ", ri + 1);
		cin >> m >> psun >> prain >> pinitsun >> dsun >> pdsun >> drain >> pdrain;
		memset(f, 0, sizeof(f));
		f[0][0][2][0][0] = 1.0;
		double ans = 0;
		rep (i, 2 * m) {
			rep (j, min(i + 1, m + 1)) {
				if (i - j >= m) continue;
				rep (o, 3) {
					double init = (o == 2 ? pinitsun : (o == 1 ? 1.0 : 0.0));
					double curs = 0;
					rep (s, j + 1) {
						double curr = 0;
						rep (r, i - j + 1) {
							if (f[i][j][o][s][r]) {
								double &cur = f[i][j][o][s][r];
								if (j == m) {
									ans += f[i][j][o][s][r];
									continue;  
								}
								double p = init + curs - curr;
								assert(0 <= p && p <= 1);
								double &t0 = f[i + 1][j + 1][o][s][r];
								double &t1 = f[i + 1][j][o][s][r];
								double &t2 = p + dsun >= 1 ? f[i + 1][j + 1][1][0][0] : f[i + 1][j + 1][o][s + 1][r];
								double &t3 = p - drain <= 0 ? f[i + 1][j][0][0][0] : f[i + 1][j][o][s][r + 1];
								double pwin = p * psun + (1 - p) * prain;
								{ // win
									t0 += cur * pwin * (1 - pdsun);
									t2 += cur * pwin * pdsun;
								//	cout << "t0 = " << t0 << ", t2 = " << t1 << endl; 
								}
								{ // lose
									t1 += cur * (1 - pwin) * (1 - pdrain);
									t3 += cur * (1 - pwin) * pdrain;
								}
							}
							curr += drain;
						}
						curs += dsun;
					}
				}
			}
		}
		printf("%.6f\n", ans);
	}
}

#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>	// srand( time(NULL) )
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>

using namespace std;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) for(int i = 0; i < a; ++i)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define sz(A) int((A).size())
#define CLR(x, a) memset(x, a, sizeof(x))
#define pb push_back
#define mp make_pair

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}

long double ps, pr, pi, pu, pw, pd, pl;
int T, K;

long double mat[2][101][101][101][3];

long double do_it (){

	FORR (i, K){
		FORR (j, K+1){
			FORR (l, K+1){
				FORR (u, 3) mat[K&1][i][j][l][u] = 1.;
			}
		}
	}
	FORR (j, K+1){
		FORR (l, K+1) {
			FORR (u, 3) mat[0][K][j][l][u] = mat[1][K][j][l][u] = 0.;
		}
	}

	FORE (wn, K-1, 0){
		FORE (lo, K-1, 0){
			FORE (up, wn, 0){
				FORE (dn, lo, 0){
					FORR (u, 3){
						long double prob = up * pu - dn * pd;
					
						if (u==0){
							prob += pi;
						} else if (u==1){
							prob += 1.;
						}

						long double vic = prob * ps + (1. - prob) * pr;
						long double los = prob * (1. - ps) + (1. - prob) * (1. - pr);

						long double c1 = (1.-pw)*mat[(wn+1)&1][lo][up][dn][u];
						long double c2 = pw;
						if (prob+pu>1.){
							c2 *= mat[(wn+1)&1][lo][0][0][1];
						} else {
							c2 *= mat[(wn+1)&1][lo][up+1][dn][u];
						}
				
						long double c3 = (1.-pl)*mat[wn&1][lo+1][up][dn][u];
						long double c4 = pl;
						if (prob-pd<0.){
							c4 *= mat[wn&1][lo+1][0][0][2];
						} else {
							c4 *= mat[wn&1][lo+1][up][dn+1][u];
						}

						long double res = vic * (c1 + c2) + los * (c3 + c4);

						mat[wn&1][lo][up][dn][u] = res;
					}
				}
			}
		}
	}
	
	return mat[0][0][0][0][0];	

}

int main (){	
	cin >> T;
	FORR (c, T){
		cin >> K >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
		printf ("Case #%d: %.6Lf\n", c+1, do_it()); 
	}
}

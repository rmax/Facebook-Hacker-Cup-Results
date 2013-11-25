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

char mat[50][50];

int main (){
	int T, N;
	cin >> T;
	FORR (c, T){
		cin >> N;
		FORR (i, N){
			FORR (j, N){
				cin >> mat[i][j];
			}
		}

		int leftX = N, rightX = 0; 
		int leftY = N, rightY = 0;
		FORR (i, N){
			FORR (j, N){
				if (mat[i][j]=='#'){
					leftX = min (leftX, i);
					leftY = min (leftY, j);
					rightX = max (rightX, i);
					rightY = max (rightY, j);
				}
			}
		}
		bool ans = (rightX-leftX)==(rightY-leftY);
		FOR (i, leftX, rightX+1){
			FOR (j, leftY, rightY+1){
				if (mat[i][j]!='#') { ans = false; break; }
			}
		}
		if (ans){
			cout << "Case #"<< (c+1) << ": " << "YES" << endl;
		} else {
			cout << "Case #"<< (c+1) << ": " << "NO" << endl;
		}
	}
}

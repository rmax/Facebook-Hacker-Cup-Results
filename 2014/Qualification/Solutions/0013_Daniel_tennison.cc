#include <bits/stdc++.h>
#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,0,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define N 1
using namespace std;
template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

int pu,pd;
double p1,p2;
int k;
double ps, pr;
void leer(int &entero) {
	int a,b;
	scanf("%d.%d", &a, &b);
	entero = a*1000+b;
}
double memo[101][101][1001];
double g(int A, int B, int SUN) {
	double &res = memo[A][B][SUN];
	if (res != -1) return res;
	if (A == k) return 1;
	if (B == k) return 0;
	double sun = SUN/1000.0;
	double win = ps*sun + pr*(1-sun);
	return res = win*(g(A+1,B,min(1000,SUN+pu)) * p1
			+ g(A+1,B,SUN) * (1-p1)) + 
		(1-win) * (g(A,B+1,max(0,SUN-pd)) * p2 
				+ g(A,B+1,SUN) * (1-p2));
}
int tc,caso;

int main(){
	cin >> tc;
	while(tc--) {
		cin >> k;
		cin >> ps >> pr;
		int SUN;
		leer(SUN);
		leer(pu); cin >> p1;
		leer(pd); cin >> p2;
		f(i,0,101) f(j,0,101) f(k,0,1001) memo[i][j][k] = -1;
		double res = g(0,0,SUN);
		printf("Case #%d: %.6f\n", ++caso, res);
	}
}



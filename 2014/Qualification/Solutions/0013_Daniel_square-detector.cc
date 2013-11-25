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

int tc;
int caso;
string a[20];

int main(){
	cin >> tc;
	while(tc--) {
		int n;
		cin >> n;
		f(i,0,n) cin >> a[i];
		int a1,a2,b1,b2;
		f(i,0,n) f(j,0,n) {
			if (a[i][j] == '#') {
				a1 = i; b1 = j;
				i = j = oo;
			}
		}
		fd(i,n-1,0) fd(j,n-1,0) {
			if (a[i][j] == '#') {
				a2 = i; b2 = j;
				i = j = -oo;
			}
		}

		bool ok;
		if (a2-a1 == b2-b1) {
			int k = a2-a1+1;
			bool ok1,ok2;
			int num = 0;
			f(i,0,n) f(j,0,n) if (a[i][j] == '#') num++;
			ok1 = num == k*k;
			ok2 = 1;
			f(i,a1,a2+1) f(j,b1,b2+1) if (a[i][j]!='#')
				ok2 = 0;
			if (ok1 && ok2) ok = 1;
			else ok = 0;
		} else ok = 0;
		printf("Case #%d: %s\n", ++caso, ok?"YES" : "NO");
	}
}



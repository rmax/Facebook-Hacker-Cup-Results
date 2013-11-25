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

void simular(int n, int m, int p, int r[]) {
	f(i,0,n) r[i] = i;
	vint jugaron(n, 0);
	f(i,0,p) jugaron[i]++;
	while(m--) {
		int sale; int mx = oo;
		fd(i,p-1,0) {
			if (i == p-1 || jugaron[r[i]] >= mx) {
				if (mx == jugaron[r[i]]) {
					if (r[i] > r[sale]) sale = i;
					continue;
				}
				mx = jugaron[r[i]];
				sale = i;
			}
		}
		int entra, mn = oo;
		f(i,p,n) {
			if (i == p || jugaron[r[i]] <= mn) {
				if (mn == jugaron[r[i]]) {
					if (r[i] < r[entra]) entra = i;
					continue;
				}
				mn = jugaron[r[i]];
				entra = i;
			}
		}
		if (p < n) swap(r[entra], r[sale]);
		f(i,0,p) jugaron[r[i]]++;
	}
}
int tc, caso;
int n,m,p;

int main(){
	cin >> tc;
	while(tc--) {
		cin >> n >> m >> p;
		string s; int shot, height;
		vector< pair<int,string> > players(n);
		f(i,0,n) {
			cin >> s >> shot >> height;
			players[i] = pair<int, string>(shot*300 + height, s);
		}
		sort(rall(players));
//		f(i,0,n) cout << players[i].second << " "; cout << endl;
		int n2 = n/2, n1 = n - n2;
		int r1[n1], r2[n2];
		simular(n1, m, p, r1);
		simular(n2, m, p, r2);
		vector<string> res;
		f(i,0,p) {
			res.pb( players[r1[i]*2].second );
			res.pb( players[r2[i]*2+1].second );
		}
		sort(all(res));
		printf("Case #%d: ", ++caso);
		f(i,0,p*2) cout << res[i] << char(i+1==p*2? 10 : 32);
	}
}



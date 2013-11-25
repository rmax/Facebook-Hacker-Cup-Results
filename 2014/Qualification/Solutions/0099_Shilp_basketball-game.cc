#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> ip;
typedef pair<ip,string> pl;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(A) A.begin(), A.end()
#define fi first.first
#define se first.second
#define th second
#define sz size()
#define pb push_back

int main() {
	int T;
	cin >> T;
	int cn = 1;
	while(T--) {
		int N, M, P;
		cin >> N >> M >> P;
		deque<pl> A(N);
		FOR(i,0,N) cin >> A[i].th >> A[i].fi >> A[i].se;
		sort(ALL(A));
		reverse(ALL(A));
		deque<pl> T1, T2;
		deque<pl> T1a, T2a;
		FOR(i,0,2*P)
			if (i%2) T1a.pb(pl(ip(0,i),A[i].th));
			else T2a.pb(pl(ip(0,i),A[i].th));
		FOR(i,2*P,N)
			if (i%2) T1.pb(pl(ip(0,i),A[i].th));
			else T2.pb(pl(ip(0,i),A[i].th));
		FOR(it,0,M) {
			FOR(i,0,P) T1a[i].fi++;
			FOR(i,0,P) T2a[i].fi++;
			sort(ALL(T1a));
			sort(ALL(T2a));
			sort(ALL(T1));
			sort(ALL(T2));
			T1.pb(T1a.back()); T1a.pop_back();
			T1a.pb(T1.front()); T1.pop_front();
			T2.pb(T2a.back()); T2a.pop_back();
			T2a.pb(T2.front()); T2.pop_front();
		}
		deque<string> R;
		FOR(i,0,P) { R.pb(T1a[i].th); R.pb(T2a[i].th); }
		sort(ALL(R));
		cout << "Case #" << cn << ":";
		FOR(i,0,2*P) cout << " " << R[i];
		cout << endl;
		cn++;
	}
	return 0;
}

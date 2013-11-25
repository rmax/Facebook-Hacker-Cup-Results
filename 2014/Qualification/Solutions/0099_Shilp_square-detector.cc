#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

int main() {
	int T;
	cin >> T;
	int cn = 1;
	while(T--) {
		int N;
		cin >> N;
		vector<string> A(N);
		FOR(i,0,N) cin >> A[i];
		bool res = false;
		FOR(i,0,N) FOR(j,0,N) FOR(k,0,20) {
			bool f = true;
			FOR(p,0,N) FOR(q,0,N) {
				bool shouldB = (A[p][q] == '#');
				bool isB = (p >= i && p <= i+k && q >= j && q <= j+k);
				if ((shouldB && !isB) || (!shouldB && isB)) {
					f = false;
					goto F_RESOLVED;
				}
			}
			F_RESOLVED: if (f) {
				res = true;
				goto RES_RESOLVED;
			}
		}
		RES_RESOLVED: cout << "Case #" << cn << ": " << (res ? "YES" : "NO") << endl;
		cn++;
	}
	return 0;
}

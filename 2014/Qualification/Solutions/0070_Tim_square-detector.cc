#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
	int n;
	cin >> n;
	cin.get();
	vector<string> ss(n);
	for (int i = 0; i < n; i++) {
	    cin >> ss[i];
	}
	int sum = 0;
	int mxi = -1, mii = 999, mxj = -1, mij = 999;
#define update(f, a, b) a = f(a, b)
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		if (ss[i][j] == '#') {
		    sum++;
		    update(max, mxi, i);
		    update(max, mxj, j);
		    update(min, mii, i);
		    update(min, mij, j);
		}
	    }
	}
	cout << "Case #" << ca << ": ";
	int l = mxi - mii + 1, r = mxj - mij + 1;
	if (sum == 0 || (l == r && l * r == sum)) {
	    cout << "YES\n";
	} else {
	    cout << "NO\n";
	}
    }
    return 0;
}

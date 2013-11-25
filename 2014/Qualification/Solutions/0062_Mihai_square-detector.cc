#include <iostream>

using namespace std;

int t, n, nrBlack, minl, maxl, minc, maxc;
char h[20][20];

void solveTest(int testNr) {
    int dl, dc;
    cin >> n;
    nrBlack = 0;
    minl = minc = n;
    maxl = maxc = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
            if (h[i][j] == '#') {
                ++nrBlack;
                if (i < minl) minl = i;
                if (i > maxl) maxl = i;
                if (j < minc) minc = j;
                if (j > maxc) maxc = j;
            }
        }
    dl = maxl - minl + 1;
    dc = maxc - minc + 1;
    cout << "Case #" << testNr << ": ";
    if (maxl == -1) cout << "YES";
    else if ((dl == dc) && (nrBlack == dl * dc)) cout << "YES";
    else cout << "NO";
    cout << endl;
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solveTest(i);
    return 0;
}

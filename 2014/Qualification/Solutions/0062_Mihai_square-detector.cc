#include <fstream>

using namespace std;

ifstream fi("fb1.in");
ofstream fo("fb1.out");
int t, n, nrBlack, minl, maxl, minc, maxc;
char h[20][20];

void solveTest(int testNr) {
    int dl, dc;
    fi >> n;
    nrBlack = 0;
    minl = minc = n;
    maxl = maxc = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            fi >> h[i][j];
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
    fo << "Case #" << testNr << ": ";
    if (maxl == -1) fo << "YES";
    else if ((dl == dc) && (nrBlack == dl * dc)) fo << "YES";
    else fo << "NO";
    fo << endl;
}

int main() {
    fi >> t;
    for (int i = 1; i <= t; i++) solveTest(i);
    return 0;
}

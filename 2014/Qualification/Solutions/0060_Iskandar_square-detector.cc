#include<iostream>

using namespace std;

int main() {
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        char map[20][20];
        int left = 21, top = 21, bottom = -1, right = -1;
        bool isValid = false;
        cin >> N;
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                cin >> map[j][k];
                if (map[j][k] == '#') {
                    isValid = true;
                    if (j < top) top = j;
                    if (j > bottom) bottom = j;
                    if (k < left) left = k;
                    if (k > right) right = k;
                }
            }

        for (int j = top; j <= bottom; j++)
            for (int k = left; k <= right; k++) {
                if (map[j][k] != '#') {
                    isValid = false;
                    break;
                }
                if (!isValid) break;
            }

        if (right - left != bottom - top) isValid = false;

        cout << "Case #" << (i+1) << ": ";
        if (isValid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

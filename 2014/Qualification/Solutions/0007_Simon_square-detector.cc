#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve() {
	int N;
	cin >> N;
	cin.ignore(1000, '\n');
	vector<string> board(N);
	for (int i = 0; i < N; ++i)
		getline(cin, board[i]);
	int minx = 1 << 29, miny = 1 << 30, maxx = 0, maxy = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] == '#') {
				minx = min(minx, j);
				miny = min(miny, i);
				maxx = max(maxx, j);
				maxy = max(maxy, i);
			}
		}
	}
	if (maxx - minx != maxy - miny)
		return false;
	for (int i = miny; i <= maxy; ++i) {
		for (int j = minx; j <= maxx; ++j) {
			if (board[i][j] != '#')
				return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
		cout << "Case #" << (i+1) << ": " << (solve() ? "YES" : "NO") << endl;
}

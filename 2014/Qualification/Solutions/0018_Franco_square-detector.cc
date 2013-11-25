#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()

struct pto {
	int x, y;
	pto(int xx, int yy) { x=xx;y=yy;}
	pto(){}
};

bool board[32][32];
int value[32][32];
int n;

int squareSum(pto a, pto b) {
	pto left = pto(min(a.x, b.x), min(a.y, b.y)), right = pto(max(a.x, b.x), max(a.y, b.y));
	return value[right.x][right.y] - (left.y == 0 ? 0 : value[right.x][left.y - 1]) - (left.x == 0 ? 0 : value[left.x-1][right.y]) + (left.x == 0 || left.y == 0 ? 0 : value[left.x - 1][left.y - 1]);
}

bool works() {
	forn(i,n) forn(j,n) forn(k,n) forn(l,n) if(board[i][j] && board[k][l]) {
		if (squareSum(pto(i,j), pto(k,l)) != ((abs(k - i) + 1) * (abs(l - j) + 1))) {
			//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
			return false;
		}
	}
	return true;
}

int main() {
	int casos; cin >> casos;
	forn(caso, casos) {
		cout << "Case #" << caso + 1 << ": ";
		
		pair<pto, pto> square;
		pto leftier = pto(INT_MAX, INT_MAX), rightier = pto(INT_MIN, INT_MIN);
		
		cin >> n;
		forn(i,n) forn(j,n) {
			char t; scanf(" %c ", &t);
			board[i][j] = (t == '#');
			if (board[i][j]) {
				leftier.x = min(leftier.x, i);
				leftier.y = min(leftier.y, j);
				rightier.x = max(leftier.x, i);
				rightier.y = max(leftier.y, j);
			}
		}
		if ((rightier.y - leftier.y) != (rightier.x - leftier.x)) {
			cout << "NO\n";
		} else {
			value[0][0] = board[0][0];
			forn(i,n) forn(j,n){
				value[i][j] = (i == 0 ? 0 : value[i - 1][j]) + (j == 0 ? 0 : value[i][j - 1]) - (i == 0 || j == 0 ? 0 : value[i - 1][j - 1]) + board[i][j];
			}
			
			cout << (works()? "YES\n" : "NO\n");
		}
		//cout << "=========" << endl;
		//cout << squareSum(pto(0,2), pto(0,2)) << endl;
		//pto left = pto(0,2), right = pto(0,2);
		//cout << value[right.x][right.y] - value[right.x][left.y - 1] - value[left.x-1][right.y] + value[left.x - 1][right.y - 1] << endl;
		//cout << "===============================" << endl;
	}
}

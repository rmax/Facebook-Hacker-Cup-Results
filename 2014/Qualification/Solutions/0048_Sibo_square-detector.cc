#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	freopen("square_detector.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int T;
	cin >> T;
	for (int task = 1; task <= T; task++) {
		int n;
		scanf("%d\n", &n);
		int minR = n, maxR = -1, minC = n, maxC = -1, cnt = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				if (s[j] == '#') {
					cnt++;
					minR = min(minR, i);
					maxR = max(maxR, i);
					minC = min(minC, j);
					maxC = max(maxC, j);
				}
			}
		}
		int w = maxC - minC + 1;
		int h = maxR - minR + 1;
		printf("Case #%d: %s\n", task, w * h == cnt && w == h ? "YES" : "NO");
	}
	return 0;
}

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char s[22];

inline int sqr(int x) {
	return x * x;
}

int main() {
int z,zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n;
		scanf("%d",&n);
		int x1 = n, x2 = 0, y1 = n, y2 = 0, black = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s",s);
			for (int j = 0; j < n; ++j) {
				if (s[j] == '#') {
					x1 = min(x1, i);
					x2 = max(x2, i);
					y1 = min(y1, j);
					y2 = max(y2, j);
					++black;
				}
			}
		}	
	
		printf("Case #%d: %s\n",z,((x2 - x1 == y2 - y1) && (sqr(x2 - x1 + 1) == black))?"YES":"NO");
	}
	return 0;
}
	


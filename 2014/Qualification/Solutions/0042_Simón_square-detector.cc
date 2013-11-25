#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

char m[25][25];
int T, n;
int main() {
    scanf("%d\n", &T);
    for (int t=1; t<=T; t++) {
	scanf("%d\n", &n);
	for (int i=0; i<n; i++) {
	    for (int j=0; j<n; j++) {
		scanf("%c", &m[i][j]);
	    }
	    scanf("\n");
	}
	bool found = false;
	int x, y;
	for (int i=0; i<n&&!found; i++) {
	    for (int j=0; j<n&&!found; j++) {
		if(m[i][j] == '#') x = i, y = j, found = true;
	    }
	}
	int length = 0;
	bool ok = true;
	for (int j=y; j<n&&ok; j++) {
	    if (m[x][j] == '#') length++;
	    else ok = false;
	}
	// printf("%d\n", length);
	int sum = 0;
	for (int i=x; i<min(n, x+length); i++) {
	    for (int j=y; j<y+length; j++) {
		if (m[i][j] == '#') sum++;
	    }
	}
	bool square = (length*length == sum);
	int sum2 = 0;
	for (int i=0; i<n; i++)
	    for (int j=0; j<n; j++)
		if (m[i][j] == '#') sum2++;
	if (sum2 == sum && square)
	    printf("Case #%d: YES\n", t);
	else
	    printf("Case #%d: NO\n", t);
	int count = 0;


    }
    return 0;
}

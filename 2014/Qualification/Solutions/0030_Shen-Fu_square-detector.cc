#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int T, N;

char x[22][22];

int xmin, xmax, ymin, ymax;

int main()
{
	scanf("%d", &T);

	for(int caseidx = 1; caseidx <= T; caseidx++){

		scanf("%d", &N);

		xmax = ymax = -1;
		xmin = ymin = 100;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){

		//		scanf("%c", &x[i][j]);
				cin >> x[i][j];

				if(x[i][j] == '#'){
					xmin = MIN(xmin, j);
					ymin = MIN(ymin, i);
					xmax = MAX(xmax, j);
					ymax = MAX(ymax, i);
				}
			}
		}

		/*
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++)
				printf("%c", x[i][j]);
		printf("\n");
		}
		*/

		bool ans = (xmax - xmin == ymax - ymin);

		for(int i = ymin; ans && i <= ymax; i++){

			for(int j = xmin; ans && j <= xmax; j++){

				if(x[i][j] - '#')
					ans = false;
			}
		}

		printf("Case #%d: %s\n", caseidx, ans ? "YES" : "NO");
	}
	return 0;
}

// vi: ts=2 sw=2

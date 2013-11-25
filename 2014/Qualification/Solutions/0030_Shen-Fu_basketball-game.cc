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

int T, N, M, P;

string names[33];

int t[33];
vector<int> simulate(int N, int P, int M){

	for(int i = 0; i < P; i++)
		t[i] = i;
	for(int i = P; i < N; i++)
		t[i] = N - 1 - (i - P);

	int d = (N - (M % N)) % N;

	vector<int> ret;

	for(int i = 0; i < P; i++)
		ret.push_back(t[(i + d) % N]);

	return ret;
}

int main()
{
	//scanf("%d", T);
	cin >> T;
	for(int caseidx = 1; caseidx <= T; caseidx++){

		vector<pair<pair<int, int>, string> > S;

		S.clear();
		//scanf("%d %d %d", &N, &M, &P);
		cin >> N >> M >> P;

		for(int i = 0; i < N; i++){
			string name;
			int height;
			int shot;

			cin >> name >> shot >> height;

			S.push_back(pair<pair<int, int>, string>(pair<int, int>(shot, height), name));
		}

		sort(S.begin(), S.end());
		for(int i = 0; i < N; i++)
			names[i] = S[N - 1 - i].second;
		
		vector<int> a = simulate((N + 1) / 2, P, M);
		vector<int> b = simulate(N / 2, P, M);


		vector<string> ans;
		for(int i = 0; i < P; i++){
			ans.push_back(names[a[i] * 2]);
		}
		for(int i = 0; i < P; i++){
			ans.push_back(names[1 + b[i] * 2]);
		}
		sort(ans.begin(), ans.end());

		printf("Case #%d:", caseidx);
		for(int i = 0; i < 2 * P; i++)
			printf(" %s", ans[i].c_str());
		printf("\n");

	}

	return 0;
}

// vi: ts=2 sw=2

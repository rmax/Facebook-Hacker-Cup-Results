#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
vector<double> v;
int n;
double ps, pr, pi, pu, pw, pd, pl;
#define MAXN (101)
#define eps 1e-8
#define MAXM (MAXN * MAXN)
double f[MAXN][MAXN][MAXM];
double fpw = 0;
double fpl = 0;
int get(double p){
	int s = 1;
	int t = v.size() - 2;
	while (s <= t){
		int mid = (s + t) / 2;
		if (2 * p < v[mid] + v[mid - 1]){
			t = mid - 1;
		}else if (2 * p > v[mid] + v[mid + 1]){
			s = mid + 1;
		}else{
			return mid;
		}
		if (t < s) return mid;
	}
}

void add(int i, int j, double p, double p2){
	if (p < 0) p = 0;
	if (p > 1) p = 1;
	int k = get(p);
	//cout<<i<<' '<<j<<' '<<p<<' '<<p2<<endl;
	if (i == n) fpw += p2;
	else if (j == n) fpl += p2;
	f[i][j][k] += p2;
}
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int tt;
	cin>>tt;
	for (int t = 0; t < tt; ++t){
		cin>>n>>ps>>pr>>pi>>pu>>pw>>pd>>pl;
		v.clear();
		vector<double> v2;
		v2.push_back(-100);
		v2.push_back(0);
		v2.push_back(1);
		v2.push_back(100);
		for (int i = 0; i <= 2; ++i){
			for (int j = 0; j <= n; ++j)
				for (int k = 0; k <= n; ++k){
					double p = j * pu - k * pd;
					if (i == 1) p += pi;
					if (i == 2) p += 1;
					if (p >= 1) continue;
					if (p <= 0) continue;
					v2.push_back(p);
				} 
		}
		sort(v2.begin(), v2.end());
		for (int i = 0; i < v2.size(); ++i){
			if (v.size()&&(v2[i] - v[v.size() - 1] < eps)) continue;
			v.push_back(v2[i]);
		}
		//for (int i = 0; i < v.size(); ++i)
		//	cout<<v[i]<<' ';
		//cout<<endl;
		memset(f, 0, sizeof( f));
		f[0][0][get(pi)] = 1;
		fpw = 0;
		fpl = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < v.size(); ++k)
					if (f[i][j][k] > 0){
						//cout<<i<<' '<<j<<' '<<k<<endl;
						double pi = v[k];
						double p = pi * ps + (1 - pi) * pr;
						add(i + 1, j, pi, p * f[i][j][k] * (1-pw));
						add(i + 1, j, pi + pu, p * f[i][j][k] * pw);
						add(i, j + 1, pi, (1 - p) * f[i][j][k] * (1 - pl));
						add(i, j + 1, pi - pd, (1 - p) * f[i][j][k] * pl);
					}
		//cout<<fpw<<' '<<fpw + fpl<<endl;
		//fpw = fpw / (fpw + fpl);
		//fpw += eps;
		//cout<<
		printf("Case #%d: %.6lf\n", t + 1, fpw);

		//cout<<fpw<<endl;
			
	}
}

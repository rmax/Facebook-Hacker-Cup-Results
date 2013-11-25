
 #define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <list>
#include <cassert>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

int N, M, P;
vector<string> sub(const vector<pair<pii,string> > &v) {
//	each(i, v) cerr << i->second << ", "; cout << endl;
	vi t(N, 0);
	set<int> s;
	rep(i, P) s.insert(i);
	rep(i, M) {
//		cerr << i << ": "; each(i, s) cerr << v[*i].second << ", "; cout << endl;
		each(i, s) t[*i] ++;
		pii hi(-INF,-INF), lo(INF, INF);
		each(i, s) hi = max(hi, mp(t[*i], *i));
		int leave = hi.second;
		s.erase(leave);
		rep(i, v.size()) if(!s.count(i))
			lo = min(lo, mp(t[i], i));
		int join = lo.second;
		s.insert(join);
	}

	vector<string> names;
	each(i, s) names.pb(v[*i].second);
	return names;
}

int main() {
	int T;
	cin >> T;
	rep(ii, T) {
		cin >> N >> M >> P;
		vector<pair<pii,string> > v, even, odd;
		rep(i, N) {
			string name; int p, h;
			cin >> name >> p >> h;
			v.pb(mp(mp(p, h), name));
		}
		sort(all(v)); reverse(all(v));
		rep(i, N) ((i+1) % 2 == 1 ? odd : even).push_back(v[i]);

		cout << "Case #" << ii+1 << ": ";
		vector<string> s = sub(even), t = sub(odd);
		vector<string> names;
		each(i, s) names.pb(*i);
		each(i, t) names.pb(*i);
		sort(all(names));
		rep(i, names.size()) {
			cout << names[i];
			if(i+1 != names.size()) cout << " ";
		}
		cout << endl;
	}
	return 0;
}


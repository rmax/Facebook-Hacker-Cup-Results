#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;
typedef long long ll;

template<class T> T abs(T x) { return x > 0 ? x : (-x); }
template<class T> T sqr(T x) { return x * x; }

struct Point {
	int x, y, z;
	void scan() {
		cin >> x >> y >> z;
	}
	Point() {}
	Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

const int MAXN = 200;
Point p[MAXN];
int n;


Point median(const Point &a, const Point &b) {
	return Point((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
}

void print(const Point &a) {
	cerr << a.x << " " << a.y << " " << a.z << "  ";
}

int max_dst;
bool check(const Point &_min, const Point &_max) {//at least max_dst
/*	print(_min);
	print(_max);
	cerr << endl;*/
	Point _med = median(_min, _max);
	bool med_good = true;
	for (int i = 0; i < n; ++i) {
		int r = sqr(max(abs(_min.x - p[i].x), abs(_max.x - p[i].x))) + sqr(max(abs(_min.y - p[i].y), abs(_max.y - p[i].y))) + sqr(max(abs(_min.z - p[i].z), abs(_max.z - p[i].z)));
		if (r < max_dst) {
			return false;
		}
		if (med_good && (sqr(_med.x - p[i].x) + sqr(_med.y - p[i].y) + sqr(_med.z - p[i].z) < max_dst))
			med_good = false;
	}
//	cerr << max_dst << " " << med_good << endl;
	if (med_good) return true;
	if (_min.x >= _max.x && _min.y >= _max.y && _min.z >= _max.z) return false;
	if (check(Point(_min.x, _min.y, _min.z), Point(_med.x, _med.y, _med.z))) return true;
	if (check(Point(_min.x, _min.y, _med.z + 1), Point(_med.x, _med.y, _max.z))) return true;
	if (check(Point(_min.x, _med.y + 1, _min.z), Point(_med.x, _max.y, _med.z))) return true;
	if (check(Point(_min.x, _med.y + 1, _med.z + 1), Point(_med.x, _max.y, _max.z))) return true;
	if (check(Point(_med.x + 1, _min.y, _min.z), Point(_max.x, _med.y, _med.z))) return true;
	if (check(Point(_med.x + 1, _min.y, _med.z + 1), Point(_max.x, _med.y, _max.z))) return true;
	if (check(Point(_med.x + 1, _med.y + 1, _min.z), Point(_max.x, _max.y, _med.z))) return true;
	if (check(Point(_med.x + 1, _med.y + 1, _med.z + 1), Point(_max.x, _max.y, _max.z))) return true;
	return false;
}

bool check(int dst) {
	max_dst = dst;
	return check(Point(0, 0, 0), Point(1000, 1000, 1000));
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) p[i].scan();
	int OMIN = 0;
	int OMAX = 1000 * 1000 * 10;
	while (OMIN != OMAX - 1) {
		int t = (OMIN + OMAX) / 2;
		if (check(t))
			OMIN = t;
		else
			OMAX = t;
//		cerr << OMIN << " " << OMAX << endl;
	}
	cout << OMIN << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cerr << i << endl;
		solve();
	}
	return 0;
}

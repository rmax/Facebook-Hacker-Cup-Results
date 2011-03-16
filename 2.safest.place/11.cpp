#include <iostream>
#include <stdlib.h>
#include <numeric>
#include <vector>
#include <time.h>

using namespace std;
struct vec {
	int x, y, z;
	vec() {
		x = y = z = 0;
	}
	vec(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	bool operator == (const vec& r) const {
		return x == r.x && y == r.y && z == r.z;
	}
};

vector<vec> bombs;
int best_result;

int dist(const vec& v0, const vec& v1) {
	return (v0.x - v1.x)*(v0.x - v1.x) + 
		   (v0.y - v1.y)*(v0.y - v1.y) + 
		   (v0.z - v1.z)*(v0.z - v1.z);
}

int calc_dist(const vec& v) {
	int res = numeric_limits<int>::max();

	for (int i=0; i < bombs.size(); i++) {
		res = min(res, dist(v, bombs[i]));
	}

	return res;
}

int estimate_cube(const vec& b, const vec& v0, const vec& v1) {
	int res = 0;
	res = max(res, dist(b, vec(v0.x, v0.y, v0.z)));
	res = max(res, dist(b, vec(v0.x, v0.y, v1.z)));
	res = max(res, dist(b, vec(v0.x, v1.y, v0.z)));
	res = max(res, dist(b, vec(v0.x, v1.y, v1.z)));
	res = max(res, dist(b, vec(v1.x, v0.y, v0.z)));
	res = max(res, dist(b, vec(v1.x, v0.y, v1.z)));
	res = max(res, dist(b, vec(v1.x, v1.y, v0.z)));
	res = max(res, dist(b, vec(v1.x, v1.y, v1.z)));
	return res;
}

void check_cube(const vec& v0, const vec& v1) {
	if (v0.x > v1.x) return;
	if (v0.y > v1.y) return;
	if (v0.z > v1.z) return;

	if (v0 == v1) {
		best_result = max(best_result, calc_dist(v0));
		return;
	}

	int estim = numeric_limits<int>::max();
	for (int i=0; i < bombs.size(); i++) {
		estim = min(estim, estimate_cube(bombs[i], v0, v1));
	}
	if (estim < best_result)
		return;

	vec vm((v0.x + v1.x)/2,
		   (v0.y + v1.y)/2,
		   (v0.z + v1.z)/2);

	check_cube(vec(v0.x, v0.y, v0.z),
			   vec(vm.x, vm.y, vm.z));
	check_cube(vec(vm.x+1, v0.y, v0.z),
			   vec(v1.x, vm.y, vm.z));
	check_cube(vec(v0.x, vm.y+1, v0.z),
			   vec(vm.x, v1.y, vm.z));
	check_cube(vec(vm.x+1, vm.y+1, v0.z),
			   vec(v1.x, v1.y, vm.z));
	check_cube(vec(v0.x, v0.y, vm.z+1),
			   vec(vm.x, vm.y, v1.z));
	check_cube(vec(vm.x+1, v0.y, vm.z+1),
			   vec(v1.x, vm.y, v1.z));
	check_cube(vec(v0.x, vm.y+1, vm.z+1),
			   vec(vm.x, v1.y, v1.z));
	check_cube(vec(vm.x+1, vm.y+1, vm.z+1),
			   vec(v1.x, v1.y, v1.z));
}

int solve() {
	srand(time(0));
	best_result = 0;

	for (int i=0; i < 1000; i++) {
		vec pt(0, 0, 0);
		pt.x = rand() % 1001;
		pt.y = rand() % 1001;
		pt.z = rand() % 1001;
		best_result = max(best_result, calc_dist(pt));
	}

	check_cube(vec(0, 0, 0), vec(1000, 1000, 1000));
	return best_result;
}

int bruteforce() {
	int res = 0;
	for (int x=0; x < 1000; x++) 
		for (int y=0; y < 1000; y++)
			for (int z=0; z < 1000; z++)
				res = max(res, calc_dist(vec(x, y, z)));
	return res;
}

int main() {
	freopen("safest_place.txt", "r", stdin);
	freopen("safest_place.out", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		bombs.resize(N);

		for (int i=0; i < N; i++)
			cin >> bombs[i].x >> bombs[i].y >> bombs[i].z;

		int res = solve();
/*		int bf = bruteforce();
		if (res != bf) {
			cout << "No: " << res << " < " << bf << endl;
		} else {
			cout << "Yes: " << res << endl;
		}*/
		cout << res << endl;
	}

	return 0;
}
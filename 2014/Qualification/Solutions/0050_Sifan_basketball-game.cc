#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 40;

struct Person {
	char name[30];
	int percentage, height, rank;
	void input() {
		scanf("%s%d%d", name, &percentage, &height);
	}
} persons[N];

bool by_rank(const Person &a, const Person &b) {
	return a.percentage > b.percentage || a.percentage == b.percentage && a.height > b.height;
}

bool by_name(const int a, const int b) {
	return strcmp(persons[a].name, persons[b].name) < 0;
}

int n, m, p;

int total[N];

void solve(std::vector<int>& team, std::vector<int>& remain) {
	memset(total, 0, sizeof(total));
	std::set<int> onfield;
	for (int i = 0; i < p; ++ i) {
		onfield.insert(team[i]);
	}
	for (int counter = 0; counter < m; ++ counter) {
		int leave_id = -1;
		foreach(iter, onfield) {
			int u = *iter;
			total[u] ++;
			if (leave_id == -1 || total[u] > total[leave_id] || total[u] == total[leave_id] && u > leave_id) {
				leave_id = u;
			}
		}

		int enter_id = -1;
		foreach(iter, team) {
			int u = *iter;
			if (onfield.find(u) == onfield.end()) {
				if (enter_id == -1 || total[u] < total[enter_id] || total[u] == total[enter_id] && u < enter_id) {
					enter_id = u;
				}
			}
		}

		if (enter_id >= 0 && leave_id >= 0) {
			onfield.erase(leave_id);
			onfield.insert(enter_id);
		}
	}

	foreach(iter, onfield) {
		int u = *iter;
		remain.push_back(u);
	}
}

int main() {
	//freopen("B.in", "r", stdin);
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; ++ t) {
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 0; i < n; ++ i) {
			persons[i].input();
		}
		std::sort(persons, persons + n, by_rank);

		std::vector<int> team[2];
		for (int i = 0; i < n; ++ i) {
			team[i & 1].push_back(i);
		}

		std::vector<int> remain;
		for (int i = 0; i < 2; ++ i) {
			solve(team[i], remain);
		}
		std::sort(remain.begin(), remain.end(), by_name);
		printf("Case #%d: ", t);
		for (int i = 0; i < remain.size(); ++ i) {
			printf("%s%c", persons[remain[i]].name, i + 1 == remain.size() ? '\n' : ' ');
		}
	}
	return 0;
}

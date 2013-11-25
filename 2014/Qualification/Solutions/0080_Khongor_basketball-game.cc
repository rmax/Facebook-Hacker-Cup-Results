#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

struct my {
    string name;
    int id;
    int x, y;
    int played;
    int active;
};

bool comp(my a, my b) {
    if (a.x > b.x) return true;
    if (a.x < b.x) return false;
    if (a.x == b.x) return a.y > b.y;
}

vector<my> get(vector<my> v, int m, int p) {
    int n = v.size();
    p = min(p, n);
    vector<my> cur;
    for (int i = 0; i < n; i++) v[i].played = 0, v[i].active = 0;
    for (int i = 0; i < p; i++) v[i].active = 1;
    while (m--) {
        for (int i = 0; i < n; i++) if (v[i].active) v[i].played++;
        int idx = -1, idx2 = -1;
        for (int i = 0; i < n; i++)
            if (v[i].active) {
                if (idx == -1 || (v[i].played > v[idx].played || v[i].played == v[idx].played && v[i].id > v[idx].id)) idx = i;
            }
            else {
                if (idx2 == -1 || (v[i].played < v[idx2].played || v[i].played == v[idx2].played && v[i].id < v[idx2].id)) idx2 = i;
            }
        if (idx == -1 || idx2 == -1) continue;
        v[idx].active = 0;
        v[idx2].active = 1;
    }
    for (int i = 0; i < n; i++)
        if (v[i].active) cur.push_back(v[i]);
    return cur;
}

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    my a[30];

    for (int i = 0; i < n; i++)
        cin >> a[i].name >> a[i].x >> a[i].y;
    sort(a, a + n, comp);

    vector<my> t1, t2;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        if (i % 2) t1.push_back(a[i]);
        else t2.push_back(a[i]);
    }

    vector<string> res;
    vector<my> v = get(t1, m, p);
    for (int i = 0; i < v.size(); i++) res.push_back(v[i].name);
    v = get(t2, m, p);
    for (int i = 0; i < v.size(); i++) res.push_back(v[i].name);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) cout << " " << res[i];
    cout << endl;
}

int main() {
    //freopen("basketball_game.in", "r", stdin);
    //freopen("basketball_game.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; test++) {
        printf("Case #%d:", test);
        solve();
    }
    return 0;
}

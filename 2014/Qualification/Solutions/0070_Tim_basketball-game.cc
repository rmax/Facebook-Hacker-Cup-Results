#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<string> ans;
int m, p;

void work(const vector<string> v) {
    int n = (int)v.size();
    //if (n == p) {
    //    for (int i = 0; i < n; i++) {
    //        ans.push_back(v[i]);
    //    }
    //    return;
    //}
    vector<bool> vis(n);
    vector<int> play(n);
    for (int i = 0; i < p; i++) {
	vis[i] = true;
    }
    int mm = m;
    while (mm--) {
	for (int i = 0; i < n; i++) {
	    if (vis[i]) {
		play[i]++;
	    }
	}
	  {
	    int maxn = -1;
	    for (int i = 0; i < n; i++) {
		if (vis[i]) {
		    if (maxn == -1 || play[maxn] <= play[i]) {
			maxn = i;
		    }
		}
	    }
	    vis[maxn] = false;
	  }
	  {
	    int minn = -1;
	    for (int i = 0; i < n; i++) {
		if (!vis[i]) {
		    if (minn == -1 || play[minn] > play[i]) {
			minn = i;
		    }
		}
	    }
	    vis[minn] = true;
	  }
    }
    for (int i = 0; i < n; i++) {
	if (vis[i]) {
	    ans.push_back(v[i]);
	}
    }
}

int main() {
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
	int n;
	cin >> n >> m >> p;
	string s;
	int l, r;
	vector<tuple<int, int, string>> tt(n);
	for (int i = 0; i < n; i++) {
	    cin >> s >> l >> r;
	    tt[i] = make_tuple(-l, -r, s);
	}
	sort(tt.begin(), tt.end());
	vector<string> v[2];
	int pp = 0;
	for (int i = 0; i < n; i++) {
	    v[pp].push_back(get<2>(tt[i]));
	    pp = 1 - pp;
	}
	ans.clear();
	work(v[0]);
	work(v[1]);
	sort(ans.begin(), ans.end());
	cout << "Case #" << ca << ":";
	for (auto &s : ans) {
	    cout << " " << s;
	}
	cout << "\n";
    }
    return 0;
}

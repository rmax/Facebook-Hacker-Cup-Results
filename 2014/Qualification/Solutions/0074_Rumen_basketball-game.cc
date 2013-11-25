#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p;
vector < pair<pair<int,int>, string > > qq;
vector<string> a, b;
vector<int> ta, tb;

vector<int> cura, curb;

void read() {
	string s;
	int q, w;
	
	qq.clear();
	a.clear();
	b.clear();
	ta.clear();
	tb.clear();
	cura.clear();
	curb.clear();
	
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> s >> q >> w;
		
		qq.push_back( make_pair(make_pair(q,w), s));
	}
	
	sort (qq.rbegin(), qq.rend());
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			b.push_back(qq[i].second);
			tb.push_back(0);
		} else {
			a.push_back(qq[i].second);
			ta.push_back(0);
		}
	}
}

void solve() {
	int i;
	
	for (i = 0; i < p; i++) {
		cura.push_back(i);
		curb.push_back(i);
	}
	while (m --) {
		for (i = 0; i < (int)cura.size(); i++) {
	//		printf ("%s ", a[cura[i]].c_str());
			ta[cura[i]] ++;
		}
	//	printf ("\n");
		
		for (i = 0; i < (int)curb.size(); i++) {
	//		printf ("%s ", b[curb[i]].c_str());
			tb[curb[i]] ++;
		}
	//	printf ("\n");
		
		if ((int)a.size() > p) {
			int sw = 0;
			
			for (i = 1; i < (int)cura.size(); i++) {
				if (ta[cura[i]] > ta[cura[sw]]
					|| (ta[cura[i]] == ta[cura[sw]] && cura[i] > cura[sw]))
					sw = i;
			}
			
			cura.erase(cura.begin() + sw);
			
			sw = -1;
			for (i = 0; i < (int)a.size(); i++) {
				if (find(cura.begin(), cura.end(), i) == cura.end()) {
					if (sw == -1 || ta[i] < ta[sw]) {
						sw = i;
					}
				}
			}
			
			cura.push_back(sw);
		}
		
		swap (cura, curb);
		swap (a, b);
		swap (ta, tb);
		
		if ((int)a.size() > p) {
			int sw = 0;
			
			for (i = 1; i < (int)cura.size(); i++) {
				if (ta[cura[i]] > ta[cura[sw]]
					|| (ta[cura[i]] == ta[cura[sw]] && cura[i] > cura[sw]))
					sw = i;
			}
			
			cura.erase(cura.begin() + sw);
			
			sw = -1;
			for (i = 0; i < (int)a.size(); i++) {
				if (find(cura.begin(), cura.end(), i) == cura.end()) {
					if (sw == -1 || ta[i] < ta[sw]) {
						sw = i;
					}
				}
			}
			
			cura.push_back(sw);
		}
		
		swap (cura, curb);
		swap (a, b);
		swap (ta, tb);
	}
	
	
	vector<string> ans;
	for (i = 0; i < (int)cura.size(); i++) ans.push_back(a[cura[i]]);
	for (i = 0; i < (int)curb.size(); i++) ans.push_back(b[curb[i]]);
	
	sort(ans.begin(), ans.end());
	for (i = 0; i < (int)ans.size(); i++) {
		printf ("%s%c", ans[i].c_str(), ((i + 1) == (int)ans.size()) ? '\n' : ' ');
	}
}

int main() {
	int i, cases;
	
	cin >> cases;
	for (i = 1; i <= cases; i++) {
		read();
		printf ("Case #%d: ", i);
		solve();
	//	break;
	}
	
	return 0;
}
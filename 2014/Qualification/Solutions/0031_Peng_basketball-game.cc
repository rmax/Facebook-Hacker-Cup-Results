#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct player {
int id;
int time;
string name;
};

struct node {
int per;
int height;
string name;
};

char s[100];
node all[40];

bool operator<(const player &p1,const player &p2) {
	return make_pair(p1.time, p1.id) < make_pair(p2.time,p2.id);
}


set<player> after(set<player> &a) {
set<player> r;
	for (set<player>::iterator t = a.begin(); t != a.end(); ++t) {
		player temp;
		temp.id = t->id;
		temp.time = t->time + 1;
		temp.name = t->name;
		r.insert(temp);
	}
	return r;
}

bool cmp(const node &p1,const node &p2) {
	return make_pair(p1.per,p1.height) > make_pair(p2.per, p2.height);
}


	

int main() {
int zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int n, m, p;
		scanf("%d%d%d",&n,&m,&p);
		for (int i = 0; i < n; ++i) {
			scanf("%s%d%d",s,&all[i].per,&all[i].height);
			all[i].name = s;
		}
		sort(all, all + n, cmp);
		
		set<player> a[2],b[2];
		for (int i = 0; i < n; ++i) {
			player temp;
			temp.id = i + 1;
			temp.time = 0;
			temp.name = all[i].name;
			int x = temp.id & 1;
			if (a[x].size() < p) {
				a[x].insert(temp);
			}
			else {
				b[x].insert(temp);
			}
		}
		
		for (;m;--m) {
			for (int i = 0; i < 2; ++i) {
				a[i] = after(a[i]);
				if (!b[i].empty()) {
					set<player>::iterator t = a[i].end();
					--t;
					player temp;
					temp.id = t->id;
					temp.time = t->time;
					temp.name = t->name;
					a[i].erase(t);
					a[i].insert(*(b[i].begin()));
					b[i].erase(b[i].begin());
					b[i].insert(temp);
				}
		
			}
		
		}
		multiset<string> have;
		for (int i = 0; i < 2; ++i) {
			for (set<player>::iterator t = a[i].begin(); t != a[i].end(); ++t) {
				have.insert(t->name);
			}
		}
		printf("Case #%d:",z);
		for (multiset<string>::iterator t = have.begin(); t != have.end(); ++t) {
			printf(" %s",t->c_str());
		}
		puts("");
	}
	return 0;
}
		 


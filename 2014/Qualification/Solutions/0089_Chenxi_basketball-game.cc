#include<set>
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
struct NODE{
	string name;
	int height;
	int shot;
	int on;
	int down;
	int id;
	bool operator < (const NODE &a)const{
		if (shot != a.shot) return shot > a.shot;
		return height > a.height;
	}
};
struct cmpon{
	bool operator ()(const NODE &a, const NODE &b){
		if (a.down != b.down) return a.down < b.down;
		return a.id > b.id;
	}
};
struct cmpdown{
	bool operator ()(const NODE &a, const NODE &b){
		if (a.on != b.on) return a.on < b.on;
		return a.id < b.id;
	}
};
void gao(vector<NODE> &v, int m, int p, vector<string> &ans){
	set<NODE, cmpon> ons;
	set<NODE, cmpdown> downs;
	//for (int i = 0; i < v.size(); ++i){
	//	cout<<v[i].name<<' '<<v[i].id<<endl;
	//}
	for (int i = 0; i < p; ++i){
		ons.insert(v[i]);
	}
	for (int i = p; i < v.size(); ++i){
		downs.insert(v[i]);
	}
	
	for (int t = 1; t <= m; ++ t){
		if (!downs.empty()){
			
			NODE down = *ons.begin();
			ons.erase(ons.begin());
			down.on = t - down.down;
			NODE up = *downs.begin();
			downs.erase(downs.begin());
			up.down = t - up.on;
			ons.insert(up);
			downs.insert(down);
			//cout<<down.name<<' '<<up.name<<endl;
			/*
			NODE down = *ons.begin();
			ons.erase(ons.begin());
			down.on = t - down.down;
			downs.insert(down);
			NODE up = *downs.begin();
			downs.erase(downs.begin());
			up.down = t - up.on;
			ons.insert(up);*/
		}
	}
	while (!ons.empty()){
		ans.push_back((*ons.begin()).name);
		ons.erase(ons.begin());
	}
}
NODE a[100];
int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tt;
	cin>>tt;
	int n, m, p;
	for (int t = 0; t < tt; ++t){
		cin>>n>>m>>p;
		for (int i = 0; i < n; ++i){
			cin>>a[i].name>>a[i].shot>>a[i].height;
			a[i].on = a[i].down = 0;
		}
		vector<NODE> v1, v2;
		sort(a, a + n);
		for (int i = 0; i < n; ++i){
			//cout<<a[i].name<<endl;
			a[i].id = i;
			if (i % 2 == 0) v1.push_back(a[i]);
			else v2.push_back(a[i]);
		}
		vector<string> ans;
		gao(v1, m, p, ans);
		gao(v2, m, p, ans);
		sort(ans.begin(), ans.end());
		cout<<"Case #"<<t + 1<<":";
		for (int i = 0; i < ans.size(); ++i){
			cout<<' '<<ans[i];
		}
		cout<<endl;
	}
}

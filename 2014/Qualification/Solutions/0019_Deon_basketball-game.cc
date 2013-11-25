#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <utility>
#include <cctype>
#include <list>

using namespace std;

#define FORALL(i,a,b) for(int i=(a);i<=(b);++i)
#define FOR(i,n) for(int i=0;i<(n);++i)
#define FORB(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef long double ld;
typedef complex<ld> vec;

typedef pair<int,int> pii;
typedef map<int,int> mii;

#define pb push_back
#define mp make_pair

struct player {
	string name;
	int shot, height, minutes;
	bool operator<(const player& b) const {	// rank / draft pick
		return mp(shot,height) > mp(b.shot,b.height);
	}
	bool operator>(const player& b) const {
		return mp(shot,height) < mp(b.shot,b.height);
	}
	
	friend ostream& operator<<(ostream& out, const player& p) {
		return out << "(" << p.name << "," << p.shot << "," << p.height << "," << p.minutes << ")";
	}
};

struct by_minutes{ 
	bool operator()(const player& a, const player& b) const {
		if (a.minutes > b.minutes) return false;
		if (a.minutes < b.minutes) return true;
		if (a > b) return false;	// by rank / draft pick
		if (a < b) return true;
		assert(false);
	}
};

struct by_bench{ 
	bool operator()(const player& a, const player& b) const {
		if (a.minutes < b.minutes) return false;
		if (a.minutes > b.minutes) return true;
		if (a<b) return false;
		if (a>b) return true;
		assert(false);
	}
};

#warning same name?
#warning M = 0?

#define move_player(X,Y) (Y.push(X.top()), X.pop())
#define MAXN 35
player Players[MAXN];

typedef priority_queue<player, vector<player>, by_minutes> Field;
typedef priority_queue<player, vector<player>, by_bench> Bench;

void up_minutes(Field& f) {
	Field tmp;
	while(!f.empty()) {
		player p = f.top(); f.pop();
		p.minutes++;
		tmp.push(p);
	}
	f = tmp;
}

void print(Field F) {
	cout << "[";
	while(!F.empty()) {
		cout << F.top().name << ",";
		F.pop();
	}
	cout << "]" << endl;
}

int main () {
	int TEST;
	cin >> TEST;
	FOR(test,TEST) {
		int N,M,P;
		cin >> N >> M >> P;
		FOR(i,N) Players[i].minutes = 0, cin >> Players[i].name >> Players[i].shot >> Players[i].height;
		sort(Players,Players+N);
		
		//FOR(i,N) cout << Players[i] << endl;
		
		Bench benchA, benchB;
		Field fieldA, fieldB;
		FOR(i,N)
			if (i%2) benchB.push(Players[i]);
			else benchA.push(Players[i]);
		
		assert((int)benchA.size() >= P);
		assert((int)benchB.size() >= P);
		while((int)fieldA.size() < P) move_player(benchA,fieldA);
		while((int)fieldB.size() < P) move_player(benchB,fieldB);
		FOR(minutes,M) {
			//cout << "minute: " << minutes << endl;
			//print(fieldA);
			//print(fieldB);
			//cout << endl;
			
			up_minutes(fieldA);
			up_minutes(fieldB);
			
			move_player(fieldA,benchA);
			move_player(benchA,fieldA);
			
			move_player(fieldB,benchB);
			move_player(benchB,fieldB);
			assert((int)fieldA.size() == P);
			assert((int)fieldB.size() == P);
		}
		
		multiset<string> players_on_field;
		while(!fieldA.empty()) players_on_field.insert(fieldA.top().name), fieldA.pop();
		while(!fieldB.empty()) players_on_field.insert(fieldB.top().name), fieldB.pop();
		
		assert((int)players_on_field.size() == 2*P);
		
		cout << "Case #" << test+1 << ": ";
		bool sp = false;
		for(multiset<string>::iterator it = players_on_field.begin();
			it != players_on_field.end();
			++it) {
			if (sp) cout << " ";
			sp = true;
			cout << *it;
		}
		cout << endl;
	}
}












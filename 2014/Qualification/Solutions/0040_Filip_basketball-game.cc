#include<cstdio>
#include<iostream>
#include<cassert>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<set>
using namespace std;
typedef vector<int> VI;
typedef long long LL;
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) __typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MP make_pair
#define PB push_back
#define ST first
#define ND second
#define DEBUG 1
#define debug(x) {if (DEBUG) cerr << #x << " = " << x << endl; }
#define debugv(x) { if (DEBUG) {cerr << #x << " = "; FOREACH(ii, (x)) cerr << *ii << ", "; cerr << endl; }}

const int MAXN = 32;
const int MAXM = 140;
const int MAXP = 150;

int n,m,p;
struct player{
    string name;
    int p;
    int h;
    int tim;
    player(string name, int p, int h){
        this->tim = 0;
        this->name = name;
        this->p = p;
        this->h = h;
    }
};

bool cmp(const player & a, const player & b){
return MP(a.p,a.h) > MP(b.p,b.h);
}

struct fieldcmp{
    bool operator()(const player & a, const player & b){
        if (a.tim > b.tim) return true;
        if (a.tim < b.tim) return false;
        return MP(a.p, a.h) < MP(b.p, b.h);
    }
};
struct benchcmp{
    bool operator()(const player & a, const player & b){
        if (a.tim < b.tim) return true;
        if (a.tim > b.tim) return false;
        return MP(a.p, a.h) > MP(b.p, b.h);
    }
};
vector<string> tsolve(vector<player> team){
    set<player, fieldcmp> field;
    set<player, benchcmp> bench;
    FOREACH(it, team){
        if (field.size() < p) field.insert(*it);
        else bench.insert(*it);
    }
    REP(i, m){
        if (bench.empty()) break;
        set<player, fieldcmp> tmpfi;
        FOREACH(it, field){
            player tmp(*it);
            tmp.tim++;
            tmpfi.insert(tmp);
        }
        field = tmpfi;

        player sch = *field.begin();
        player wch = *bench.begin();
        
        field.erase(sch);
        bench.erase(wch);
        field.insert(wch);
        bench.insert(sch);
    }
    vector<string> res;
    FOREACH(it, field){
        res.PB(it -> name);
    }
    return res;
}
void solve(int no){
    cin >> n >>m>>p;
    vector<player> ps;
    REP(i,n){
        string s;
        int p,  h;
        cin >> s >> p >> h;
        ps.PB(player(s,p,h));
    }
    sort(ALL(ps), cmp);
    vector<player> t1;
    vector<player> t2;
    REP(i,n){
        if (i%2 == 0) t1.PB(ps[i]);
        else t2.PB(ps[i]);
    }
    vector<string> res;
    vector<string> tt1(tsolve(t1)), tt2(tsolve(t2));
    REP(i,p){
        res.PB(tt1.back());
        res.PB(tt2.back());
        tt1.pop_back();
        tt2.pop_back();
    }
    sort(ALL(res));
    cout << "Case #" << no <<":";
    FOREACH(it, res){
        cout << ' ' << *it;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    REP(i,t){
        solve(i + 1);
    }
}

#include <bits/stdc++.h>
#define Fr(i,a,b) for(int i = (a); i < (b); ++i)
#define Rp(i,n) Fr(i,0,n)
#define all(c) (c).begin(), (c).end()
#define pb push_back

using namespace std;

struct no {
    string name;
    int sp, h;
    int draft;
    no(){}
    no(string name, int sp, int h):name(name), sp(sp), h(h), draft(0){}
    bool operator <(const no& n) const {
        if(sp != n.sp) return sp > n.sp;
        return h > n.h; 
    }
};

struct atl {
    int min; no n;
    atl(){}
    atl(int min, no n):min(min), n(n){}
};

bool cmpr(const atl &a, const atl &b) { //remove
    if(a.min != b.min) return a.min > b.min;
    return a.n.draft > b.n.draft;
}

bool cmpa(const atl &a, const atl &b) { //adiciona
    if(a.min != b.min) return a.min < b.min;
    return a.n.draft < b.n.draft;
}

no A[33];

int main() {
    int tc; cin >> tc; ++tc;
    Fr(_,1,tc) {
        int n,m,p;
        cin >> n >> m >> p;
        Rp(i,n) {
            cin >> A[i].name >> A[i].sp >> A[i].h;
        }
        sort(A,A + n);
        Rp(i,n) A[i].draft = i;
        vector<atl> times[2];
        Rp(i,n) {
            times[i&1].pb( atl(0,A[i]) );
        }
        
        vector<atl> joga[2], res[2];
        Rp(k,2) Rp(i,p) joga[k].pb(times[k][i]);
        Rp(k,2) Fr(i,p,times[k].size()) res[k].pb(times[k][i]);
        
        while(m--) {
            Rp(k,2) sort(all(joga[k]), cmpr);
            Rp(k,2) sort(all(res[k]), cmpa);
            Rp(k,2) Rp(i,p) ++joga[k][i].min;
            Rp(k,2) if(joga[k].size() && res[k].size()) swap(joga[k][0], res[k][0]);
        }
        
        vector<string> ans;
        Rp(k,2) Rp(i,p) ans.pb(joga[k][i].n.name);
        sort(all(ans));
        printf("Case #%d:",_);
        Rp(i,ans.size()) {
            cout << " " << ans[i];
        }
        puts("");
    }
    return 0;
}

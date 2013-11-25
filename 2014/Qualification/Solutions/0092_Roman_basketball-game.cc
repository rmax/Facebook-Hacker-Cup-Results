#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;


#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second
#define y1 y1_gdssdfjsdgf
#define y0 y0_fsdjfsdogfs
#define ws ws_fdfsdfsdgfs
#define image(a) {sort(all(a)),a.resize(unique(all(a))-a.begin());}
#define eprintf(...) {fprintf(stderr,__VA_ARGS__),fflush(stderr);}

#define forn(i,n) for( int i = 0 ; i < (n) ; i++ )
#define forit(it,c) for( __typeof((c).begin()) it = (c).begin() ; it != (c).end() ; it++ )
#define problem_name "a"
int x[1000];
int sp[1000];
int h[1000];
int tim[1000];
int was[1000];
char s[1000][1000];

int main(){
    #ifdef home
    //assert(freopen(problem_name".out","wt",stdout));
    #endif
    //assert(freopen(problem_name".in","rt",stdin));
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d:", ti);
        int n, m, p;
        scanf("%d %d %d", &n, &m, &p);
        vector<pair<int, int> > g;
        for (int i = 0; i < n; i++) {
            scanf("%s %d %d", s[i], &sp[i], &h[i]);
            x[i] = sp[i] * 1000 + h[i];
            g.pb(mp(x[i], i));
            tim[i] = 0;
            was[i] = 0;
        }
        sort(all(g));
        reverse(all(g));
        vector<pair<int, int> > t1, t2;
        for (int i = 0; i < sz(g); i++) {
            if (i % 2 == 0) {
                t1.pb(g[i]);
            } else {
                t2.pb(g[i]);
            }
        }  

        for (int i = 0; i < p; i++) {
            was[t1[i].y] = 1;
            was[t2[i].y] = 1;
        }
        for (int it = 0; it < m; it++) {
/*            for (int i = 0; i < sz(t1); i++) if (was[t1[i].y]) {
                cerr<<s[t1[i].y]<<" ";
            }
            cerr<<endl;
            for (int i = 0; i < sz(t2); i++) if (was[t2[i].y]) {
                cerr<<s[t2[i].y]<<" ";
            }
            cerr<<endl;*/
            for (int i = 0; i < n; i++) {
                if (was[i] == 1) {
                    tim[i]++;
                }
            }
            if (sz(t1) > p) {
                int mxi = -1;
                for (int i = 0; i < sz(t1); i++) {
                    int id = t1[i].y;
                    if (was[id] == 1 && (mxi == -1 || (tim[mxi] < tim[id] || (tim[mxi] == tim[id] && x[mxi] > x[id])))) {
                        mxi = id;
                    }
                }
                assert(mxi != -1);
                was[mxi] = 0;
                mxi = -1;
                for (int i = 0; i < sz(t1); i++) {
                    int id = t1[i].y;
                    if (was[id] == 0 && (mxi == -1 || (tim[mxi] > tim[id] || (tim[mxi] == tim[id] && x[mxi] < x[id])))) {
                        mxi = id;
                    }
                }
                assert(mxi != -1);
                was[mxi] = 1;
            }
            if (sz(t2) > p) {
                int mxi = -1;
                for (int i = 0; i < sz(t2); i++) {
                    int id = t2[i].y;
                    if (was[id] == 1 && (mxi == -1 || (tim[mxi] < tim[id] || (tim[mxi] == tim[id] && x[mxi] > x[id])))) {
                        mxi = id;
                    }
                }
                assert(mxi != -1);
//                cerr<<mxi<<endl;
                was[mxi] = 0;
                mxi = -1;
                for (int i = 0; i < sz(t2); i++) {
                    int id = t2[i].y;
                    if (was[id] == 0 && (mxi == -1 || (tim[mxi] > tim[id] || (tim[mxi] == tim[id] && x[mxi] < x[id])))) {
                        mxi = id;
                    }
                }
                assert(mxi != -1);
//                cerr<<mxi<<endl;
                was[mxi] = 1;
            }            
        }
        vector<string> names;
        for (int i = 0; i < n; i++) {
            if (was[i] == 1) {
                string ss(s[i]);
                names.pb(ss);
            }
        }
        sort(all(names));
        for (int i = 0; i < sz(names); i++) {
            printf(" %s", names[i].c_str());
        }
        printf("\n");
    }

    return 0;
}

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
char a[1000];
int main(){
    #ifdef home
    assert(freopen(problem_name".out","wt",stdout));
    #endif
    assert(freopen(problem_name".in","rt",stdin));
    int T;
    scanf("%d", &T);
    for (int ti = 1; ti <= T; ti++) {
        printf("Case #%d: ", ti);
        int n;
        scanf("%d", &n);
        int cnt = 0;
        int minx = n;
        int miny = n;
        int maxx = 0;
        int maxy = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", a);
            for (int j = 0; j < n; j++) {
                if (a[j] == '#') {
                    minx = min(minx, i);
                    miny = min(miny, j);
                    maxx = max(maxx, i);
                    maxy = max(maxy, j);
                    cnt++;
                }
            }
        }
        if (maxx - minx == maxy - miny && cnt == (maxy - miny + 1) * (maxy - miny + 1) && cnt > 0) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

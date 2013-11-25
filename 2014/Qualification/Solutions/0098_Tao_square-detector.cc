#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char g[55][55];
int main(){
    int t, n;
    cin >> t;
    for(int ca=0;ca<t;ca++){
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> g[i];
        int u = n, d = -1, r = -1, l = n;
        int cnt = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                if(g[i][j] == '#'){
                    cnt++;
                    u = min(u,i);
                    d = max(d,i);
                    l = min(l,j);
                    r = max(r,j);
                }
            }
        cout << "Case #" << ca + 1 << ": ";
        if(cnt == (r-l+1)*(d-u+1) && r-l==d-u)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

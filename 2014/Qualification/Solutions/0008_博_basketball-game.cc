#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;
struct Tnode{
    int a, b, c;
    string s;
} t[33];

int v[33], T[33];
vector <string> s;


bool cmp(Tnode a, Tnode b){
    if (a.a != b.a) return a.a > b.a;
    return a.b > b.b;
}

int main(){
    int CAS, n, m, p;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> CAS;
    for (int cas = 1; cas <= CAS; cas++){
        cin >> n >> m >> p;
        for (int i = 0; i < n; i++)
            cin >> t[i].s >> t[i].a >> t[i].b;
        sort(t, t + n, cmp);
        for (int i = 0; i < n; i++) t[i].c = i;
        memset(v, 0, sizeof(v));
        memset(T, 0, sizeof(T));
        for (int i = 0; i < 2 * p; i++) v[i] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++) T[j] += v[j];
            int mx1 = 0, mx2 = 0, p1, p2, mn1 = INF, mn2 = INF;
            for (int j = 0; j < n; j += 2)
            if (v[j] && (T[j] > mx1 || (T[j] == mx1 && t[j].c > mx2))){
                mx1 = T[j];
                mx2 = t[j].c;
                p1 = j;
            }
            for (int j = 0; j < n; j += 2)
            if (!v[j] && (T[j] < mn1 || (T[j] == mn1 && t[j].c < mn2))){
                mn1 = T[j];
                mn2 = t[j].c;
                p2 = j;
            }
            if ((n + 1) / 2 > p) v[p1] = 0, v[p2] = 1;

            mx1 = 0, mx2 = 0, mn1 = INF, mn2 = INF;
            for (int j = 1; j < n; j += 2)
            if (v[j] && (T[j] > mx1 || (T[j] == mx1 && t[j].c > mx2))){
                mx1 = T[j];
                mx2 = t[j].c;
                p1 = j;
            }
            for (int j = 1; j < n; j += 2)
            if (!v[j] && (T[j] < mn1 || (T[j] == mn1 && t[j].c < mn2))){
                mn1 = T[j];
                mn2 = t[j].c;
                p2 = j;
            }
            if (n / 2 > p) v[p1] = 0, v[p2] = 1;
        }
        s.clear();
        for (int i = 0; i < n; i++)
        if (v[i]) s.push_back(t[i].s);
        sort(s.begin(), s.end());
        printf("Case #%d:", cas);
        for (int i = 0; i < (int)s.size(); i++)
            cout << " " << s[i];
        puts("");
    }
}

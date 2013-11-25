#include <bits/stdc++.h>
#ifdef LOCAL
#include "local.h"
#endif

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }

void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


typedef pair<pint, char*> A; // (time, draft, name)
void go(vector<A>& a, vector<A>& x, int p, int m, vector<string>& res)
{
    if (a.size() > p)
    {
        while (a.size() > p)
        {
            x.push_back(a.back());
            a.pop_back();
        }
        rep(t, m)
        {
            for (auto& i : a)
                i.first.first++;
            if (!x.empty())
                swap(*max_element(all(a)), *min_element(all(x)));
        }
    }
    for (auto& i : a)
        res.push_back(i.second);
}
int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        int n, m, p;
        cin >> n >> m >> p;
        char name[33][33];
        vector<pair<pint, char*>> rate;
        rep(i, n)
        {
            int shot, height;
            cin >> name[i] >> shot >> height;
            rate.push_back(mp(pint(shot, height), name[i]));
        }
        sort(all(rate));
        reverse(all(rate));

        vector<A> a, b;
        vector<A> x, y;
        rep(i, n)
            (i % 2 ? a : b).push_back(A(pint(0, i), rate[i].second));

        vector<string> play;
        go(a, x, p, m, play);
        go(b, y, p, m, play);
        sort(all(play));

        string res = play[0];
        for (int i = 1; i < play.size();i ++)
            res += " " + play[i];
        printf("Case #%d: %s\n", C, res.c_str());
    }
}

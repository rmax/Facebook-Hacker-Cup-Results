#include <iostream>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Point {
    int x, y, z;
    Point () : x(0), y(0), z(0) {
    }
    Point (int x, int y, int z) : x(x), y(y), z(z) {
    }
};
struct ScoredPoint {
    Point p;
    int dist;
    ScoredPoint(Point p, int dist) : p(p), dist(dist) {
    }
};
struct Compare {
    bool operator()(const ScoredPoint &s1, const ScoredPoint &s2) {
        return s1.dist > s2.dist;
    }
};

#define MAX 1000
#define STEP 10
#define KEEP 5000
#define SEARCH 10
Point points[200];
int n;
int score(int x, int y, int z, int thresh=-1) {
    int rtn = 1000000000;
    for (int i = 0; i < n; i++) {
        Point &p = points[i];
        int d = (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z);
        rtn = min(rtn, d);
        if (rtn < thresh)
            return rtn;
    }
    return rtn;
}
int main() {
    int t;
    cin >> t;
    for (int _t = 0; _t < t; _t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y >> points[i].z;
        }
        priority_queue<ScoredPoint, vector<ScoredPoint>, Compare> pq;
        int thresh = -1;
        for (int x = 0; x < MAX; x+= STEP) {
        for (int y = 0; y < MAX; y+= STEP) {
        for (int z = 0; z < MAX; z+= STEP) {
            int d = score(x, y, z, thresh);
            pq.push(ScoredPoint(Point(x, y, z), d));
            //printf("Scored %d\n", d);
            if (pq.size() > KEEP) {
                //ScoredPoint sp = pq.top();
                //printf("popped %d\n", sp.dist);
                thresh = pq.top().dist;
                pq.pop();
            }
        }
        }
        }
        int best = -1;
        while (pq.size()) {
            ScoredPoint sp = pq.top();
            pq.pop();
            for (int x = sp.p.x-SEARCH; x <= sp.p.x+SEARCH; x++) {
                if (x < 0 || x > MAX)
                    continue;
            for (int y = sp.p.y-SEARCH; y <= sp.p.y+SEARCH; y++) {
                if (y < 0 || y > MAX)
                    continue;
            for (int z = sp.p.z-SEARCH; z <= sp.p.z+SEARCH; z++) {
                if (z < 0 || z > MAX)
                    continue;
                int d = score(x, y, z, best);
                if (d > best) {
                    //printf("%d %d %d: %d\n", x, y, z, d);
                    best = d;
                }
            }
            }
            }
        }
        printf("%d\n", best);
        fflush(stdout);
    }
    return 0;
}

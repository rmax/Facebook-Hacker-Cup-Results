#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <cmath>

#define EPS 1e-9

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

using namespace std;

inline int cmpf(double a, double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

struct cmp {
    bool operator()(double a, double b) {
        return cmpf(a,b) < 0;
    }
};

int C=1, T, k;
double ps, pr, pi, pu, pw, pd, pl;
map<double, double, cmp> PD[128][128];
map<double, double, cmp>::iterator PDi;

double calc(int eu, int ele, double psol) {
    if (eu==k) return 1.0;
    if (ele==k) return 0.0;
    psol = max(psol,0.0); psol = min(psol,1.0);

    PDi = PD[eu][ele].find(psol);
    if (PDi != PD[eu][ele].end())
        return PDi->second;

    double pganha = psol*ps + (1.0-psol)*pr;

    double soma = 0.0;
    soma += pganha*pw*calc(eu+1,ele,psol+pu);
    soma += pganha*(1.0-pw)*calc(eu+1,ele,psol);
    soma += (1.0-pganha)*pl*calc(eu,ele+1,psol-pd);
    soma += (1.0-pganha)*(1.0-pl)*calc(eu,ele+1,psol);

    PD[eu][ele][psol] = soma;
    return soma;
}

int main() {

    for(scanf("%d",&T);T--;) {
        printf("Case #%d: ",C++);
        scanf("%d",&k);
        for (int i=0;i<k+3;i++)
            for (int j=0;j<k+3;j++)
                PD[i][j].clear();
        scanf("%lf %lf %lf %lf %lf %lf %lf",&ps,&pr,&pi,&pu,&pw,&pd,&pl);
        printf("%.6lf\n",calc(0,0,pi));
    }

    return 0;
}

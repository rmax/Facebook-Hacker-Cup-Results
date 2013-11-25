#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int t, k;
double ps, pr, pi, pu, pw, pd, pl;
map<double, double> m[101][101];

void init() {
    for (int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j)
            m[i][j].clear();
    m[0][0][pi] = 1.0;
}

double pPlus(double p, double c) {
    p += c;
    if (p > 1.0) return 1.0;
    return p;
}

double pMinus(double p, double c) {
    p -= c;
    if (p < 0.0) return 0.0;
    return p;
}

double probWin(double pSun) {
    return pSun * ps + (1.0 - pSun) * pr;
}

void addProb(int wins, int loses, double pSun, double pAdd) {
    if (m[wins][loses].find(pSun) == m[wins][loses].end()) {
        if (pAdd > 0.0) m[wins][loses][pSun] = pAdd;
    }
    else m[wins][loses][pSun] += pAdd;
}

void solveTest(int testNumber) {
    double result = 0.0, d, p;
    int wins, loses;
    cin >> k >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
    init();
    for (int games = 1; games < 2*k; ++games) {
        if (games < k) wins = 0;
        else wins = games - k + 1;
        loses = games - wins;
        while (wins <= k && loses >= 0) {
            if (wins > 0 && loses < k) {
                for (map<double, double>::iterator it = m[wins - 1][loses].begin(); it != m[wins - 1][loses].end(); ++it) {
                    p = probWin(it->first);
                    addProb(wins, loses, it->first, it->second * (1.0 - pw) * p);
                    d = pPlus(it->first, pu);
                    addProb(wins, loses, d, it->second * pw * p);
                }
            }
            if (loses > 0 && wins < k) {
                for (map<double, double>::iterator it = m[wins][loses - 1].begin(); it != m[wins][loses - 1].end(); ++it) {
                    p = 1.0 - probWin(it->first);
                    addProb(wins, loses, it->first, it->second * (1.0 - pl) * p);
                    d = pMinus(it->first, pd);
                    addProb(wins, loses, d, it->second * pl * p);
                }
            }
            ++wins;
            --loses;
        }
    }
    result = 0.0;
    for (loses = 0; loses < k; ++loses) {
        for (map<double, double>::iterator it = m[k][loses].begin(); it != m[k][loses].end(); ++it)
            result += it->second;
    }
    cout << "Case #" << testNumber << ": " << result << endl;
}

int main() {
    cout << fixed << setprecision(6);
    cin >> t;
    for (int i = 1; i <= t; ++i) solveTest(i);
    return 0;
}

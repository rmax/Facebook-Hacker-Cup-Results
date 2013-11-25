#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#include <cassert>
#include <map>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define foreach(it, c) for(typeof(c.begin()) it = c.begin();it != c.end();it++)
#define contains(x, c) (c.find(x) != c.end())


struct stateGivenResult {
	double sunnyProb;
	bool win;
	stateGivenResult(double s, bool w) {
		if (!(0 <= sunnyProb && sunnyProb <= 1)) {
			//cout << sunnyProb << endl;
		}
		sunnyProb = s; win = w;}
	stateGivenResult(){}
};

bool operator<(const stateGivenResult& a, const stateGivenResult& b) {
	return (a.sunnyProb < b.sunnyProb || (a.sunnyProb == b.sunnyProb && a.win < b.win));
}

map<stateGivenResult, double> dp[128][128];

int K;
double sunnyWin, rainingWin, firstSetSun, increasingSunValue, increasingSunProb, decreasingSunValue, decreasingSunProb;

int main() {
	int casos; cin >> casos;
	forsn(caso, 1, casos + 1) {
		cin >> K >> sunnyWin >> rainingWin >> firstSetSun >> increasingSunValue >> increasingSunProb >> decreasingSunValue >> decreasingSunProb;
		
		forn(i,K + 3) forn(j,K + 3) dp[i][j].clear();
		
		dp[1][0][stateGivenResult(firstSetSun, 1)] = max(0.0,min(1.0,sunnyWin * firstSetSun * (1 - increasingSunProb) + rainingWin * (1 - firstSetSun) * (1 - increasingSunProb)));
		dp[1][0][stateGivenResult(min(1.0,firstSetSun + increasingSunValue), 1)] = max(0.0,min(1.0,sunnyWin * firstSetSun * increasingSunProb + rainingWin * (1 - firstSetSun) * increasingSunProb));
		dp[0][1][stateGivenResult(firstSetSun, 0)] = max(0.0,min(1.0,(1 - sunnyWin) * firstSetSun * (1 - decreasingSunProb) + (1 - rainingWin) * (1 - firstSetSun) * (1 - decreasingSunProb)));
		dp[0][1][stateGivenResult(max(0.0, firstSetSun - decreasingSunValue), 0)] = max(0.0,min(1.0,(1 - sunnyWin) * firstSetSun * decreasingSunProb + (1 - rainingWin) * (1 - firstSetSun) * decreasingSunProb));
		//if (caso != 2) continue;
		forsn(size, 1, 2 * K) {
			forn(mygames, min(K + 1, size + 1)) {
				if ((mygames >= K) || ((size - mygames) >= K)) continue;
				foreach(it, dp[mygames][size - mygames]) {
					stateGivenResult currentState = it->first;
					double currentProb = it->second;
					
					//A donde nos podemos mover desde el estado actual?
					///Podemos ganar, siendo un sunny day, y que suba la probabilidad de sunniedad
					stateGivenResult nuevoEstado = stateGivenResult(min(1.0, currentState.sunnyProb + increasingSunValue), 1);
					double nuevaProb = currentProb * sunnyWin * currentState.sunnyProb * increasingSunProb;
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames + 1][size - mygames])) {
							dp[mygames + 1][size - mygames][nuevoEstado] = 0;
						}
						dp[mygames + 1][size - mygames][nuevoEstado] += nuevaProb;
					}
					///Podemos ganar, siendo un sunny day, y que se mantenga la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(currentState.sunnyProb, 1);
					nuevaProb = currentProb * sunnyWin * currentState.sunnyProb * (1 - increasingSunProb);
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames + 1][size - mygames])) {
							dp[mygames + 1][size - mygames][nuevoEstado] = 0;
						}
						dp[mygames + 1][size - mygames][nuevoEstado] += nuevaProb;
					}
					///Podemos ganar, siendo un rainy day, y que suba la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(min(1.0, currentState.sunnyProb + increasingSunValue), 1);
					nuevaProb = currentProb * rainingWin * (1 - currentState.sunnyProb) * increasingSunProb;
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames + 1][size - mygames])) {
							dp[mygames + 1][size - mygames][nuevoEstado] = 0;
						}
						dp[mygames + 1][size - mygames][nuevoEstado] += nuevaProb;
					}
					///Podemos ganar, siendo un rainy day, y que se mantenga la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(currentState.sunnyProb, 1);
					nuevaProb = currentProb * rainingWin * (1 - currentState.sunnyProb) * (1 - increasingSunProb);
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames + 1][size - mygames])) {
							dp[mygames + 1][size - mygames][nuevoEstado] = 0;
						}
						dp[mygames + 1][size - mygames][nuevoEstado] += nuevaProb;
					}
					///Podemos perder, siendo un sunny day, y que se mantenga la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(currentState.sunnyProb, 0);
					nuevaProb = currentProb * (1 - sunnyWin) * currentState.sunnyProb * (1 - decreasingSunProb);
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames][size - mygames + 1])) {
							dp[mygames][size - mygames + 1][nuevoEstado] = 0;
						}
						dp[mygames][size - mygames + 1][nuevoEstado] += nuevaProb;
					}
					///Podemos perder, siendo un sunny day, y que baje la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(max(0.0, currentState.sunnyProb - decreasingSunValue), 0);
					nuevaProb = currentProb * (1 - sunnyWin) * currentState.sunnyProb * decreasingSunProb;
					
					if(nuevaProb > 0){
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames][size - mygames + 1])) {
							dp[mygames][size - mygames + 1][nuevoEstado] = 0;
						}
						dp[mygames][size - mygames + 1][nuevoEstado] += nuevaProb;					
					}
					///Podemos perder, siendo un rainy day, y que se mantenga la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(currentState.sunnyProb, 0);
					nuevaProb = currentProb * (1 - rainingWin) * (1 - currentState.sunnyProb) * (1 - decreasingSunProb);
					
					if(nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames][size - mygames + 1])) {
							dp[mygames][size - mygames + 1][nuevoEstado] = 0;
						}
						dp[mygames][size - mygames + 1][nuevoEstado] += nuevaProb;					
					}
					///Podemos perder, siendo un rainy day, y que baje la probabilidad de sunniedad
					nuevoEstado = stateGivenResult(max(0.0, currentState.sunnyProb - decreasingSunValue), 0);
					nuevaProb = currentProb * (1 - rainingWin) * (1 - currentState.sunnyProb) * decreasingSunProb;
					if (nuevaProb > 0) {
						nuevaProb = min(1.0, nuevaProb);
						if (!contains(nuevoEstado, dp[mygames][size - mygames + 1])) {
							dp[mygames][size - mygames + 1][nuevoEstado] = 0;
						}
						dp[mygames][size - mygames + 1][nuevoEstado] += nuevaProb;					
					}
				}
			}
		}
		
		
		
		//foreach(it, dp[2][1]) {
			//cout << it->first.sunnyProb << ' ' << it->first.win << ' ' << it->second << endl;
		//}
		
		double total = 0;
		forn(i, K) {
			foreach(it, dp[K][i]) {
				if (it->first.win) {
					total += it->second;
				}
			}
		}
		
		//cout << "Case #" << caso d<< ": " << total << endl;
		printf("Case #%d: %.6lf\n", caso, total);
	}
}

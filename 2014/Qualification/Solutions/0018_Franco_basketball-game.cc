#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

#define forsn(i,s,n) for(int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define foreach(it, c) for(typeof(c.begin()) it = c.begin();it != c.end();it++)
#define contains(x, c) (c.find(x) != c.end())

struct player {
	string name;
	int shots;
	int height;
	int minutesPlayed;
	int casaca;
	
	player(string a, int b, int c) {
		name = a; shots = b; height = c; minutesPlayed = 0;
	}
	player(){}
};

bool menor(const player& a, const player& b) {
	return (a.shots > b.shots || (a.shots == b.shots && a.height > b.height));
}

bool operator<(const player& a, const player& b) {
	if (a.minutesPlayed == b.minutesPlayed) {
		return a.casaca < b.casaca;
	} else {
		return a.minutesPlayed < b.minutesPlayed;
	}
}

vector<player> todos;
vector<player> equipo[2];
vector<player> enCancha[2];

bool operator==(const player& a, const player& b) {
	return a.casaca == b.casaca;
}

bool otroComparador(const player& a, const player& b) {
	forn(j,2) forn(i, enCancha[j].size()) {
		if (enCancha[j][i] == a) return (2 < 1);
		if (enCancha[j][i] == b) return (1 < 2);
	}
	return a < b;
}

bool comparadorPorNombre(const player& a, const player& b) {
	return a.name < b.name;
}

int main() {
	int casos; cin >> casos;
	forsn(caso, 1, casos + 1) {
		todos.clear();
		forn(i,2) {
			equipo[i].clear();
			enCancha[i].clear();
		}
		
		int n, m, p; cin >> n >> m >> p;
		assert(2 * p <= n);
		forn(i,n) {
			player p; cin >> p.name >> p.shots >> p.height; todos.push_back(p);
		}
		sort(todos.begin(), todos.end(), menor);
		forn(i, todos.size()) {
			todos[i].casaca = i;
			equipo[i % 2].push_back(todos[i]);
		}
		
		forn(i,p) forn(j,2) enCancha[j].push_back(equipo[j][i]);
		
		forn(i,m) {
			//if (caso == 2) cout << endl;
			forn(k, 2) forn(j, p) {
				//if (caso == 2) if (!j) cout << endl;
				enCancha[k][j].minutesPlayed++;
				equipo[k][enCancha[k][j].casaca / 2].minutesPlayed++;
				//if (caso == 2) cout << enCancha[k][j].name << ' ' ;
			}
			//if (caso == 2) cout << endl;
			forn(j,2) {
				player aEntrar = *min_element(equipo[j].begin(), equipo[j].end(), otroComparador);
				player aSalir = *max_element(enCancha[j].begin(), enCancha[j].end());
				//if (caso == 2) cout << "SALEEEE " << aSalir.name << " CON " << aSalir.minutesPlayed << " MINUTOS!" << endl;
				enCancha[j][distance(enCancha[j].begin(), max_element(enCancha[j].begin(), enCancha[j].end()))] = aEntrar;
			}
			
		}
		//cout << endl << "===================" << endl;
		//sort(enCancha[j].begin(), enCancha[j].end(), comparadorPorNombre);
		vector<string> todosEnCancha; forn(j,2) forn(k,p) todosEnCancha.push_back(enCancha[j][k].name);
		sort(all(todosEnCancha));
		//if (caso != 2) continue;
		cout << "Case #" << caso << ":";
		forn(j,2 * p) cout << ' ' << todosEnCancha[j];
		cout << endl;
		//cout << "======================================================" << endl;
	}
}

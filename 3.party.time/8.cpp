#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

typedef long long ll;

// Debugging
string ToString(char ch) {string s = "?"; s[0] = ch; return s;}
string ToString(double r) {ostringstream out; out << r; return out.str();}
string ToString(float r) {ostringstream out; out << r; return out.str();}
string ToString(int n) {ostringstream out; out << n; return out.str();}
string ToString(ll n) {ostringstream out; out << n; return out.str();}
string ToString(const string& s) {return s;}
template <class S, class T>
string ToString(const map<S,T>& m, const string& d = ", ") {
  string x = "{";
  for (typename map<S,T>::const_iterator it = m.begin(); it != m.end(); ++it)
    x += (it == m.begin()? "": d) +
      (ToString(it->first) + "->" + ToString(it->second));
  return x + "}";
}
template <class T> string ToString(const set<T>& s, const string& d = ", ") {
  string x = "{";
  for (typename set<T>::const_iterator it = s.begin(); it != s.end(); ++it)
    x += (it == s.begin()? "": d) + ToString(*it);
  return x + "}";
}
template <class T> string ToString(const vector<T>& v, const string& d = ", ") {
  string x = "(";
  for (int i = 0; i < v.size(); ++i) x += (i == 0? "": d) + ToString(v[i]);
  return x + ")";
}

void Preprocess();
void SolveCase(int tc);

int main() {
  cout << "Preprocessing..." << endl;
  Preprocess();
  int test_cases;
  in >> test_cases;
  for (int tc = 1; tc <= test_cases; ++tc) {
    cout << "Solving test case " << tc << " of " << test_cases << "..." << endl;
    SolveCase(tc);
  }

  int c = clock();
  cout << (1.0 * clock()) / CLOCKS_PER_SEC << " seconds." << endl << endl;
  return 0;
}

////////////////////////////////////////////////////////////////////////////////

const int kInfinity = 123456789;
const int kMult = 500;

int N, M, F;
vector<int> cost;
vector<vector<int> > best;
vector<vector<int> > path_cost;

void Preprocess() {}

void Solve(int bm) {
  for (int i = 0; i < 11; ++i) {
    if (bm == (1 << i)) {
      for (int node = 0; node < N; ++node) {
	best[bm][node] = path_cost[node][i];
      }
    }
  }

  for (int j = 0; j < bm; ++j) {
    if ((bm & j) == j) {
      for (int node = 0; node < N; ++node) {
	best[bm][node] = 
	  min(best[bm][node],
	      best[j][node] + best[bm-j][node] - cost[node]);
      }
    }
  }

  for (int node = 0; node < N; ++node) {
    for (int node2 = 0; node2 < N; ++node2) {
      best[bm][node] =
	min(best[bm][node],
	    best[bm][node2] + path_cost[node][node2] - cost[node2]);
    }
  }
}

void SolveCase(int tc) {
  in >> N >> F >> M;

  vector<int> friend1(M), friend2(M);
  cost = vector<int>(N);
  for (int i = 0; i < M; ++i) in >> friend1[i] >> friend2[i];
  for (int i = 0; i < N; ++i) {
    in >> cost[i];
    cost[i] = cost[i] * kMult + 1;
  }

  path_cost = vector<vector<int> >(N, vector<int>(N, kInfinity));
  for (int i = 0; i < N; ++i) {
    path_cost[i][i] = cost[i];
  }
  for (int i = 0; i < M; ++i) {
    int f1 = friend1[i], f2 = friend2[i];
    path_cost[f1][f2] = cost[f1] + cost[f2];
    path_cost[f2][f1] = cost[f1] + cost[f2];
  }

  for (int j = 0; j < N; ++j) {
    for (int i = 0; i < N; ++i) {
      for (int k = 0; k < N; ++k) {
	int pc2 = path_cost[i][j] + path_cost[j][k] - cost[j];
	if (pc2 < path_cost[i][k]) path_cost[i][k] = pc2;
      }
    }
  }

  best = vector<vector<int> >(2048, vector<int>(N, kInfinity));
  int fbm = (1 << F) - 1;
  for (int i = 1; i <= fbm; ++i) {
    Solve(i);
  }

  int real_best = kInfinity;
  for (int i = 0; i < N; ++i) real_best = min(real_best, best[fbm][i]);

  int min_cost = real_best / kMult;
  int min_guys = real_best % kMult;
  out << min_cost << " " << min_guys << endl;
}

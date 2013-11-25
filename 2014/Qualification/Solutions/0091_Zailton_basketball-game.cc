#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>	// srand( time(NULL) )
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>

using namespace std;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) for(int i = 0; i < a; ++i)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define sz(A) int((A).size())
#define CLR(x, a) memset(x, a, sizeof(x))
#define pb push_back
#define mp make_pair

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}

#define person pair < ii, string >

bool ord (person i1, person i2) {
	return i1.first.first > i2.first.first || (i1.first.first==i2.first.first && i1.first.second > i2.first.second); 
}

int main (){
	int T, N, M, P;
	cin >> T;
	FORR (c, T){
		cin >> N >> M >> P;
		vector<person> vec, vec1, vec2;
		vector<ii> in1, in2, out1, out2;
		FORR (i, N){
			string name;
			int sp, h;
			cin >> name >> sp >> h;
			person p ( ii (sp, h), name );
			vec.pb (p);
		}
		sort (all (vec), ord);		
		FORR (i, N){
			if (i&1) 
				vec1.pb(vec[i]);
			else
				vec2.pb(vec[i]);
		}
		FORR (i, 2*P){
			if (i&1)
				in1.pb (ii (0, i));
			else
			 	in2.pb (ii (0, i));
		}
		FOR (i, 2*P, N){
			if (i&1)
				out1.pb (ii (0, i));
			else
				out2.pb (ii (0, i));
		}

		FORR (i, M){
			if (2*P==N) break;
			FORR (j, P){
				in1[j].first++;
				in2[j].first++;
			}
			ii p = out1[0];
			out1.erase (out1.begin());
			out1.pb (in1[P-1]);
			in1.erase (in1.begin()+P-1);
			in1.pb (p);

			p = out2[0];
			out2.erase (out2.begin());
			out2.pb (in2[P-1]);
			in2.erase (in2.begin()+P-1);
			in2.pb (p);
	
			sort (all (in1));
			sort (all (in2));
			sort (all (out1));
			sort (all (out2));
		}
		
		vector<string> final;
		FORR (i, P) {
			final.pb (vec[in1[i].second].second);
			final.pb (vec[in2[i].second].second);
		}
		sort (all(final));
		cout << "Case #" << (c+1) << ":";
		FORR (i, sz(final)){
			cout << " " << final[i];
		}
		cout << endl;
		/*FORR (i, N)
			cout << vec[i].second << " ";
		cout << endl;
		int x = 2*M;
		vector<string> final;
		FORR (i, 2*P){
			final.pb (vec[(i+x)%N].second);
		}
		sort (all(final));
		cout << "Case #" << (c+1) << ":";
		FORR (i, sz(final)){
			cout << " " << final[i];
		}
		cout << endl;*/
	}
}

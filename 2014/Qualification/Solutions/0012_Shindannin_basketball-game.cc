#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <stdio.h>
#include <string.h>
#include <assert.h>

using namespace std;
static const double EPS = 1e-9;
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }
#define PI	(acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG (123456789)
#define BIGBIG (987654321987654321LL)
#define SZ(a) ((int)((a).size()))
#define SQ(a) ((a)*(a))
typedef long long ll;
typedef unsigned long long ull;

#define FOR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
// BEGIN CUT HERE
#undef FOR
#define FOR(v,i) for(auto i=(v).begin();i!=(v).end();++i)
// END CUT HERE


#if 1


int main()
{
	int T;
	cin >> T;

	//FILE *fp = fopen("_google_code_jam_output.txt","w");
	FILE *fp = stdout;

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N,M,P;
		cin >> N >> M >> P;
		vector < pair <pair <int, int>, string > > players; // percen
		for (int i = 0; i < N; i++)
		{
			string name;
			int shot, height;
			cin >> name >> shot >> height;

			players.push_back(make_pair(make_pair(shot,height),name));
		}

		sort(players.rbegin(),players.rend());

		vector < pair < pair < int, int > , string > > field[2];	// totaltime, draft
		vector < pair < pair < int, int > , string > > bench[2];	// totaltime, draft

		for (int i = 0; i < N; i++)
		{
			int team = i%2;
			pair < pair < int, int > , string > player = make_pair(make_pair(0,i+1),players[i].second);
			if(SZ(field[team])<P)
			{
				field[team].push_back(player);
			}
			else
			{
				bench[team].push_back(player);
			}
		}

		for (int time = 0; time < M; time++)
		{
			for (int team = 0; team < 2; team++)
			{
				for (int i = 0; i < SZ(field[team]); i++)
				{
					field[team][i].first.first++;
				}

				if(SZ(bench[team])>0)
				{
					sort(field[team].rbegin(),field[team].rend());
					sort(bench[team].begin(),bench[team].end());
					swap(field[team][0],bench[team][0]);
				}
			}
		}

		vector <string> allfielders;
		for (int team = 0; team < 2; team++)
		{
			for (int i = 0; i < SZ(field[team]); i++)
			{
				allfielders.push_back(field[team][i].second);
			}
		}

		sort(allfielders.begin(),allfielders.end());

		fprintf(fp,"Case #%d:",testcase+1);
		for (int i = 0; i < SZ(allfielders); i++)
		{
			fprintf(fp," %s",allfielders[i].c_str());
		}
		fprintf(fp,"\n");
	}

	fclose(fp);

	return 0;
}


#else

int main()
{
	int T;
	cin >> T;

	FILE *fp = fopen("_google_code_jam_output.txt","w");

	for (int testcase = 0; testcase < T; testcase++)
	{
		int N;
		cin >> N;
		vector <string> field;
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			field.push_back(s);

		}

		bool yes = false;

		for (int ly = 0; ly < N; ly++)
		{
			for (int lx = 0; lx < N; lx++)
			{
				for (int h = 1; h+ly <= N && h+lx<= N; h++)
				{
					int w = h;
					bool ok = true;

					for (int y = 0; y < N; y++)
					{
						for (int x = 0; x < N; x++)
						{
							if(INRANGE(y,ly,ly+h-1)&&INRANGE(x,lx,lx+w-1) && field[y][x]!='#')
							{
								ok = false;
							}
							if( !(INRANGE(y,ly,ly+h-1)&&INRANGE(x,lx,lx+w-1)) && field[y][x]=='#')
							{
								ok = false;
							}

						}
					}

					if(ok)
					{
						yes = true;
					}
				}
			}
		}


		fprintf(fp,"Case #%d: %s\n",testcase+1,yes?"YES":"NO");
	}
	
	fclose(fp);

	return 0;
}

#endif

#include <iostream>
#include <ctime>
#include <cstdio>
#include <vector>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <cassert>
#include <set>
#include <complex>
#include <iomanip>

using namespace std;

char line[30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC; ++tc)
	{
		int N;
		cin >> N;
		int mai = 0 , mii = N , mij = N , maj = 0 , cnt = 0;
		for(int i = 0; i < N; ++i)
		{
			cin >> line;
			for(int j = 0; j < N; ++j)
				if(line[j] == '#')
				{
					mij = min(mij , j);
					maj = max(maj , j);
					mii = min(mii , i);
					mai = max(mai , i);
					cnt++;
				}
		}
		cout << "Case #" << tc << ": ";
		cout << ((mai-mii+1)==(maj-mij+1) && (mai-mii+1)*(maj-mij+1)  == cnt ? "YES": "NO") << endl;
	}

}






/*

7
1 1
2 2
3 1
4 1
5 1
6 1
8 3


5
4
..##
..##
....
....
4
..##
..##
#...
....
4
####
#..#
#..#
####
5
#####
#####
#####
#####
.....
5
#####
#####
#####
#####
#####




 */







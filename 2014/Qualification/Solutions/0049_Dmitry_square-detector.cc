#pragma comment (linker, "/STACK:268435456")
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <bitset>
#include <functional>
#include <complex>
#include <numeric>
#include <utility>
#include <cstdlib>

using namespace std;

string s[30];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tn;
    cin >> tn;
    for (int tc = 0; tc < tn; tc++)
    {
    	int n;
    	cin >> n;
    	for (int i = 0; i < n; i++)
    		cin >> s[i];
    	int cnt = 0;
    	int maxi = -1, maxj = -1, mini = n, minj = n;
    	for (int i = 0; i < n; i++)
    		for (int j = 0; j < n; j++)
    			if (s[i][j] == '#')
    			{
    				cnt++;
    				maxi = max(maxi, i);
    				mini = min(mini, i);
    				maxj = max(maxj, j);
    				minj = min(minj, j);
    			}
    	string result = (maxi - mini == maxj - minj && (maxi - mini + 1) * (maxj - minj + 1) == cnt) ? "YES" : "NO";
    	cout << "Case #" << tc + 1 << ": " << result << endl;
    }
    return 0;
}
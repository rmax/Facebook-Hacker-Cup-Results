#include <bits/stdc++.h>
using namespace std;

string a[55];
int n;

int checkSquare(int x, int y, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (x + i >= n || y + j >= n || a[x + i][y + j] == '.')
				return 0;
	return 1;
}

int main()
{
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	int test;
	cin >> test;
	for (int idTest = 1; idTest <= test; idTest++)
	{
		int black = 0, ans = -1;
		
		cin >> n;
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i];
			for (int j = 0; j < n; j++) black += a[i][j] == '#';
		}
		
		int k = int(sqrt(black));
		
		if (k * k == black)
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					if (a[i][j] == '#')
					{
						ans = checkSquare(i, j, k);
						break;
					}
				if (ans >= 0) break;
			}
		else ans = 0;
				
		cout << "Case #" << idTest << ": " << (ans ? "YES" : "NO") << endl;
	}
}

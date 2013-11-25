#include <iostream>
#include <cassert>
using namespace std;
int main()
{
	int n_cases;
	cin >> n_cases;
	for (int t = 0; t < n_cases; t++)
	{
		int n;
		cin >> n;
		int min_x = n, min_y = n;
		int max_x = -1, max_y = -1;
		int n_black = 0;
		for (int i = 0; i < n; i++)
		{
			string row;
			cin >> row;
			for (int j = 0; j < n; j++)
			{
				if (row[j] == '#')
				{
					n_black++;
					max_x = max(max_x, i);
					max_y = max(max_y, j);
					min_x = min(min_x, i);
					min_y = min(min_y, j);
				}
			}
		}
		assert(n_black > 0);
		bool is_quadratic = max_x - min_x == max_y - min_y;
		bool is_filled = n_black == (max_x - min_x + 1) * (max_y - min_y + 1);
		bool is_square = is_quadratic && is_filled;
		cout << "Case #" << t + 1 << ": " << (is_square ? "YES" : "NO") << endl;
	}
	return 0;
}

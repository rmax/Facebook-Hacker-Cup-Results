#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

char s[110000];
int main()
{
	int t,ii=0;
	int n,h1,h2,c1,c2;

	//freopen("square_detector.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int i,j,k;

	cin>>t;

	while(t--)
	{
		cin>>n;

		h1=c1=21000000,h2=c2=-21000000;

		int cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",s);
			for(j=0;s[j];j++)if(s[j]=='#')
				cnt++,h1=min(h1,i),c1=min(c1,j),h2=max(h2,i),c2=max(c2,j);
		}
		printf("Case #%d: ",++ii);
		if((h2-h1+1)*(c2-c1+1)==cnt&&h2-h1==c2-c1)
			puts("YES");
		else
			puts("NO");
	}
}

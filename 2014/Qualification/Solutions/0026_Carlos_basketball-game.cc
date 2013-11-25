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


typedef pair<int,int> PII;
typedef pair<PII,string> PPS;
PPS arr[50];
PPS T1[50];;
PPS T2[50];
int SZ1 , SZ2;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC; ++tc)
	{
		int N , M , P;
		cin >> N >> M >> P;
		for(int i = 0; i < N; ++i)
		{
			cin >> arr[i].second >> arr[i].first.first >> arr[i].first.second;
		}
		sort(arr,arr+N);
		reverse(arr,arr+N);
		SZ1 = SZ2 = 0;
		for(int i = 0; i < N; ++i)
		{
			if(i&1)
				T2[i/2] = arr[i] , SZ2++;
			else
				T1[i/2] = arr[i] , SZ1++;
		}
		reverse(T1,T1+P);
		reverse(T2,T2+P);
		vector<string> ANS;
		for(int i = M%SZ1 , j = 0 ; j < P; j++, i = (i+1)%SZ1)
			ANS.push_back(T1[i].second);
		for(int i = M%SZ2 , j = 0 ; j < P; j++, i = (i+1)%SZ2)
			ANS.push_back(T2[i].second);
		sort(ANS.begin(),ANS.end());
		
		cout << "Case #" << tc << ": ";
		for(int i = 0; i < 2*P; ++i)
			cout << ANS[i] << (i==2*P-1 ? "\n" : " ");
	}

}






/*
5
6 3 2
Wai 99 131
Weiyan 81 155
Lin 80 100
Purav 86 198
Slawek 80 192
Meihong 44 109
7 93 2
Paul 82 189
Kittipat 62 126
Thomas 17 228
Fabien 57 233
Yifei 65 138
Liang 92 100
Victor 53 124
6 62 3
Meihong 33 192
Duc 62 162
Wai 70 148
Fabien 19 120
Bhuwan 48 176
Vlad 30 225
8 59 3
Anil 38 180
Song 7 187
David 65 159
Lin 45 121
Ranjeeth 39 183
Torbjorn 26 181
Clifton 57 158
Phil 3 183
4 72 1
Anh 2 187
Erling 69 226
Purav 0 199
Zejia 29 163




 */







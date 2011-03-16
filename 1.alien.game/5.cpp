#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1ll<<60)

int N,P;
ll bound;
ll sum[2010];
ll a[3000000];

ll func(void){
	int sz=0,i,j;
	
	REP(j,N-1) REP(i,j){
		ll tmp = 0;
		if(i >= P || j < P){
			if(sum[i] < sum[j]) tmp = -INF; else tmp = INF;
		} else {
			tmp = sum[j] - sum[i] + 1;
		}
		a[sz] = tmp; sz++;
	}
	
	sort(a,a+sz); a[sz] = INF;
	
	ll ans = 0;
	for(i=0;i<sz;i+=2){
		ll low = a[i];
		ll high = a[i+1];
		low = max(low,0ll);
		high = min(high,bound+1);
		if(low <= high) ans += high - low;
	}
	
	return ans;
}

int main(void){
	int T,t,i;
	
	cin >> T;
	REP(t,T){
		cin >> N >> P; P--;
		REP(i,N){
			cin >> sum[i];
			if(i == P) bound = sum[i] * 2;
		}
		REP(i,N-1) sum[i+1] += sum[i];
		ll ans = func();
		cout << ans << endl;
	}
	
	return 0;
}

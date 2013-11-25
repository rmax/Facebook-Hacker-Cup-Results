#include <iostream>
#include <algorithm>
using namespace std;

long long times[4000000];

int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int N, P;
		cin >> N >> P;
		
		long long buckets[N];
		for (int i = 0; i < N; i++) cin >> buckets[i];
		long long F = buckets[P-1];
		buckets[P-1] = -F;
		for (int i = 1; i < N; i++) buckets[i] += buckets[i-1];
		
		int inversions = 0;
		for (int i = 0; i < N-1; i++)
			for (int j = i+1; j < N-1; j++)
				if (buckets[i] < buckets[j]) inversions++;
		
		int yes = (inversions%2);
		int number = 0;
		
		for (int i = 0; i < P-1; i++)
			for (int j = P-1; j < N-1; j++) {
				if (buckets[j]-buckets[i] <= 0 && 1-buckets[j]+buckets[i] <= 2*F) times[number++] = 1-buckets[j]+buckets[i];
			}
		
		sort(times, times+number);
		
		long long prev = 0;
		long long ans = 0;
		for (int i = 0; i < number; i++) {
			if (i < number-1 && times[i] == times[i+1]) {
				i++;
				continue;
			}
			
			ans += (times[i]-prev)*yes;
			prev = times[i];
			yes = !yes;
		}
		ans += (2*F+1-prev)*yes;
		cout << ans << '\n';
	}
	return 0;
}

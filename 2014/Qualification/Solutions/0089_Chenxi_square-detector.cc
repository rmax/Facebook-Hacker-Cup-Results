#include<iostream>
#include<cmath>
using namespace std;
string s[30];
int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, tt;
	cin>>tt;
	for (t = 0; t < tt; ++t){
		int n;
		cin>>n;
		//cout<<n<<endl;
		int cnt = 0;
		//int x, y;
		int maxx = 0;
		int minx = n;
		int maxy = 0;
		int miny = n;
		for (int i = 0; i < n; ++i){
			cin>>s[i];
			for (int j = 0; j < n; ++j){
				if (s[i][j] == '#'){
					++cnt;
					//x = i;
					//y = j;
					maxx = max(maxx, i);
					minx = min(minx, i);
					maxy = max(maxy, j);
					miny = min(miny, j);
				} 
			}
		}
		int k = 0; 
		for (; k <= n; ++k){
			if (k * k == cnt) break;
		}
		if (k * k != cnt){
			cout<<"Case #"<<t + 1<<": NO"<<endl;
			continue;
		}
		if (cnt == 0){
			cout<<"Case #"<<t + 1<<": YES"<<endl;
			continue;
		}
		//cout<<k<<endl;
		if ((minx + k - 1 != maxx)||(miny + k - 1 != maxy)){
			cout<<"Case #"<<t + 1<<": NO"<<endl;
			continue;
		}else 
			cout<<"Case #"<<t + 1<<": YES"<<endl;
			
		/*
		if ((x < n - 1)||(y < n - 1)){
			cout<<"Case #"<<t + 1<<": NO"<<endl;
			continue;
		}
		int out = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if ((s[x - i][y - j]) != '#') out = true;
		if (out){
			
			cout<<"Case #"<<t + 1<<": NO"<<endl;
			continue;
		}
		cout<<"Case #"<<t + 1<<": YES"<<endl;
		*/
	}	
}

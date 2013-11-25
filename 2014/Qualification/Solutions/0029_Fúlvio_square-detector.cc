#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){

	int t;
	cin>>t;
	int c = 1;
	while(t--){
		int n;
		cin>>n;
		char v[n+10][n+10];
		for(int i = 0;i<n;i++)scanf("%s",v[i]);
		int ip,jp;
		bool f = true;
		bool resp = true;
		for(int i = 0;i<n && f;i++)
			for(int j = 0;j<n && f;j++){
				if(v[i][j]=='#'){
					f = false;
					ip = i;
					jp = j;
				}
			}
		int qtd = 0;
		int i = ip;
		while(v[i++][jp]=='#')qtd++;
		for( i = ip;i<ip+qtd;i++){
			for(int j = jp;j<jp+qtd;j++){
				if(v[i][j] == '.')resp = false;
			}
		}
		
		for( i = 0;i<n;i++)
			for(int j = 0;j<n;j++){
				if(i>=ip && i<ip+qtd && j>=jp && j<jp+qtd)continue;
				if(v[i][j] == '#')resp = false;
			}
		cout<<"Case #"<<c++<<": ";
		if(!resp){cout<<"NO\n";}
		else cout<<"YES\n";
	}
	return 0;
}
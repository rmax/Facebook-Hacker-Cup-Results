#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

double func2(double x){
	if(x>=1)return 1.0;
	else if(x<=0)return 0.0;
	return x;
}
double ps, pr, pi, pu, pw, pd, pl;
double PD[201][1001][100];
int k;

double func(int partida,int probSol,int partidasGanhas){

	if(partidasGanhas == k) {
		return 1.0;
	} else if(partida == k+partidasGanhas+1) {
		return 0.0;
	}

	if(PD[partida][probSol][partidasGanhas]<0.0){
		double npi = probSol/1000.0;
		double ganharEssa = ((npi*ps) + ((1-npi)*pr));
		PD[partida][probSol][partidasGanhas] = (ganharEssa)*(pw*func(partida+1,round(func2(npi + pu)*1000),partidasGanhas+1) 
															+ (1-pw)*func(partida+1,probSol,partidasGanhas+1)) +

											 (1-ganharEssa)*(pl*func(partida+1,round(func2(npi - pd)*1000),partidasGanhas) 
											 				+ (1-pl)*func(partida+1,probSol,partidasGanhas));
		
	}
	return PD[partida][probSol][partidasGanhas];
}


int main(){
	int t, c = 1;
	cin>>t;
	while(t--){
		memset(PD,-17.9,sizeof(PD));
		cin>>k>>ps>>pr>>pi>>pu>>pw>>pd>>pl;
		printf("Case #%d: %.6lf\n",c++,func(1,pi*1000,0));
	}
	return 0;
}
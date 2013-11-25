#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cstring>
using namespace std;

int main(){

	int t;
	cin>>t;
	int c = 1;
	while(t--){
		vector<pair<int,pair<int,string> > > todos;
		int N,M,P;
		cin>>N>>M>>P;
		for(int i = 0;i<N;i++){
			string x;
			int a,b;
			cin>>x>>a>>b;
			todos.push_back(make_pair(a,make_pair(b,x)));
		}
		sort(todos.begin(), todos.end());
		reverse(todos.begin(), todos.end());
		vector<pair<int,pair<int,string> > > time1,time2;
		for(int i = 0;i<N;i++){
			if(i%2 == 0){
				time1.push_back(todos[i]);
			}else{
				time2.push_back(todos[i]);
			}
		}
		vector<pair<int,int> > sentados1,jogando1;
		vector<pair<int,int> > sentados2,jogando2;
		for(int i = 0;i<P;i++){
			jogando1.push_back(make_pair(0,i));
			jogando2.push_back(make_pair(0,i));
		}

		for(int i = P;i<time1.size();i++){
			sentados1.push_back(make_pair(0,i));
		}

		for(int i = P;i<time2.size();i++){
			sentados2.push_back(make_pair(0,i));
		}

		while(M--){
			vector<pair<int,int> > aux;
			for(int i = 0;i<jogando1.size();i++){
				pair<int,int> ax = jogando1[i];
				ax.first++;
				aux.push_back(ax);
			}
			sort(aux.begin(), aux.end());
			jogando1 = aux;
			sentados1.push_back(jogando1[jogando1.size()-1]);
			jogando1.pop_back();
			jogando1.push_back(sentados1[0]);
			sentados1.erase(sentados1.begin());
			sort(jogando1.begin(), jogando1.end());
			sort(sentados1.begin(), sentados1.end());

			vector<pair<int,int> > aux2;
			for(int i = 0;i<jogando2.size();i++){
				pair<int,int> ax = jogando2[i];
				ax.first++;
				aux2.push_back(ax);
			}
			sort(aux2.begin(), aux2.end());
			jogando2 = aux2;
			sentados2.push_back(jogando2[jogando2.size()-1]);
			jogando2.pop_back();
			jogando2.push_back(sentados2[0]);
			sentados2.erase(sentados2.begin());
			sort(jogando2.begin(), jogando2.end());
			sort(sentados2.begin(), sentados2.end());
		}
		std::vector<string> nomes;
		for(int i = 0;i<P;i++){
			nomes.push_back(time1[jogando1[i].second].second.second);
			nomes.push_back(time2[jogando2[i].second].second.second);
		}
		sort(nomes.begin(), nomes.end());
		cout<<"Case #"<<c++<<": ";
		for(int i = 0;i<nomes.size();i++)cout<<nomes[i]<<" ";
		cout<<endl;
	}
	return 0;
}
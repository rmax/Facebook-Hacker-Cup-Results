#include<cstring>
#include<functional>
#include<iostream>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

const int maxn = 100;

struct player {
  string name;
  int percentage;
  int height;
  int rank;
  int time;
} p[maxn];

bool operator<(player a, player b) {
  if(a.time != b.time) return a.time < b.time;
  else return a.rank < b.rank;
}

bool cmp(player a, player b) {
  if(a.percentage != b.percentage) return a.percentage > b.percentage;
  else return a.height > b.height;
}

int ntest;
int N, M, P;
bool online[maxn];

int main() {
  cin>>ntest;
  for(int test = 1; test <= ntest; test++) {
    cin>>N>>M>>P;
    for(int i=0; i<N; i++) {
      cin>>p[i].name>>p[i].percentage>>p[i].height;
      p[i].time = 0;
    }
    sort(p, p+N, cmp);
    for(int i=0; i<N; i++) {
      p[i].rank = i;
    }
    memset(online, 0, sizeof(online));
    for(int i=0; i<P*2; i++) online[i] = true;

    for(int t=1; t<=M; t++) {
      for(int i=0; i<N; i++) if(online[i]) p[i].time++;

      int IN = -1, OUT = -1;
      for(int i=0; i<N; i+=2) if(!online[i]) {
        if(IN == -1 || p[i] < p[IN]) IN = i; 
      }
      for(int i=0; i<N; i+=2) if(online[i]) {
        if(OUT == -1 || p[OUT] < p[i]) OUT = i; 
      }
      if(IN != -1 && OUT != -1) {
        online[IN] ^= 1; online[OUT] ^= 1;
      }

      IN = OUT = -1;
      for(int i=1; i<N; i+=2) if(!online[i]) {
        if(IN == -1 || p[i] < p[IN]) IN = i; 
      }
      for(int i=1; i<N; i+=2) if(online[i]) {
        if(OUT == -1 || p[OUT] < p[i]) OUT = i; 
      }
      if(IN != -1 && OUT != -1) {
        online[IN] ^= 1; online[OUT] ^= 1;
      }
    }

    printf("Case #%d: ", test);
    vector<string> output;
    for(int i=0; i<N; i++) if(online[i]) output.push_back(p[i].name);
    sort(output.begin(), output.end());
    for(int i=0; i<output.size(); i++) cout<<" "<<output[i];
    cout<<endl;
  }
  return 0;
}

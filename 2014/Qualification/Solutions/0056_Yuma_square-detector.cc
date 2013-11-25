#include<iostream>
using namespace std;

int t,n;
string g[30];

bool check(int y, int x, int len){
  for(int i=y;i<y+len;i++){
    for(int j=x;j<x+len;j++){
      if(g[i][j] == '.')return false;
    }
  }
  return true;
}

bool solve(){
  int num = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(g[i][j] == '#')num++;

  int len = 1;
  while(len*len<num)len++;
  if(len*len!=num)return false;

  for(int i=0;i+len<=n;i++){
    for(int j=0;j+len<=n;j++){
      if(check(i,j,len))return true;
    }
  }
  return false;
}

int main(){
  cin >> t;
  for(int test=1;test<=t;test++){
    cin >> n;
    for(int i=0;i<n;i++)cin >> g[i];

    cout << "Case #" << test << ": " << (solve()?"YES":"NO") << endl;
  }
}

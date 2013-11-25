#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

struct players{
  string name;
  int shot_percentage;
  int height;
  players(){}
  players( string n, int sp, int ht ){
    name = n;
    shot_percentage = sp;
    height = ht;
  }
  bool operator<( const players &other) const{
    if( shot_percentage != other.shot_percentage )
      return shot_percentage > other.shot_percentage;
    return height > other.height;
  }
};

struct teams{
  string name;
  int pos;
  int time_played;
  teams(){}
  teams( string n, int p, int tp ){
    name = n;
    pos = p;
    time_played = tp;
  }
  bool operator<( const teams &other ) const{
    if( time_played != other.time_played )
      return time_played > other.time_played;
    return pos > other.pos;
  }
};

struct bench{
  string name;
  int pos, time_played;
  bench(){}
  bench( string n, int p, int tp){
    name = n;
    pos = p;
    time_played = tp;
  }
  bool operator<( const bench &other ) const{
    if( time_played != other.time_played ) 
      return time_played < other.time_played;
    return pos < other.pos;
  }
};

vector < players > list_players;
set < teams > first_playing, second_playing;
set < bench > first_bench, second_bench;
char str[100];

void increaseTime(){
  vector < teams > fp, sp;
  for(set<teams>::iterator it = first_playing.begin(); it != first_playing.end(); it++){
    fp.push_back(*it);
  }
  for(set<teams>::iterator it = second_playing.begin(); it != second_playing.end(); it++){
    sp.push_back(*it);
  }
  first_playing.clear();
  second_playing.clear();
  for( int i = 0; i < (int)fp.size(); i++){
    fp[i].time_played++;
    first_playing.insert(fp[i]);
  }
  for( int i = 0; i < (int)sp.size(); i++){
    sp[i].time_played++;
    second_playing.insert(sp[i]);
  }
}

void play(){
  teams fp = *(first_playing.begin());
  teams sp = *(second_playing.begin());
  first_playing.erase(first_playing.begin());
  second_playing.erase(second_playing.begin());
  bench fb = *(first_bench.begin());
  bench sb = *(second_bench.begin());
  first_bench.erase(first_bench.begin());
  second_bench.erase(second_bench.begin());
  ////////////////
  first_playing.insert(teams(fb.name,fb.pos,fb.time_played));
  second_playing.insert(teams(sb.name,sb.pos,sb.time_played));
  first_bench.insert(bench(fp.name,fp.pos,fp.time_played));
  second_bench.insert(bench(sp.name,sp.pos,sp.time_played));
}

int main(){
  /*  freopen("basketball_game.txt","r",stdin);
      freopen("basketball_output.txt","w",stdout);*/
  int t;
  int tt = 1;
  scanf("%d", &t);
  while(t--){
    int N,M,P;
    scanf("%d %d %d", &N, &M, &P);
    list_players.clear();
    for( int i = 0; i < N; i++){
      int sp,ht;
      scanf(" %s %d %d", str, &sp, &ht);
      list_players.push_back(players(str,sp,ht));
    }
    sort(list_players.begin(), list_players.end());
    vector < teams > first_team, second_team;
    for( int i = 0; i < N; i++){
      if( i&1 ) {
	first_team.push_back(teams(list_players[i].name,i/2,0));
      }else {
	second_team.push_back(teams(list_players[i].name,i/2,0));
      }
    }
    first_playing.clear();
    second_playing.clear();
    first_bench.clear();
    second_bench.clear();
    for( int i = 0; i < (int)first_team.size(); i++){
      if( i < P ) first_playing.insert(first_team[i]);
      else{
	first_bench.insert(bench(first_team[i].name,first_team[i].pos,0));
      }
    }
    for( int i = 0; i < (int)second_team.size(); i++){
      if( i < P ) second_playing.insert(second_team[i]);
      else{
	second_bench.insert(bench(second_team[i].name,second_team[i].pos,0));
      }
    }
    for( int i = 0; i < M; i++){
      increaseTime();
      if( 2 * P < N ) play();
    }
    vector < string > playing;
    for( set<teams>::iterator it = first_playing.begin(); it != first_playing.end(); it++)
      playing.push_back(it->name);
    for( set<teams>::iterator it = second_playing.begin(); it != second_playing.end(); it++)
      playing.push_back(it->name);
    sort(playing.begin(), playing.end());
    printf("Case #%d:", tt++);
    for( int i = 0; i < (int)playing.size(); i++)
      printf(" %s", playing[i].c_str());
    printf("\n");
  }
  
  return 0;
}

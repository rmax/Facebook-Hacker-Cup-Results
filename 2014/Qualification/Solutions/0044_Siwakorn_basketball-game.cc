//
// friends.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Thursday, 21 November 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define MAXN 35

typedef struct node {
    string name;
    int height, shot;
    int play_time;
}Player;

Player players[MAXN];

bool cmp1(Player a, Player b){
    if(a.shot != b.shot) return a.shot > b.shot;
    return a.height > b.height;
}

void solve(){
    int N, M, P;
    scanf("%d %d %d", &N, &M, &P);
    for(int i = 0; i < N; i++ ){
        cin >> players[i].name >> players[i].shot >> players[i].height;
        players[i].play_time = 0;
    }
    sort(players, players + N, cmp1);
    vector<Player> team1;
    vector<Player> team2;
    for(int i = 0; i < N; i++ ){
        if((i % 2) == 0) team1.push_back(players[i]);
        else team2.push_back(players[i]);
    }
/*
    for(int i = 0; i < team1.size(); i++ ) cout << team1[i].name << endl;
    cout << endl;
    for(int i = 0; i < team2.size(); i++ ) cout << team2[i].name << endl;
*/

    // PII = (time, rank)
    priority_queue<PII, vector<PII>, greater<PII> > out1, out2;
    priority_queue<PII> in1, in2;
    for(int i = 0; i < team1.size(); i++ ) out1.push(PII(0, i));
    for(int i = 0; i < team2.size(); i++ ) out2.push(PII(0, i));
    PII a;
    for(int i = 0; i < P; i++ ){
        a = out1.top();
        out1.pop();
        in1.push(PII(a.first + 1, a.second));
        a = out2.top();
        out2.pop();
        in2.push(PII(a.first + 1, a.second));
    }
    for(int i = 0; i < M; i++ ){
        if(out1.size()){
            PII temp = in1.top();
            in1.pop();
            a = out1.top();
            out1.pop();
            vector<PII> tt;
            while(!in1.empty()) tt.push_back(in1.top()), in1.pop();
            out1.push(temp);
            for(int j = 0; j < tt.size(); j++ )
                in1.push(PII(tt[j].first + 1, tt[j].second));
            in1.push(PII(a.first + 1, a.second));
        }
        if(out2.size()){
            PII temp = in2.top();
            in2.pop();
            a = out2.top();
            out2.pop();
            vector<PII> tt;
            while(!in2.empty()) tt.push_back(in2.top()), in2.pop();
            out2.push(temp);
            for(int j = 0; j < tt.size(); j++ )
                in2.push(PII(tt[j].first + 1, tt[j].second));
            in2.push(PII(a.first + 1, a.second));
        }
    }
    vector<string> ans;
    while(in1.size()) ans.push_back(team1[in1.top().second].name), in1.pop();
    while(in2.size()) ans.push_back(team2[in2.top().second].name), in2.pop();
    sort(ans.begin(), ans.end());
    for(int i = 0; i < 2 * P; i++ )
        cout << " " << ans[i];
    cout << endl;
}

int main(){
    int test;
    scanf("%d", &test);
    for(int tt = 0; tt < test; tt++ ){
        printf("Case #%d:", tt + 1);
        solve();
    }
    return 0;
}

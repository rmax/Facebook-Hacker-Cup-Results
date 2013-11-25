#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
int p[33],h[33],team_order[33],cnt[33],draft[33];
bool in[33];
char name[33][22];
bool compare0(int x,int y){
    if(p[x]!=p[y])return p[x]>p[y];
    return h[x]>h[y];
}
bool compare_name(int x,int y){
    return strcmp(name[x],name[y])<0;
}
struct data1{
    int id;
    data1(int _id=0):id(_id){}
    bool operator<(const data1& b)const{
        if(cnt[id]!=cnt[b.id])return cnt[id]>cnt[b.id];
        return draft[id]>draft[b.id];
    }
};
struct data2{
    int id;
    data2(int _id=0):id(_id){}
    bool operator<(const data2& b)const{
        if(cnt[id]!=cnt[b.id])return cnt[id]<cnt[b.id];
        return draft[id]<draft[b.id];
    }
};
void print(vector<int>&res){
    sort(res.begin(),res.end(),compare_name);
    for(int i=0;i<(int)res.size();i++)printf(" %s",name[res[i]]);
    puts("");
}
int main(){
    int T,cs=0,N,M,P;
    scanf("%d",&T);
    while(T--){
        memset(cnt,0,sizeof(cnt));
        scanf("%d%d%d",&N,&M,&P);
        for(int i=0;i<N;i++)scanf("%s%d%d",name[i],&p[i],&h[i]);
        for(int i=0;i<N;i++)in[i]=false;
        printf("Case #%d:",++cs);
        for(int i=0;i<N;i++)team_order[i]=i;
        sort(team_order,team_order+N,compare0);
        for(int i=0;i<N;i++)draft[team_order[i]]=i+1;
        priority_queue<data1>heap1[2];
        priority_queue<data2>heap2[2];
        for(int i=0;i<N;i+=2)heap1[0].push(data1(team_order[i]));
        for(int i=1;i<N;i+=2)heap1[1].push(data1(team_order[i]));
        for(int i=0;i<P;i++){
            int tmp=heap1[0].top().id;
            in[tmp]=true;
            heap2[0].push(data2(tmp));
            heap1[0].pop();
            tmp=heap1[1].top().id;
            in[tmp]=true;
            heap2[1].push(data2(tmp));
            heap1[1].pop();
        }
        for(int round=1;round<=M;round++){
            data2 leave[2];
            //printf("round %d:\n",round);
            for(int i=0;i<2;i++){
                leave[i]=heap2[i].top();
                heap2[i].pop();
            }

            for(int i=0;i<N;i++)
                if(in[i])cnt[i]++;
            for(int i=0;i<2;i++){
                in[leave[i].id]=false;
                heap1[i].push(data1(leave[i].id));
            }
            data1 enter[2];
            for(int i=0;i<2;i++){
                enter[i]=heap1[i].top();
                in[enter[i].id]=true;
                heap1[i].pop();
                heap2[i].push(data2(enter[i].id));
            }
        }
        vector<int>res;
        for(int i=0;i<2;i++){
            while(!heap2[i].empty()){
                res.push_back(heap2[i].top().id);
                heap2[i].pop();
            }
        }
        print(res);
    }
    return 0;
}

//General Template 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <bitset> // bitset<N>, set, reset, flip, to_ulong
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORI(it,v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define MP(x,y) make_pair( (x), (y))
#define PB(x) push_back( x )

template<class T>void checkMin(T& r, T v){if(r>v)r=v;}
template<class T>void checkMax(T& r, T v){if(r<v)r=v;}

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;

struct Node{
    string name;
    int s;
    int h;    
    int id;
    
    bool operator < (const Node& nd)const{
        return s>nd.s || (s==nd.s && h > nd.h);
    }
};

Node nd[100];

int n,m,p;

int main()
{
    int t,cs=0;
    cin>>t;
    while(++cs <= t){
        cin>>n>>m>>p;
        FOR(i,n){
            cin>>nd[i].name>>nd[i].s>>nd[i].h;
        }
        sort(nd,nd+n);

        VS va,vb;
        FOR(i,n) if(i%2) va.PB( nd[i].name ); else vb.PB( nd[i].name );
        FOR(i,p/2){
            swap( va[i], va[p-1-i] );    
            swap( vb[i], vb[p-1-i] );    
        }
        
        int i = m % va.size();
        int j = m % vb.size();
        
        VS ans;
        while(p--){
            int ii = (i+p) % va.size();
            int jj = (j+p) % vb.size();    
            ans.PB( va[ii] );
            ans.PB( vb[jj] );
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d:",cs);
        FORI(it,ans)cout<<" "<<*it;
        cout<<endl;        
    }
   return 0;
}

// 1) for multi-input cases, don't forget to initialize
// 2) when you add a global variable LATTER, THEN add some intialization process
// 3) when you reuse a variable declared outside of current scope, be careful:
// scanf("%d",&ct); while(ct--) scanf("%d",&ct); // bug
// 4) when you read Row,Col, be careful about the order, and Row+1 or not
// 5) if everything seems OK, then check if undersanding the problem correctly
// 6) typo: i,j,k misuse(usually array index); a=b;(a==b;)
// 7) care about if( cond1 && cond2 || cond3 ... ), easy to forget some cases
// 8) input/output format
// after contest
// 9) for some state variables, when you change one part, do not forget change
// some other parts related to the current state, e.g. W=4, all perm. is 24, when
// W is not 4, all perm should be W! (rather than hard coded 24)
// 10) when processing two or more demisions, take the the order of i,j,k
// 11) take care of the correctness of each sub-method, e.g. there is bug in the 
//  fall(), left(), when you occur an empty cell, simple move the current empty one
// to the end is not enough, you still need to check again if the current is still 
// an empty cell (some non-empty cell is still existed after it), when move to the next step: ++i
// 12) try best to prove the correctness of greedy algorithm, before coding
// 13) when writing simulation program, give some consideration of how to print debug info
// 14) sync_with_stdio(false), will make the dbg confusing, since cout is not sync with putchar, puts

// Input and Output
//ifstream fin("input.txt");
//std::ios_base::sync_with_stdio(false);
//freopen("in.txt","r",stdin);
//freopen("ouput.txt","w",stdout);
//cout.precision(5); cout<<std::fixed; 

//priority_queue<int>pq; push,pop,top,empty//top is the largest, default: less<int>
//priority_queue<int, vector<int>, greater<int> > pq; // top is the smallest
//set<int> st; // st.being() -> st.end(), from smallest one to the largest one

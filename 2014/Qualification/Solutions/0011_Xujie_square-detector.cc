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


char mp[25][25];
int n;

bool check(int r1, int r2, int c1, int c2)
{
    if(r2-r1 != c2-c1)return false;
    
    for(int i=r1;i<=r2;++i)for(int j=c1;j<=c2;++j) if(mp[i][j]=='.')return false;
    return true;
}

int main()
{
    int t,cs=0;
    cin>>t;
    while(++cs <=t){
        cin>>n;
        
        int r1,r2,c1,c2;
        r1=c1=n;
        r2=c2=0;
        FOR(i,n)scanf("%s",mp[i]);
        FOR(i,n)FOR(j,n){
            if(mp[i][j]=='#'){
                checkMin(r1,i);
                checkMax(r2,i);
                checkMin(c1,j);
                checkMax(c2,j);
            }    
        }
        
        string s = "NO";
        if( check(r1,r2,c1,c2) ) s= "YES";
        cout<<"Case #"<<cs<<": "<<s<<endl;
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

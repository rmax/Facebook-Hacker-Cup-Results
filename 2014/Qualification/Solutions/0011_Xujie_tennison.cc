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

double dp[220][110][1100];
double ps,pr, pi, pu, pw, pd, pl;
int ipi, ipu, ipd;
int K;

int main()
{
    
    int t,cs=0;
    cin>>t;
    while(++cs <= t){
        memset(dp,0,sizeof(dp));
        cin >> K >> ps >> pr >> pi >> pu >> pw >> pd >> pl;
        
        ipi = (int)(pi*1000 + 0.1);
        ipu = (int)(pu*1000 + 0.1);
        ipd = (int)(pd*1000 + 0.1);
        
        dp[0][0][ipi]=1.0;
        FOR(i,2*K){
            for(int j = i-K+1;j<K;++j){
                if(j<0 || j>i)continue;
                
                for(int p=0;p<=1000;++p){
                    double cur = dp[i][j][p];
                    //if(cur<1e-9)continue;
                    
                    //printf("i=%d j=%d p=%d  win=%lf\n",i,j,p, dp[i][j][p]);

                    // win                    
                    double win = ps*(double)p*0.001+ pr*(1000-p)*0.001;
                    
                    int np = p+ipu > 1000 ? 1000 : p+ipu;
                    dp[i+1][j+1][np] += cur* win * pw;
                    dp[i+1][j+1][p ] += cur* win * (1.0-pw);
                    
                    // loose
                    np = p - ipd < 0 ? 0 : p-ipd;
                    dp[i+1][j][np] += cur* (1.0-win) * pl;
                    dp[i+1][j][p]  += cur* (1.0-win) * (1.0-pl);
                }
            }
        }        

        double ans=0;
        FOR(i,2*K)FOR(j,1001) ans += dp[i][K][j];
        printf("Case #%d: %.6lf\n",cs,ans);
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

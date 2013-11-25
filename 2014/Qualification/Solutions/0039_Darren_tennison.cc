//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;
const double PI = acos(-1);
/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */


int T;
int K;
double ps, pr, pi, pu, pw, pd, pl;
double dp[256][1024][128];
int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &T);
  while (T--){
    scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
    memset(dp, 0, sizeof(dp));
    //cout<< pi * 1000 << endl;
    dp[0][(int)round(pi*1000)][0] = 1;
    //cout << dp[0][(int)round(pi*1000)][0] << endl;
    double ans = 0;
    for (int turn = 0; turn <= 2 * K; turn++){
      for (int pro = 0; pro <= 1000; pro++){
        for (int win = 0; win <= K; win++){
          double &cur = dp[turn][pro][win];
          if (cur == 0) continue;
          //printf("%d %d %d: %lf\n", turn, pro, win, cur);
          if (win == K){
            ans += cur;
            cur = 0;
            continue;
          }else if (turn - win == K){
            cur = 0;
            continue;
          }
          int winNextPro = min(pro + (int)round(pu * 1000), 1000);
          double winPro = cur * pro / 1000.0 * ps + cur * (1 - pro/ 1000.0) * pr;  
          //printf("             %lf\n", winPro);
          //printf("             %lf %lf\n", cur * pro / 1000.0 * ps, cur * (1 - pro / 1000.0) * pr);
          
          dp[turn + 1][pro][win + 1] += winPro * (1 - pw);
          dp[turn + 1][winNextPro][win + 1] += winPro * pw; 
          int lossNextPro = max(pro - (int)round(pd * 1000), 0); 
          dp[turn + 1][pro][win] += (cur - winPro) * (1 - pl);
          dp[turn + 1][lossNextPro][win] += (cur - winPro) * pl;
        }
      }
    }
    printf("Case #%d: %.06lf\n", ++TestNum, ans);
  }
}


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
const int MAXN = 32;
char grid[32][32];
int T;
int N;
bool isValid(){
  int blackCnt = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (grid[i][j] == '#') blackCnt++;
    }
  }
  int L = sqrt(blackCnt);
  if (L * L != blackCnt) return false;
  int x1, y1;
  bool found = false;
  for (int i = 0; i < N && !found; i++){
    for (int j = 0; j < N && !found; j++){
      if (grid[i][j] == '#'){
        x1 = i, y1 = j;
        found = true;
      }
    }
  }
  for (int i = x1; i < x1 + L; i++){
    for (int j = y1; j < y1 + L; j++){
      if (grid[i][j] != '#') return false;
    }
  }
  return true;
}

int TestNum;
int main(){
  ios_base::sync_with_stdio(false); 
  scanf("%d", &T);
  while (T--){
    memset(grid, 0, sizeof(grid));
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
      scanf("%s", grid[i]);
    }
    printf("Case #%d: ", ++TestNum);
    if (isValid()) printf("YES\n");
    else printf("NO\n");
  }
}


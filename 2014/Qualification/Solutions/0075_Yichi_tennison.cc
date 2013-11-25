#include <cstdlib>
#include <cstdio>
#include <map>

// compile at -O3 if you don't feel like waiting around forever for the answer

double ps, pr, pi, pu, pw, pd, pl;
int K;

std::map<double, double>* probs[100][100];
// maps of win probabilities (note that we can get to a certain number of
// wins and losses with a different win probability depending on how we got
// there, so we need to do this)

double pwin(int, int, double);

int main(void) {
  int T;
  int i, j, k;
  // Take in T
  fscanf(stdin, "%d", &T);
  for (k = 0; k < T; ++k) {
    fscanf(stdin, "%d %lf %lf %lf %lf %lf %lf %lf", &K,	\
	   &ps, &pr, &pi, &pu, &pw, &pd, &pl);
    // Initialize probs (this looks ugly, but it's better than having an
    // exponential time solution -.-;;)
    // memoization hooray
    for (i = 0; i < K; ++i)
      for (j = 0; j < K; ++j)
	probs[i][j] = new std::map<double, double>;
    printf("Case #%d: %lf\n", k+1, pwin(0,0,pi));
    for (i = 0; i < K; ++i)
      for (j = 0; j < K; ++j)
	delete probs[i][j];
  }
}

double pwin(int w, int l, double cp) {
  // w is current wins, l is current losses, cp is current sun probability
  // (since it is possible for cp to differ based on how you got to (w,l))
  double wcp, lcp;
  
  // Base cases:
  if (w == K) {
    return 1;
  }
  if (l == K) {
    return 0;
  }

  // Check whether we have calculated it already
  if (probs[w][l]->count(cp)) {
    return (*probs[w][l])[cp];
  }
  
  // New sun percentage if we win:
  wcp = cp + pu;
  if (wcp > 1)
    wcp = 1;
  // New sun percentage if we lose:
  lcp = cp - pd;
  if (lcp < 0)
    lcp = 0;
  
  (*probs[w][l])[cp] = // There are four terms to consider.
    (cp * ps + (1-cp) * pr) * pw * pwin(w+1, l, wcp) + // win, sunnier
    (cp * ps + (1-cp) * pr) * (1-pw) * pwin(w+1, l, cp) + // win, same
    (cp * (1-ps) + (1-cp) * (1-pr)) * pl * pwin(w, l+1, lcp) + // lose, rainier 
    (cp * (1-ps) + (1-cp) * (1-pr)) * (1-pl) * pwin(w, l+1, cp); // lose, same
  return (*probs[w][l])[cp];
}

#include <stdio.h>
#include <algorithm>

using namespace std;

int t, teste, k;
float prob[100][100][100][100][3];
double ps, pr, pi, pu, pw, pd, pl;

double calc(int win, int lose, int sunny, int rainy, int capped) {
   if (win == k) return 1;
   if (lose == k) return 0;

   float& ret = prob[win][lose][sunny][rainy][capped];
   if (ret < 0) {
      ret = 0;

      long double sun_prob = sunny*pu - rainy*pd;

      if (capped == 0) sun_prob += pi;
      else if (capped == 1) sun_prob += 1;

      if (sun_prob < 0) {
         sun_prob = 0;
         capped = 2;
         sunny = rainy = 0;
      }
      else if (sun_prob > 1) {
         sun_prob = 1;
         capped = 1;
         sunny = rainy = 0;
      }

      long double win_prob = sun_prob * ps + (1-sun_prob) * pr;

      ret += win_prob * pw * calc(win+1, lose, sunny+1, rainy, capped);
      ret += win_prob * (1-pw) * calc(win+1, lose, sunny, rainy, capped);
      ret += (1-win_prob) * pl * calc(win, lose+1, sunny, rainy+1, capped);
      ret += (1-win_prob) * (1-pl) * calc(win, lose+1, sunny, rainy, capped);  
   }

   return ret;
}

int main() {
   for (scanf("%d", &t); t; t--) {
      printf("Case #%d: ", ++teste);
      
      scanf("%d %lf %lf %lf %lf %lf %lf %lf", &k, &ps, &pr, &pi, &pu, &pw, &pd, &pl);
      for (int i = 0; i < k; i++) {
         for (int j = 0; j < k; j++) {
            for (int x = 0; x < k; x++) {
               for (int y = 0; y < k; y++) {
                  for (int z = 0; z < 3; z++) {
                     prob[i][j][x][y][z] = -1;
                  }
               }
            }
         }
      }

      printf("%.6lf\n", calc(0,0,0,0,0));
   }
}
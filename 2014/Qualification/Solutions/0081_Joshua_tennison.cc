#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>

using namespace std;

int goal;
double sun_win;
double rain_win;
double initial_sun;
double sun_gain;
int sun_gain_t;
double sun_gain_chance;
double sun_loss;
int sun_loss_t;
double sun_loss_chance;

// Win chance if the current probability is i,
// there are j wins and k losses.
double win_chance[2000][200][200];

int thousandths(double d) {
  return (int)(1000*d + 0.5);
}

double compute_win_chance(int prob_t, int wins, int losses) {
  if (wins == goal) return 1.0;
  if (losses == goal) return 0.0;

  if (win_chance[prob_t][wins][losses] >= 0.0) {
    return win_chance[prob_t][wins][losses];
  }

  double curr_win = double(prob_t)/1000 * sun_win + (1 - double(prob_t)/1000) * rain_win;
  double answer =   curr_win       * sun_gain_chance       * compute_win_chance(min(1000, prob_t + sun_gain_t),
                                                                                wins + 1,
                                                                                losses)
                  + curr_win       * (1 - sun_gain_chance) * compute_win_chance(prob_t,
                                                                                wins + 1,
                                                                                losses)
                  + (1 - curr_win) * sun_loss_chance       * compute_win_chance(max(0, prob_t - sun_loss_t),
                                                                                wins,
                                                                                losses + 1)
                  + (1 - curr_win) * (1 - sun_loss_chance) * compute_win_chance(prob_t,
                                                                                wins,
                                                                                losses + 1);

  return (win_chance[prob_t][wins][losses] = answer);
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cin >> goal >> sun_win >> rain_win >> initial_sun >> sun_gain >> sun_gain_chance >> sun_loss >> sun_loss_chance;
    sun_gain_t = thousandths(sun_gain);
    sun_loss_t = thousandths(sun_loss);
    for (int i = 0; i <= 1000; ++i) {
      for (int j = 0; j <= goal; ++j) {
        for (int k = 0; k <= goal; ++k) {
          win_chance[i][j][k] = -1;
        }
      }
    }
    cout << "Case #" << test << ": " << fixed << setprecision(6)
      << compute_win_chance(thousandths(initial_sun), 0, 0) << endl;
  }
  return 0;
}
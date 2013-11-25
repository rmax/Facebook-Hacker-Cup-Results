import java.util.Scanner;

public class C {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    int SUN_LIMIT = 1000;
    int K_LIMIT = 100;
    double[][][] go = new double[K_LIMIT + 1][K_LIMIT + 1][SUN_LIMIT + 1];
    for (int tc = 1; tc <= T; tc++) {
      int K = in.nextInt();
      double ps = in.nextDouble();
      double pr = in.nextDouble();
      int pi = Integer.parseInt(in.next().replace(".", ""));
      int pu = Integer.parseInt(in.next().replace(".", ""));
      double pw = in.nextDouble();
      int pd = Integer.parseInt(in.next().replace(".", ""));
      double pl = in.nextDouble();
      for (int i = 0; i < go.length; i++) {
        for (int j = 0; j < go[i].length; j++) {
          for (int k = 0; k < go[i][j].length; k++) {
            go[i][j][k] = 0;
          }
        }
      }
      go[0][0][pi] = 1;
      for (int wins = 0; wins < K; wins++) {
        for (int losses = 0; losses < K; losses++) {
          for (int sun = 0; sun <= SUN_LIMIT; sun++) {
            if (go[wins][losses][sun] > 0) {
              double curr = go[wins][losses][sun];
              double P = sun * 1e-3;
              double winChance = P * ps + (1 - P) * pr;
              double lossChance = 1 - winChance;
              double winInc = winChance * pw;
              double winSame = winChance * (1 - pw);
              double lossSame = lossChance * (1 - pl);
              double lossDec = lossChance * pl;
              go[wins + 1][losses][sun] += curr * winSame;
              go[wins + 1][losses][Math.min(SUN_LIMIT, sun + pu)] += curr * winInc;
              go[wins][losses + 1][sun] += curr * lossSame;
              go[wins][losses + 1][Math.max(0, sun - pd)] += curr * lossDec;
            }
          }
        }
      }
      double winning = 0;
      for (int losses = 0; losses < K; losses++) {
        for (int sun = 0; sun <= SUN_LIMIT; sun++) {
          winning += go[K][losses][sun];
        }
      }
      System.out.printf("Case #%d: %.6f\n", tc, winning);
    }
  }
}


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Tennison {
    static double sunWin, rainWin, sunIncreaseChance, sunDecreaseChance;
    static int sunFirstSet, sunIncrease, sunDecrease;
    static int k;
    static double[][][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(r.readLine());
        StringTokenizer st;
        String token;
        for (int i = 1; i <= t; i++) {
            st = new StringTokenizer(r.readLine());
            k = Integer.parseInt(st.nextToken());
            sunWin = Double.parseDouble(st.nextToken());
            rainWin = Double.parseDouble(st.nextToken());

            token = st.nextToken();
            if (token.charAt(0) == '1') {
                sunFirstSet = 1000;
            } else {
                sunFirstSet = Integer.parseInt(token.substring(2));
            }

            token = st.nextToken();
            if (token.charAt(0) == '1') {
                sunIncrease = 1000;
            } else {
                sunIncrease = Integer.parseInt(token.substring(2));
            }

            sunIncreaseChance = Double.parseDouble(st.nextToken());

            token = st.nextToken();
            if (token.charAt(0) == '1') {
                sunDecrease = 1000;
            } else {
                sunDecrease = Integer.parseInt(token.substring(2));
            }

            sunDecreaseChance = Double.parseDouble(st.nextToken());

            pw.format("Case #%d: %.6f\n", i,
                    Math.round(solve() * 1000000) / 1000000.0);
        }
        pw.flush();
    }

    private static double solve() {
        dp = new double[k + 1][k + 1][1001];
        dp[0][0][sunFirstSet] = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                for (int u = 0; u <= 1000; u++) {
                    if (dp[i][j][u] > 0) {
                        process(i, j, u);
                    }
                }
            }
        }
        return sumWins();
    }

    private static double sumWins() {
        double sum = 0;
        for (int j = 0; j < k; j++) {
            for (int u = 0; u <= 1000; u++) {
                sum += dp[k][j][u];
            }
        }
        return sum;
    }

    private static void process(int i, int j, int u) {
        int newSun;
        double p = dp[i][j][u];
        double win = sunWin * u / 1000 + rainWin * (1000 - u) / 1000;
        double lost = 1 - win;
        win *= p;
        lost *= p;
        // lost
        dp[i][j + 1][u] += lost * (1 - sunDecreaseChance);
        newSun = u - sunDecrease;
        if (newSun < 0) {
            newSun = 0;
        }
        dp[i][j + 1][newSun] += lost * sunDecreaseChance;
        // won
        dp[i + 1][j][u] += win * (1 - sunIncreaseChance);
        newSun = u + sunIncrease;
        if (newSun > 1000) {
            newSun = 1000;
        }
        dp[i + 1][j][newSun] += win * sunIncreaseChance;
    }
}

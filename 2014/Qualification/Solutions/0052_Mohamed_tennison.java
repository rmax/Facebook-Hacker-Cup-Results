import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

    private BufferedReader in;
    private StringTokenizer st;
    private PrintWriter out;

    int k;
    double ps, pr, pi, pu, pw, pd, pl;
    double[][][] dp;

    double solve(int k, int o, double p) {

        if (k == 0)
            return 1;
        if (o == 0)
            return 0;
        if (dp[k][o][(int) (p * 1000)] != -1.0) {
            return dp[k][o][(int) (p * 1000)];
        }
        double ans = (ps * p + (1 - p) * pr)
                * (solve(k - 1, o, p) * (1 - pw) + solve(k - 1, o, Math.min(1, p + pu)) * pw);
        ans += ((1 - ps) * p + (1 - pr) * (1 - p))
                * (solve(k, o - 1, p) * (1 - pl) + solve(k, o - 1, Math.max(0, p - pd)) * pl);
        return dp[k][o][(int) (p * 1000)] = ans;

    }
    void solve() throws IOException {

        int t = nextInt();
        int kase = 0;
        while (t-- > 0) {
            kase++;
            out.print("Case #" + kase + ": ");
            k = nextInt();
            ps = nextDouble();
            pr = nextDouble();
            pi = nextDouble();
            pu = nextDouble();
            pw = nextDouble();
            pd = nextDouble();
            pl = nextDouble();
            dp = new double[k + 1][k + 1][1000 + 1];
            for (int i = 0; i < dp.length; i++) {
                for (int j = 0; j < dp[i].length; j++) {
                    Arrays.fill(dp[i][j], -1);
                }

            }
            //            System.out.println(solve(k, k, pi));
            out.printf("%1.6f", solve(k, k, pi));
            out.println();

        }
    }

    C() throws IOException {
        in = new BufferedReader(new FileReader("in"));
        out = new PrintWriter(new FileWriter("out"));
        eat("");
        solve();
        out.close();
    }

    private void eat(String str) {
        st = new StringTokenizer(str);
    }

    String next() throws IOException {
        while (!st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null) {
                return null;
            }
            eat(line);
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static void main(String[] args) throws IOException {
        new C();
    }

    int gcd(int a, int b) {
        if (b > a)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

}

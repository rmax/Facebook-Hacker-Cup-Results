import java.io.*;

public class SquareDetector {

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(r.readLine());
        int n;
        for (int i = 1; i <= t; i++) {
            n = Integer.parseInt(r.readLine());
            char[][] cc = new char[n][];
            for (int j = 0; j < n; j++) {
                cc[j] = r.readLine().toCharArray();
            }
            pw.println("Case #" + i + ": " + solve(n, cc));
        }
        pw.flush();
    }

    private static String solve(int n, char[][] cc) {
        int count = 0;
        int minX = n + 1;
        int maxX = -1;
        int minY = n + 1;
        int maxY = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cc[i][j] == '#') {
                    count++;
                    minX = Math.min(i, minX);
                    maxX = Math.max(i, maxX);
                    minY = Math.min(j, minY);
                    maxY = Math.max(j, maxY);
                }
            }
        }
        if (maxX == -1) {
            return "NO";
        }
        int x = maxX - minX + 1;
        int y = maxY - minY + 1;
        if (x != y) {
            return "NO";
        }
        if (x * y != count) {
            return "NO";
        }
        return "YES";
    }

}

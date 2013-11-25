import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

    private BufferedReader in;
    private StringTokenizer st;
    private PrintWriter out;

    void solve() throws IOException {


        int t = nextInt();
        int kase = 0;
        while(t-->0){
            kase++;
            out.print("Case #" + kase + ": ");
            int n = nextInt();
            char[][] arr = new char[n][n];
            for (int i = 0; i < arr.length; i++) {
                arr[i] = next().toCharArray();
            }
            int st = 0;
            int end = 0;
            int c = 0;
            l:for (int i = 0; i < arr.length; i++) {
                for (int j = 0; j < arr.length; j++) {
                    if(arr[i][j] == '#'){
                        for (int k = j; k < arr.length; k++) {
                            if(arr[i][k] == '#'){
                                c ++;
                            }
                            else break;
                        }
                        st = i;
                        end = j;
                        break l;
                    }
                }
            }
            boolean valid = true;
            l: for (int i = st; i < st + c; i++) {
                for (int j = end; j < end + c; j++) {
                    if (arr[i][j] != '#') {
                        valid = false;
                        break l;
                    }
                }
            }
            if (valid) {
                l: for (int i = 0; i < arr.length; i++) {
                    for (int j = 0; j < arr.length; j++) {
                        if (arr[i][j] == '#' && (i < st || i >= st + c || j < end || j >= end + c)) {
                            valid = false;
                            break l;
                        }
                    }
                }
            }

            if (valid) {
                out.println("YES");
            }
            else {
                out.println("NO");
            }
        }
    }

    A() throws IOException {
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
        new A();
    }

    int gcd(int a, int b) {
        if (b > a)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

}

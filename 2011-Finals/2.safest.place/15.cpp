import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    FastScanner in;
    PrintWriter out;

    int n;
    class S {
        int x;
        int y;
        int z;

        S(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    S[] s;

    int max = 1000;

    boolean[] ok;

    boolean search(int minx, int maxx, int miny, int maxy, int minz, int maxz, int r, int d) {
        Arrays.fill(ok, true);
        int dx = Math.max(1, maxx - minx);
        int dy = Math.max(1, maxy - miny);
        int dz = Math.max(1, maxz - minz);
        int k = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            k = 0;
            for (int x = minx; x <= maxx; x += dx) {
                for (int y = miny; y <= maxy; y += dy) {
                    for (int z = minz; z <= maxz; z += dz) {
                        int wd = (x - s[i].x) * (x - s[i].x) + (y - s[i].y) * (y - s[i].y) + (z - s[i].z) * (z - s[i].z);
                        if (wd < r) {
                            ok[k] = false;
                            c++;
                        }
                        k++;
                    }
                }
            }
            if (c == k) {
                return false;
            }
        }

        for (int i = 0; i < k; i++) {
            if (ok[i]) {
                return true;
            }
        }

        if (minx == maxx || miny == maxy || minz == maxz) {
            return false;
        }

        switch (d % 3) {
            case 0:
                return
                        search(minx, (minx + maxx) / 2, miny, maxy, minz, maxz, r, d + 1) ||
                                search((minx + maxx) / 2 + 1, maxx, miny, maxy, minz, maxz, r, d + 1);
            case 1:
                return
                        search(minx, maxx, miny, (miny + maxy) / 2, minz, maxz, r, d + 1) ||
                                search(minx, maxx, (miny + maxy) / 2 + 1, maxy, minz, maxz, r, d + 1);
            case 2:
                return
                        search(minx, maxx, miny, maxy, minz, (minz + maxz) / 2, r, d + 1) ||
                                search(minx, maxx, miny, maxy, (minz + maxz) / 2 + 1, maxz, r, d + 1);

        }
        return false;
    }

    public void solve() {
        n = in.nextInt();
        s = new S[n];
        for (int i = 0; i < n; i++) {
            s[i] = new S(in.nextInt(), in.nextInt(), in.nextInt());
        }
        ok = new boolean[8];

        int l = 0;
        int r = 3000000;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (search(0, max, 0, max, 0, max, m, 0)) {
                l = m;
            } else {
                r = m;
            }
        }
        out.println(l);
    }

    void run() throws FileNotFoundException {
        in = new FastScanner("B.in");
        out = new PrintWriter("B.out");

        int testN = in.nextInt();
        for (int test = 0; test < testN; test++) {
            System.out.println(test);
            solve();
            out.flush();
        }
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        new B().run();
    }

    public class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String fileName) {
            try {
                br = new BufferedReader(new FileReader(new File(fileName)));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
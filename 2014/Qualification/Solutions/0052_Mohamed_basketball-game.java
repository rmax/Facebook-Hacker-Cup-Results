import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {

    private BufferedReader in;
    private StringTokenizer st;
    private PrintWriter out;

    void check1(PriorityQueue<player> p) {
        player[] tmp = new player[p.size()];
        int sz = 0;
        while (p.size() > 0) {
            tmp[sz++] = p.remove();
        }
        for (int i = 1; i < tmp.length; i++) {
            if (tmp[i].timeplayed > tmp[i - 1].timeplayed
                    || (tmp[i].timeplayed == tmp[i - 1].timeplayed && tmp[i].compareTo(tmp[i - 1]) < 0)) {
                System.out.println("error");
            }
        }
        for (int i = 0; i < tmp.length; i++) {
            p.add(tmp[i]);
        }
    }

    void check2(PriorityQueue<player> p) {
        player[] tmp = new player[p.size()];
        int sz = 0;
        while (p.size() > 0) {
            tmp[sz++] = p.remove();
        }
        for (int i = 1; i < tmp.length; i++) {
            if (tmp[i].timeplayed < tmp[i - 1].timeplayed
                    || (tmp[i].timeplayed == tmp[i - 1].timeplayed && tmp[i].compareTo(tmp[i - 1]) > 0)) {
                System.out.println("error");
            }
        }
        for (int i = 0; i < tmp.length; i++) {
            p.add(tmp[i]);
        }
    }
    void solve() throws IOException {

        int t = nextInt();
        int kase = 0;
        while (t-- > 0) {
            kase++;
            out.print("Case #" + kase + ":");
            player[] players = new player[nextInt()];
            int n = players.length;
            int m = nextInt();
            int p = nextInt();
            for (int i = 0; i < players.length; i++) {
                player x = new player();
                x.name = next();
                x.shot = nextInt();
                x.height = nextInt();
                x.timeplayed = 0;
                x.current = false;
                players[i] = x;
            }
            Arrays.sort(players);
            for (int i = 0; i < 2 * p; i++) {
                players[i].current = true;
            }
            int i = 1;
            while (i <= m) {
                for (int j = 0; j < players.length; j++) {
                    if (players[j].current) {
                        players[j].timeplayed++;
                    }
                }

                for (int st = 0; st < 2; st++) {
                    int removed = 0;
                    int time = 0;
                    int k;
                    if (st == 0) {
                        k = players.length - 1 - ((n + 1) % 2);
                    } else {
                        k = players.length - 1 - (n % 2);
                    }
                    for (int j = k; j >= 0; j -= 2) {
                        if (players[j].current && players[j].timeplayed > time) {
                            time = players[j].timeplayed;
                            removed = j;
                        }
                    }
                    players[removed].current = false;
                    time = Integer.MAX_VALUE;

                    for (int j = st; j < players.length; j += 2) {
                        if (!players[j].current && players[j].timeplayed < time) {
                            time = players[j].timeplayed;
                            removed = j;
                        }
                    }
                    players[removed].current = true;
                }

                i++;
            }
            //            PriorityQueue<player> p1 = new PriorityQueue<player>(p, new compare1());
            //            PriorityQueue<player> d1 = new PriorityQueue<player>(n, new compare2());
            //            PriorityQueue<player> p2 = new PriorityQueue<player>(p, new compare1());
            //            PriorityQueue<player> d2 = new PriorityQueue<player>(n, new compare2());
            //
            //            for (int i = 0; i < players.length; i++) {
            //                if (i % 2 == 0) {
            //                    d2.add(players[i]);
            //                } else {
            //                    d1.add(players[i]);
            //                }
            //            }
            //            while (p1.size() < p) {
            //                p1.add(d1.remove());
            //            }
            //
            //            while (p2.size() < p) {
            //                p2.add(d2.remove());
            //            }
            //            int i = 1;
            //            while (i < m) {
            //
            //                check1(p1);
            //                check1(p2);
            //                check2(d1);
            //                check2(d2);
            //                player[] tmp = new player[p];
            //                for (int j = 0; j < p; j++) {
            //                    tmp[j] = p1.remove();
            //                    tmp[j].timeplayed++;
            //                }
            //                for (int j = 0; j < tmp.length; j++) {
            //                    p1.add(tmp[j]);
            //                }
            //                for (int j = 0; j < p; j++) {
            //                    tmp[j] = p2.remove();
            //                    tmp[j].timeplayed++;
            //                }
            //                for (int j = 0; j < tmp.length; j++) {
            //                    p2.add(tmp[j]);
            //                }
            //                if (d1.size() > 0) {
            //                    player a = p1.remove();
            //                    p1.add(d1.remove());
            //                    d1.add(a);
            //                }
            //                if (d2.size() > 0) {
            //                    player a = p2.remove();
            //                    p2.add(d2.remove());
            //                    d2.add(a);
            //                }
            //
            //                i++;
            //            }
            String[] ans = new String[2 * p];
            int sz = 0;
            for (int j = 0; j < players.length; j++) {
                if (players[j].current) {
                    ans[sz++] = players[j].name;
                }
            }
            //            for (player a : p1) {
            //                ans[sz++] = a.name;
            //            }
            //            for (player a : p2) {
            //                ans[sz++] = a.name;
            //            }
            Arrays.sort(ans);
            for (int j = 0; j < ans.length; j++) {
                out.print(" " + ans[j]);
            }
            out.println();

        }
    }

    B() throws IOException {
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
        new B();
    }

    int gcd(int a, int b) {
        if (b > a)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

}

class player implements Comparable<player> {
    String name;
    int shot;
    int height;
    int timeplayed = 0;
    boolean current;

    @Override
    public int compareTo(player o) {
        if (shot > o.shot || (shot == o.shot && height > o.height))
            return -1;
        return 1;
    }
}

class compare1 implements Comparator<player> {

    @Override
    public int compare(player o1, player o2) {
        if (o1.timeplayed > o2.timeplayed || (o1.timeplayed == o2.timeplayed && o1.compareTo(o2) < 0))
            return -1;
        return 1;
    }

}

class compare2 implements Comparator<player> {

    @Override
    public int compare(player o1, player o2) {
        if (o1.timeplayed < o2.timeplayed || (o1.timeplayed == o2.timeplayed && o1.compareTo(o2) > 0))
            return -1;
        return 1;
    }

}
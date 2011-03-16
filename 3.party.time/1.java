import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class PartyTime implements Runnable {
    class Solver implements Runnable {
        int testId;
        int input;
        int res;
        boolean failed = false;

        Solver(int testId) {
            this.testId = testId;
        }

        int n;
        int f;
        int m;
        boolean[][] friends;
        int[] food;

        private void readInput() {
            n = nextInt();
            f = nextInt();
            m = nextInt();
            friends = new boolean[n][n];
            for (int i = 0; i < m; ++i) {
                int a = nextInt();
                int b = nextInt();
                friends[a][b] = true;
                friends[b][a] = true;
            }
            food = new int[n];
            for (int i = 0; i < n; ++i) food[i] = nextInt() * 1000 + 1;
        }

        int finalRes;

        public void run() {
            int[][] d = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        if (friends[i][j]) d[i][j] = food[j]; else d[i][j] = Integer.MAX_VALUE / 2;
                    }
                }
            }
            for (int k = 0; k < n; ++k)
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
            int[][] best = new int[1 << f][n];
            for (int set = 1; set < (1 << f); ++set) {
                Arrays.fill(best[set], Integer.MAX_VALUE / 2);
                if ((set & (set - 1)) == 0) {
                    int first = 0;
                    while ((set & (1 << first)) == 0) ++first;
                    best[set][first] = food[first];
                } else {
                    for (int subset = set; subset > 0; subset = (subset - 1) & set) {
                        if (subset == set) continue;
                        for (int i = 0; i < n; ++i)
                            best[set][i] = Math.min(best[set][i], best[subset][i] + best[subset ^ set][i] - food[i]);
                    }
                }
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        best[set][j] = Math.min(best[set][j], best[set][i] + d[i][j]);
                    }
                }
            }
            finalRes = Integer.MAX_VALUE / 2;
            for (int i = 0; i < n; ++i)
                finalRes = Math.min(finalRes, best[(1 << f) - 1][i]);
        }

        private void printOutput() {
            if (failed) {
                writer.println("BAD!!!");
                System.out.println("BAD!!!");
            } else {
                writer.println(finalRes / 1000 + " " + finalRes % 1000);
            }
        }
    }

    private void solveSequential() {
        int numTests = nextInt();
        for (int testId = 0; testId < numTests; ++testId) {
            Solver solver = new Solver(testId);
            solver.readInput();
            solver.run();
            solver.printOutput();
        }
    }

    private void solveParallel() {
        int numTests = nextInt();
        ExecutorService executor = Executors.newFixedThreadPool(4);
        Solver[] solver = new Solver[numTests];
        for (int testId = 0; testId < numTests; ++testId) {
            solver[testId] = new Solver(testId);
            solver[testId].readInput();
        }
        Future[] res = new Future[numTests];
        for (int testId = 0; testId < numTests; ++testId) {
            res[testId] = executor.submit(new Thread(solver[testId]));
        }
        for (int testId = 0; testId < numTests; ++testId) {
            try {
                res[testId].get();
            } catch (InterruptedException e) {
                solver[testId].failed = true;
            } catch (ExecutionException e) {
                solver[testId].failed = true;
            }
        }
        for (int testId = 0; testId < numTests; ++testId) {
            solver[testId].printOutput();
        }
        executor.shutdown();
    }

    static final String TASK_ID = "party";

    public static void main(String[] args) {
        new PartyTime().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer = null;
    PrintWriter writer;

    public void run() {
        try {
            long now = System.currentTimeMillis();
            reader = new BufferedReader(new FileReader(TASK_ID + ".in"));
            writer = new PrintWriter(TASK_ID + ".out");
            solveParallel();
            reader.close();
            writer.close();
            System.out.println(System.currentTimeMillis() - now + "ms");
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    long nextLong() {
        return Long.parseLong(nextToken());
    }

    String nextToken() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }
}

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class SafestPlace implements Runnable {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;

        Solver(int testId) {
            this.testId = testId;
        }

        int n;
        int[] x;
        int[] y;
        int[] z;

        private void readInput() {
            n = nextInt();
            x = new int[n];
            y = new int[n];
            z = new int[n];
            for (int i = 0; i < n; ++i) {
                x[i] = nextInt();
                y[i] = nextInt();
                z[i] = nextInt();
            }
        }

        int res;

        public void run() {
            int[] event = new int[2 * n];
            res = 0;
            for (int rx = 0; rx <= 1000; ++rx) {
                //if (rx % 10 == 0) System.out.println(rx);
                int saved = -1;
                for (int ry = 0; ry <= 1000; ++ry) {
                    if (verify(event, rx, ry, res)) continue;
                    int left;
                    int right;
                    if (saved >= 0) {
                        int delta = 1001;
                        while (true) {
                            delta *= 2;
                            left = Math.max(res, saved - delta);
                            right = Math.min(1000 * 1000 * 3 + 5, saved + delta);
                            if (verify(event, rx, ry, left)) continue;
                            if (!verify(event, rx, ry, right)) continue;
                            break;
                        }
                    } else {
                        left = res;
                        right = 1000 * 1000 * 3 + 5;
                    }
                    while (right - left > 1) {
                        int middle = (left + right) / 2;
                        boolean all = verify(event, rx, ry, middle);
                        if (all)
                            right = middle;
                        else
                            left = middle;
                    }
                    res = Math.max(res, right);
                    saved = right;
                }
            }
            System.out.println(testId + " done!");
        }

        private boolean verify(int[] event, int rx, int ry, int middle) {
            int nevent = 0;
            for (int i = 0; i < n; ++i) {
                int delta = middle - (rx - x[i]) * (rx - x[i]) - (ry - y[i]) * (ry - y[i]);
                if (delta >= 0) {
                    int what = (int) Math.sqrt(delta) - 1;
                    while ((what + 1) * (what + 1) <= delta) ++what;
                    int l = Math.max(0, z[i] - what);
                    int r = Math.min(1001, z[i] + what + 1);
                    event[nevent++] = 2 * l;
                    event[nevent++] = 2 * r + 1;
                }
            }
            Arrays.sort(event, 0, nevent);
            boolean all = true;
            if (nevent == 0 || event[0] > 0)
                all = false;
            else if (event[nevent - 1] != 2 * 1001 + 1)
                all = false;
            else {
                int balance = 0;
                for (int i = 0; i < nevent - 1; ++i) {
                    if (event[i] % 2 == 0)
                        ++balance;
                    else
                        --balance;
                    if (balance == 0)
                        all = false;
                }
            }
            return all;
        }

        private void printOutput() {
            if (failed) {
                writer.println("BAD!!!");
                System.out.println("BAD!!!");
            } else {
                writer.println(res);
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
                throw new RuntimeException(e);
//                solver[testId].failed = true;
            } catch (ExecutionException e) {
                throw new RuntimeException(e);
//                solver[testId].failed = true;
            }
        }
        for (int testId = 0; testId < numTests; ++testId) {
            solver[testId].printOutput();
        }
        executor.shutdown();
    }

    static final String TASK_ID = "place";

    public static void main(String[] args) {
        new SafestPlace().run();
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

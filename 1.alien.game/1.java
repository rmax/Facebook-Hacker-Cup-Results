import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class AlienGame implements Runnable {
    class Solver implements Runnable {
        int testId;
        boolean failed = false;

        Solver(int testId) {
            this.testId = testId;
        }

        int n;
        int p;

        class Amount {
            int where;
            long k = 0;
            long b = 0;
            Update upd = new Update();

            void refreshUpdate() {
                upd.where = where;
                if (where == 0 || where == n - 1 || k < 0) {
                    upd.atMin = maxForP + 1;
                } else if (k == 0) {
                    if (b > 0) {
                        upd.atMin = -maxForP;
                    } else {
                        upd.atMin = maxForP + 1;
                    }
                } else {
                    if (k != 1) throw new RuntimeException();
                    upd.atMin = Math.min(maxForP + 1, Math.max(-maxForP, 1 - b));
                }
            }
        }

        class Update implements Comparable<Update> {
            long atMin;
            int where;

            public int compareTo(Update o) {
                if (atMin < o.atMin)
                    return -1;
                else if (atMin > o.atMin)
                    return 1;
                else if (where < o.where)
                    return -1;
                else if (where > o.where)
                    return 1;
                else
                    return 0;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;

                Update update = (Update) o;

                if (atMin != update.atMin) return false;
                if (where != update.where) return false;

                return true;
            }

            @Override
            public int hashCode() {
                int result = (int) (atMin ^ (atMin >>> 32));
                result = 31 * result + where;
                return result;
            }
        }

        Amount[] cur;
        long maxForP;

        private void readInput() {
            n = nextInt();
            p = nextInt() - 1;
            cur = new Amount[n];
            for (int i = 0; i < n; ++i) {
                long what = nextLong();
                cur[i] = new Amount();
                cur[i].where = i;
                if (i == p) {
                    maxForP = what;
                    cur[i].k = 1;
                } else {
                    cur[i].b = what;
                }
            }
        }

        long res;

        public void run() {
            TreeSet<Update> updates = new TreeSet<Update>();
            for (Amount a : cur) {
                a.refreshUpdate();
                updates.add(a.upd);
            }
            res = 0;
            if (updates.isEmpty()) {
                return;
            }
            long start = -maxForP;
            boolean isWinning = false;
            while (true) {
                Update u = updates.first();
                long now = u.atMin;
                if (now < start) throw new RuntimeException();
                if (isWinning)
                    res += now - start;
                if (u.atMin > maxForP) {
                    break;
                }
                int i = u.where;
                updates.remove(cur[i - 1].upd);
                updates.remove(cur[i + 1].upd);
                updates.remove(cur[i].upd);
                cur[i - 1].k += cur[i].k;
                cur[i - 1].b += cur[i].b;
                cur[i + 1].k += cur[i].k;
                cur[i + 1].b += cur[i].b;
                cur[i].k *= -1;
                cur[i].b *= -1;
                cur[i - 1].refreshUpdate();
                cur[i].refreshUpdate();
                cur[i + 1].refreshUpdate();
                updates.add(cur[i - 1].upd);
                updates.add(cur[i + 1].upd);
                updates.add(cur[i].upd);
                isWinning = !isWinning;
                start = now;
            }
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

    static final String TASK_ID = "alien";

    public static void main(String[] args) {
        new AlienGame().run();
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

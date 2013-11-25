import java.io.*;
import java.util.*;

public class BasketballGame {
    static ArrayList<Player> players = new ArrayList<>();
    static ArrayList<Player> firstBench = new ArrayList<>();
    static ArrayList<Player> secondBench = new ArrayList<>();
    static ArrayList<Player> firstTeam = new ArrayList<>();
    static ArrayList<Player> secondTeam = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int t = Integer.parseInt(r.readLine());
        int n, m, p;
        StringTokenizer st;
        String name;
        int shotPercentage, height, rank;
        Player player;
        for (int i = 1; i <= t; i++) {
            st = new StringTokenizer(r.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            p = Integer.parseInt(st.nextToken());
            players.clear();
            for (int j = 0; j < n; j++) {
                st = new StringTokenizer(r.readLine());
                name = st.nextToken();
                shotPercentage = Integer.parseInt(st.nextToken());
                height = Integer.parseInt(st.nextToken());
                players.add(new Player(name, shotPercentage, height));
            }
            Collections.sort(players, new Comparator<Player>() {

                @Override
                public int compare(Player p1, Player p2) {
                    if (p1.shotPercentage != p2.shotPercentage) {
                        return -(p1.shotPercentage - p2.shotPercentage);
                    }
                    return -(p1.height - p2.height);
                }
            });
            firstBench.clear();
            secondBench.clear();
            for (int j = 0; j < n; j++) {
                rank = j + 1;
                player = players.get(j);
                player.rank = rank;
                if (rank % 2 == 1) {
                    firstBench.add(player);
                } else {
                    secondBench.add(player);
                }
            }
            pw.println("Case #" + i + ": " + solve(m, p));
        }
        pw.flush();
    }

    private static String solve(int m, int p) {
        initTeams(p);
        for (int i = 0; i < m; i++) {
            teamRotate(p, firstTeam, firstBench);
            teamRotate(p, secondTeam, secondBench);
        }
        combineTeams();
        String result = players.get(0).name;
        for (int i = 1; i < 2 * p; i++) {
            result += " " + players.get(i).name;
        }
        return result;
    }

    private static void teamRotate(int p, ArrayList<Player> team,
            ArrayList<Player> bench) {
        for (Player player : team) {
            player.timePlayed++;
        }

        if (bench.size() > 0) {
            Collections.sort(team);
            Collections.sort(bench);
            bench.add(team.get(p - 1));
            team.remove(p - 1);
            team.add(bench.get(0));
            bench.remove(0);
        }
    }

    private static void combineTeams() {
        players.clear();
        for (Player player : firstTeam) {
            players.add(player);
        }
        for (Player player : secondTeam) {
            players.add(player);
        }
        Collections.sort(players, new Comparator<Player>() {

            @Override
            public int compare(Player p1, Player p2) {
                return p1.name.compareTo(p2.name);
            }
        });
    }

    private static void initTeams(int p) {
        firstTeam.clear();
        secondTeam.clear();

        for (int i = 0; i < p; i++) {
            Player player = firstBench.get(0);
            firstTeam.add(player);
            firstBench.remove(0);

            player = secondBench.get(0);
            secondTeam.add(player);
            secondBench.remove(0);
        }
    }

    private static class Player implements Comparable<Player> {
        String name;
        int shotPercentage;
        int height;
        int timePlayed;
        int rank;

        public Player(String name, int shotPercentage, int height) {
            super();
            this.name = name;
            this.shotPercentage = shotPercentage;
            this.height = height;
            timePlayed = 0;
        }

        @Override
        public int compareTo(Player p) {
            if (timePlayed != p.timePlayed) {
                return timePlayed - p.timePlayed;
            }
            return rank - p.rank;
        }

        @Override
        public String toString() {
            return name + ", " + timePlayed + ", " + rank + "]";
        }
    }
}

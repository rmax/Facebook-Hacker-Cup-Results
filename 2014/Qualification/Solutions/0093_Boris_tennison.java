import java.io.*;
import java.util.*;

public class Qual {

	class Player {
		String name;
		int id;
		int shot;
		int height;
		int played;

		Player(String name, int shot, int height) {
			this.name = name;
			this.shot = shot;
			this.height = height;
		}
	}

	ArrayList<String> afterMRounds(ArrayList<Player> team, int m, int inGame) {
		int n = team.size();
		for (int i = 0; i < n; i++) {
			team.get(i).id = i;
		}
		ArrayList<Player> nowPlaying = new ArrayList<>();
		ArrayList<Player> notPlaying = new ArrayList<>();
		for (int i = 0; i < inGame; i++) {
			nowPlaying.add(team.get(i));
		}
		for (int i = inGame; i < team.size(); i++) {
			notPlaying.add(team.get(i));
		}
		for (int t = 0; t < m; t++) {
			for (int i = 0; i < nowPlaying.size(); i++)
				nowPlaying.get(i).played++;
			Collections.sort(nowPlaying, new Comparator<Player>() {
				@Override
				public int compare(Player o1, Player o2) {
					if (o1.played != o2.played)
						return Integer.compare(o1.played, o2.played);
					return Integer.compare(o1.id, o2.id);
				}
			});
			Player p = nowPlaying.get(nowPlaying.size() - 1);
			nowPlaying.remove(nowPlaying.size() - 1);
			Collections.sort(notPlaying, new Comparator<Player>() {
				@Override
				public int compare(Player o1, Player o2) {
					if (o1.played != o2.played)
						return -Integer.compare(o1.played, o2.played);
					return -Integer.compare(o1.id, o2.id);
				}
			});
			if (notPlaying.size() == 0) {
				nowPlaying.add(p);
			} else {
				nowPlaying.add(notPlaying.get(notPlaying.size() - 1));
				notPlaying.set(notPlaying.size() - 1, p);
			}
		}
		ArrayList<String> res = new ArrayList<>();
		for (int i = 0; i < nowPlaying.size(); i++)
			res.add(nowPlaying.get(i).name);
		return res;
	}

	void solve() {
		int t = in.nextInt();
		for (int l = 0; l < t; l++) {
			int n = in.nextInt();
			int ps = (int) Math.round(in.nextDouble() * 1000);
			int pr = (int) Math.round(in.nextDouble() * 1000);
			int pi = (int) Math.round(in.nextDouble() * 1000);
			int pu = (int) Math.round(in.nextDouble() * 1000);
			int pw = (int) Math.round(in.nextDouble() * 1000);
			int pd = (int) Math.round(in.nextDouble() * 1000);
			int pl = (int) Math.round(in.nextDouble() * 1000);
			double[][][] dp = new double[n + 1][n + 1][1001];
			dp[0][0][pi] = 1.;
			for (int sum = 0; sum < 2 * n; sum++)
				for (int v1 = 0; v1 <= sum; v1++)
					for (int v2 = 0; v2 + v1 <= sum; v2++) {
						if (v1 >= n || v2 >= n || v1 + v2 != sum)
							continue;
						for (int curP = 0; curP <= 1000; curP++) {
							double cur = dp[v1][v2][curP];
							double prSunny = curP / 1000.0;
							double prRain = 1. - prSunny;
							double prWin = prSunny * (ps / 1000.) + prRain
									* (pr / 1000.);
							double prLose = 1. - prWin;
							{
								// win
								double prUp = pw / 1000.;
								double prSame = 1. - prUp;
								int nextUp = Math.min(1000, curP + pu);
								int nextSame = curP;
								dp[v1 + 1][v2][nextUp] += prWin * prUp * cur;
								dp[v1 + 1][v2][nextSame] += prWin * prSame
										* cur;
							}
							{
								// lose
								double prDown = pl / 1000.;
								double prSame = 1. - prDown;
								int nextDown = Math.max(0, curP - pd);
								int nextSame = curP;
								dp[v1][v2 + 1][nextDown] += prLose * prDown
										* cur;
								dp[v1][v2 + 1][nextSame] += prLose * prSame
										* cur;
							}
						}
					}
			double res = 0;
			for (int v2 = 0; v2 < n; v2++)
				for (int cc = 0; cc <= 1000; cc++)
					res += dp[n][v2][cc];
			out.printf("Case #%d: %.6f\n", (l + 1), res);
		}
	}

	InputReader in;
	PrintWriter out;

	void runIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		in = new InputReader(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Qual().run();
	}

	class InputReader {
		BufferedReader bf;
		StringTokenizer st;

		InputReader(File f) {
			try {
				bf = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		InputReader(InputStream s) {
			bf = new BufferedReader(new InputStreamReader(s));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = bf.readLine();
				} catch (IOException e) {
					return null;
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
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

		boolean hasMoreElements() {
			while (!st.hasMoreElements()) {
				String s;
				try {
					s = bf.readLine();
				} catch (IOException e) {
					return false;
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}
	}
}
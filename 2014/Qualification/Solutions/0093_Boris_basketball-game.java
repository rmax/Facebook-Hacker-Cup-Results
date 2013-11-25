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
			int m = in.nextInt();
			int p = in.nextInt();
			Player[] players = new Player[n];
			for (int i = 0; i < n; i++) {
				players[i] = new Player(in.next(), in.nextInt(), in.nextInt());
			}
			Arrays.sort(players, new Comparator<Player>() {
				@Override
				public int compare(Player o1, Player o2) {
					if (o1.shot == o2.shot)
						return Integer.compare(o2.height, o1.height);
					return Integer.compare(o2.shot, o1.shot);
				}
			});
			ArrayList<Player> team1 = new ArrayList<>();
			ArrayList<Player> team2 = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					team1.add(players[i]);
				} else {
					team2.add(players[i]);
				}
			}
			ArrayList<String> all = afterMRounds(team1, m, p);
			all.addAll(afterMRounds(team2, m, p));
			Collections.sort(all);
			out.print("Case #" + (l + 1) + ": ");
			for (int i = 0; i < all.size() - 1; i++)
				out.print(all.get(i) + " ");
			out.println(all.get(all.size() - 1));
			System.err.println(l);
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
import java.io.*;
import java.util.*;

public class Qual {

	void solve() {
		int t = in.nextInt();
		for (int l = 0; l < t; l++) {
			int n = in.nextInt();
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = in.next();
			}
			int total = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					total += s[i].charAt(j) == '#' ? 1 : 0;
			boolean ok = false;
			for (int x0 = 0; x0 < n; x0++)
				for (int y0 = 0; y0 < n; y0++)
					for (int len = 1; len <= n; len++) {
						if (len * len != total)
							continue;
						if (x0 + len > n || y0 + len > n)
							continue;
						boolean ok2 = true;
						for (int x = 0; x < len; x++)
							for (int y = 0; y < len; y++)
								if (s[x0 + x].charAt(y + y0) != '#')
									ok2 = false;
						if (ok2)
							ok = true;
					}
			out.print("Case #" + (l + 1) + ": ");
			if (ok) {
				out.println("YES");
			} else {
				out.println("NO");
			}
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
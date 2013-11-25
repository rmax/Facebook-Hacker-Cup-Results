import java.util.Scanner;

public class SquareDetector {

	private static final String YES = "YES";
	private static final String NO = "NO";

	public void run() {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			sc.nextLine();
			String[] cells = new String[N];

			for (int n = 0; n < N; n++) {
				cells[n] = sc.nextLine();
			}

			String answer = solve(cells);

			System.out.println(String.format("Case #%d: %s", t, answer));
		}

	}

	private String solve(String[] cells) {
		int N = cells.length;
		int firstRowIndex = findFirstRow(cells);

		if (firstRowIndex == -1)
			return NO;

		String firstRow = cells[firstRowIndex];
		int firstIndex = firstRow.indexOf('#');
		int squareSize = findSquareSize(firstRow, firstIndex);

		for (int r = 0; r < N; r++) {
			String row = cells[r];
			for (int i = 0; i < N; i++) {
				if (r >= firstRowIndex && r <= firstRowIndex + squareSize - 1 && i >= firstIndex && i <= firstIndex + squareSize - 1) {
					if (row.charAt(i) != '#')
						return NO;
				} else {
					if (row.charAt(i) != '.')
						return NO;
				}

			}
		}

		return YES;
	}

	private int findSquareSize(String firstRow, int firstIndex) {
		int squareSize = 0;

		while (firstIndex + squareSize < firstRow.length() && firstRow.charAt(firstIndex + squareSize) == '#') {
			squareSize++;
		}

		return squareSize;
	}

	private int findFirstRow(String[] cells) {
		for (int i = 0; i < cells.length; i++) {
			if (cells[i].indexOf("#") >= 0)
				return i;
		}

		return -1;
	}

	public static void main(String[] args) {
		SquareDetector sd = new SquareDetector();
		sd.run();
	}
}

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class SquareDetector {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		new SquareDetector();
	}
	
	int T;
	
	public SquareDetector() throws FileNotFoundException {
		String inputFile = "/Users/kwittawat/Downloads/square_detector.txt";
		Scanner scanner = new Scanner(new File(inputFile));
		T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = scanner.nextInt();
			char[][] b = new char[N][N];
			for (int j = 0; j < N; j++) {
				b[j] = scanner.next().toCharArray();
			}
			System.out.println("Case #"+i+": "+solve(N,b));
		}
	}
	
	private String solve(int N, char[][] b) {
		int expectedWidth = 0,lastRow = 0,lastCol = 0;
		
		// Search for first black
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (b[r][c] == '#') {
					lastRow = r;
					lastCol = c;
					while (c < N) {
						if (b[r][c] == '#') {
							b[r][c] = '.';
							expectedWidth++;
							c++;
						} else {
							break;
						}
					}
					break;
				}
			}
			if (expectedWidth > 0) {
				if (r + expectedWidth > N) {
					// expected square height out of bound
					return "NO";
				}
				// quit searching if first black cell has been found 
				break;
			}
		}
		
		// Make sure it's a square
		for (int r = lastRow+1; r < lastRow+expectedWidth; r++) {
			for (int c = lastCol; c < lastCol+expectedWidth; c++) {
				if (b[r][c] == '#') {
					b[r][c] = '.';
				} else {
					return "NO";
				}
			}
		}
		
		// Resume scan. Search for excess black cell
		for (int c = lastCol; c < N; c++) {
			if (b[lastRow][c] == '#') {
				return "NO";
			}
		}
		for (int r = lastRow+1; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (b[r][c] == '#') {
					return "NO";
				}
			}
		}
		
		// No more black cells, congrats!
		return "YES";
	}

}

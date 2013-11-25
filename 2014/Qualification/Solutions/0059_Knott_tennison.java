import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class Tennison {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		new Tennison();
	}

	int T, K;
	double Ps, Pr, Pi, Pu, Pw, Pd, Pl;
	HashMap<String, Double> computedResults; 

	public Tennison() throws FileNotFoundException {
		String inputFile = "/Users/kwittawat/Downloads/tennison.txt";
		Scanner scanner = new Scanner(new File(inputFile));
		T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			computedResults = new HashMap<String, Double>();
			K = scanner.nextInt();
			Ps = scanner.nextDouble();
			Pr = scanner.nextDouble();
			Pi = scanner.nextDouble();
			Pu = scanner.nextDouble();
			Pw = scanner.nextDouble();
			Pd = scanner.nextDouble();
			Pl = scanner.nextDouble();
			System.out.println("Case #" + i + ": " + solve(true));
		}
	}

	boolean useDP;

	private String solve(boolean dp) {
		useDP = dp;
		double result = helper(0, 0, Pi);
		return String.format("%f", result);
	}

	private double helper(int winCount, int loseCount, double Psun) {
		Psun = (Psun < 0)?0:(Psun > 1)?1:Psun;

		String serializedParam = "";
		if (useDP) {
			serializedParam = String.format("%d,%d,%.6f",winCount,loseCount,Psun);
			Double r = computedResults.get(serializedParam);
			if (r != null) {
				return r.doubleValue();
			}
		}

		double result = 0;
		double Pwin = (Psun * Ps) + ((1.0 - Psun) * Pr);

		if (winCount + 1 < K) {
			double resultWinIncSun = Pw * helper(winCount+1, loseCount, Psun+Pu);
			double resultWinSameSun = (1.0-Pw) * helper(winCount+1, loseCount, Psun);
			double resultWin = Pwin * (resultWinIncSun + resultWinSameSun);
			result += resultWin;
		} else {
			result += Pwin;
		}

		if (loseCount + 1 < K) {
			double resultLoseSameSun = (1.0-Pl) * helper(winCount, loseCount+1, Psun);
			double resultLoseDecSun = Pl * helper(winCount, loseCount+1, Psun-Pd);
			double resultLose = (1.0-Pwin) * (resultLoseSameSun + resultLoseDecSun);
			result += resultLose;
		} else {
			result += 0;
		}

		if (useDP) {
			computedResults.put(serializedParam, result);
		}
		return result;
	}

}

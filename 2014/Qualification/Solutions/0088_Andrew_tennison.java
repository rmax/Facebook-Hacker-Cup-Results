import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class Tennison {

	public Map<String, Double> memo;
	
	public void run() {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int t=1; t<=T; t++) {
			memo = new HashMap<String, Double>();
			
			int K = sc.nextInt();
			double ps = sc.nextDouble();
			double pr = sc.nextDouble();
			double pi = sc.nextDouble();
			double pu = sc.nextDouble();
			double pw = sc.nextDouble();
			double pd = sc.nextDouble();
			double pl = sc.nextDouble();
			
			double answer = solve(K, 0, 0, ps, pr, pi, pu, pw, pd, pl);
			
			System.out.println(String.format("Case #%d: %f", t, answer));
		}
	}
	
	private double solve(int k, int wins, int losses, double ps, double pr, double pi, double pu, double pw, double pd, double pl) {
		double winProb = ps*pi + pr*(1-pi);
		double lossProb = 1-winProb;
		
		if (wins == k) return 1;
		if (losses == k) return 0;
		
		String key = wins+","+losses+","+pi;
		if (memo.containsKey(key)) return memo.get(key);
		
		double chanceWithIncreaseAfterWin = solve(k, wins+1, losses, ps, pr, Math.min(1, pi+pu), pu, pw, pd, pl);
		double chanceNoIncreaseAfterWin = solve(k, wins+1, losses, ps, pr, pi, pu, pw, pd, pl);
		double chanceAfterWin = winProb * pw * chanceWithIncreaseAfterWin + winProb * (1-pw) * chanceNoIncreaseAfterWin;
		double chanceWithDecreaseAfterLoss = solve(k, wins, losses+1, ps, pr, Math.max(0,pi-pd), pu, pw, pd, pl);
		double chanceNoIncreaseAfterLoss = solve(k, wins, losses+1, ps, pr, pi, pu, pw, pd, pl);
		double chanceAfterLoss = lossProb * pl * chanceWithDecreaseAfterLoss + lossProb * (1-pl) * chanceNoIncreaseAfterLoss;
		
		double result = chanceAfterWin + chanceAfterLoss;
		
		memo.put(key, result);
		
		return result;
	}

	public static void main(String[] args) {
		Tennison t = new Tennison();
		t.run();
	}
}

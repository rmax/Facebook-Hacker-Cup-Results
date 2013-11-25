import java.util.*;

public class R0C {

	static int k, pu, pd;
	static double ps, pr, pw, pl;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncs = sc.nextInt();
		for(int cs = 0; cs < ncs; cs++) {
			k = sc.nextInt(); // nmatches
			ps = sc.nextDouble(); // win when sunny
			pr = sc.nextDouble(); // win when rainny
			int pi = (int)Math.round(sc.nextDouble() * 1000); // first set sunny
			pu = (int)Math.round(sc.nextDouble() * 1000); // amt increase sun
			pw = sc.nextDouble(); // prob increase
			pd = (int)Math.round(sc.nextDouble() * 1000); // amt decrease sun
			pl = sc.nextDouble(); // prob decrease
			
			for(int i = 0; i < 2009; i++) 
				for(int j = 0; j < 101; j++) Arrays.fill(dp[i][j], Double.NaN);
			
			System.out.printf("Case #%d: %.6f\n", cs+1, dp(pi, 0, 0));
		}
	}
	
	static double[][][] dp = new double[2009][101][101];
	
	static double dp(int iprobsun, int mywin, int opwin) {
		iprobsun = Math.min(1000, Math.max(0, iprobsun));
		if(!Double.isNaN(dp[iprobsun + 1000][mywin][opwin])) return dp[iprobsun + 1000][mywin][opwin];
		if(opwin == k) return 0;
		if(mywin == k) return 1;
		
		double probsun = iprobsun / 1000.0;
		
		return dp[iprobsun + 1000][mywin][opwin] = 
		probsun * ps * pw * dp(iprobsun + pu, mywin + 1, opwin) // sunny, win, change
		+ probsun * ps * (1 - pw) * dp(iprobsun, mywin + 1, opwin) // sunny, win, same
		+ probsun * (1 - ps) * pl * dp(iprobsun - pd, mywin, opwin + 1) // sunny, lose, change
		+ probsun * (1 - ps) * (1 - pl) * dp(iprobsun, mywin, opwin + 1) // sunny, lose, same
		
		+ (1 - probsun) * pr * pw * dp(iprobsun + pu, mywin + 1, opwin) // rainy, win, change
		+ (1 - probsun) * pr * (1 - pw) * dp(iprobsun, mywin + 1, opwin) // rainy, win, same
		+ (1 - probsun) * (1 - pr) * pl * dp(iprobsun - pd, mywin, opwin + 1) // rainy, lose, change
		+ (1 - probsun) * (1 - pr) * (1 - pl) * dp(iprobsun, mywin, opwin + 1); // rainy, lose, same
	}
	
}

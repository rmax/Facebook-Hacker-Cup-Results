import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		final int MAX_NUM_CASE = readInt();
		for(int qq = 1; qq <= MAX_NUM_CASE; qq++)	{
			pw.print("Case #" + qq + ": ");
			int k = readInt();
			double pSunWin = readDouble();
			double pRainWin = readDouble();
			int startP = (int)Math.round(1000*readDouble());
			int sunInc = (int)Math.round(1000*readDouble());
			double probOfProbInc = readDouble();
			int sunDec = (int)Math.round(1000*readDouble());
			double probOfProbDec = readDouble();
			double[][][] dp = new double[k+1][k+1][1001];
			dp[0][0][startP] = 1;
			for(int i = 0; i < k; i++) {
				for(int j = 0; j < k; j++) {
					for(int a = 0; a <= 1000; a++) {
						if(dp[i][j][a] == 0) continue;
						double pWin = (a/1000.*pSunWin) + ((1000-a)/1000. * pRainWin);
						double pLose = 1 - pWin;
						dp[i+1][j][a] += dp[i][j][a] * pWin * (1-probOfProbInc);
						dp[i+1][j][Math.min(1000,a+sunInc)] += dp[i][j][a] * pWin * probOfProbInc;
						dp[i][j+1][a] += dp[i][j][a] * pLose * (1-probOfProbDec);
						dp[i][j+1][Math.max(0,a-sunDec)] += dp[i][j][a] * pLose * probOfProbDec;
					}
				}
			}
			double ret = 0;
			for(int a = 0; a < k; a++) {
				for(int b = 0; b <= 1000; b++) {
					ret += dp[k][a][b];
				}
			}
			pw.printf("%.6f\n", ret);
		}
		pw.close();
	}

	public static double logBinom(int n, int k) {
		double ret = 0;
		for(int i = 2; i <= n; i++) {
			ret += Math.log(i);
		}
		for(int i = 2; i <= k; i++) {
			ret -= Math.log(i);
		}
		for(int i = 2; i <= n-k; i++) {
			ret -= Math.log(i);
		}
		return ret;
	}

	/* NOTEBOOK CODE */

	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}


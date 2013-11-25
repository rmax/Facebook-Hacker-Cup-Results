import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class A {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		final int MAX_NUM_CASE = readInt();
		for(int qq = 1; qq <= MAX_NUM_CASE; qq++)	{
			pw.print("Case #" + qq + ": ");
			int n = readInt();
			char[][] grid = new char[n][n];
			for(int i = 0; i < grid.length; i++) {
				grid[i] = nextToken().toCharArray();
			}
			int count = 0;
			for(char[] a: grid) {
				for(char b: a) {
					if(b == '#') {
						count++;
					}
				}
			}
			int minR = n;
			int maxR = 0;
			int minC = n;
			int maxC = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(grid[i][j] == '#') {
						minR = Math.min(minR, i);
						maxR = Math.max(maxR, i);
						minC = Math.min(minC, j);
						maxC = Math.max(maxC, j);
					}
				}
			}
			int rDiff = maxR - minR+1;
			int cDiff = maxC - minC+1;
			if(rDiff == cDiff && rDiff*cDiff == count) {
				pw.println("YES");
			}
			else {
				pw.println("NO");
			}
		}
		pw.close();
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
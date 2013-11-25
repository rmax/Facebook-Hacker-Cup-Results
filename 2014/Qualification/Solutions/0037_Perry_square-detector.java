import java.util.*;

public class R0A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncs = sc.nextInt();
		out: for(int cs = 0; cs < ncs; cs++) {
			int n = sc.nextInt();
			sc.nextLine();
			char[][] map = new char[n][n];
			for(int i = 0; i < n; i++) map[i] = sc.nextLine().toCharArray();
			int minx = 99, miny = 99, maxx = -1, maxy = -1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(map[i][j] != '#') continue;
					minx = Math.min(minx, j);
					maxx = Math.max(maxx, j);
					miny = Math.min(miny, i);
					maxy = Math.max(maxy, i);
				}
			}
			for(int i = miny; i <= maxy; i++) {
				for(int j = minx; j <= maxx; j++) {
					if(map[i][j] != '#') {
						System.out.printf("Case #%d: NO\n", cs+1);
						continue out;
					}
				}
			}
			if(maxx - minx != maxy - miny) System.out.printf("Case #%d: NO\n", cs+1);
			else System.out.printf("Case #%d: YES\n", cs+1);
		}
	}
}

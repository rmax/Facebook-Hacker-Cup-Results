import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class SquareDetector
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());
            boolean[][] m = new boolean[N][N];
            int[] firstPoint = new int[2];
            firstPoint[0] = -1;
            int width = 0;
            boolean started = false;
            for(int i=0;i<N;i++) {
                String s = in.readLine();
                for(int j=0;j<N;j++) {
                    if(s.charAt(j)=='.') {
                        m[i][j] = false;
                        if(firstPoint[0] == i) {
                            started = false;
                        }
                    } else {
                        if(firstPoint[0] == -1) {
                            firstPoint[0] = i;
                            firstPoint[1] = j;
                            width = 0;
                            started = true;
                        } else if(firstPoint[0] == i) {
                            width++;
                        }
                        m[i][j] = true;
                    }
                }
            }
            if(isSquare(m, firstPoint, width, N)) {
                System.out.println("Case #"+(t+1)+": YES");
            } else {
                System.out.println("Case #"+(t+1)+": NO");
            }
        }
    }
    private static boolean isSquare(boolean[][] m, int[] firstPoint, int width, int N) {
        if(firstPoint[0]+width>=N||firstPoint[1]+width>=N) {
            return false;
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(m[i][j]) {
                    if(firstPoint[0]>i||firstPoint[0]+width<i) return false;
                    if(firstPoint[1]>j||firstPoint[1]+width<j) return false;
                } else {
                    if(firstPoint[0]<=i&&firstPoint[0]+width>=i&&firstPoint[1]<=j&&firstPoint[1]+width>=j) return false;
                }
            }
        }
        return true;
    }
}

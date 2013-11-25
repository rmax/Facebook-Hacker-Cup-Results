import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class A {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    public void task() throws IOException {
    	int N = nextInt();
    	char[][] map = new char[N][];
    	for(int i = 0; i < N; i++)
    		map[i] = reader.readLine().toCharArray();
    	
    	int r1, c1, r2, c2;
    	r1 = c1 = r2 = c2 = -1;
    	for(int i = 0; i < N; i++){
    		for(int j = 0; j < N; j++){
    			if (map[i][j] == '.') continue;
    			
    			if(r1 == -1){
    				r1 = i; c1 = j;
    			}
    			r2 = i; c2 = j;
    		}
    	}
    	
    	if(r2 - r1 != c2 - c1) {
    		out.println("NO"); return;
    	}
    	for(int i = r1; i <= r2; i++){
    		for(int j = c1; j <= c2; j++){
    			if(map[i][j] != '#'){
    				out.println("NO"); return;
    			}
    		}
    	}
    	out.println("YES");
    	
    }
        
	public void solve() throws IOException {
		int T = nextInt();
		for(int t = 1; t <= T; t++){
			out.print("Case #" + (t) + ": ");
			task();
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new A().run();
	}
	
	public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            out = new PrintWriter(System.out);
            solve();
            reader.close();
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

}

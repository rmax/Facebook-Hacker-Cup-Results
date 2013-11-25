import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.*;

public class C {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    double PS;
	double PR;
	double PI;
	double PU;
	double PW;
	double PD;
	double PL;
	int K;
	
	double[][][] cache;
    public void task() throws IOException {
    	K = nextInt();
    	PS = nextDouble();
    	PR = nextDouble();
    	PI = nextDouble();
    	PU = nextDouble();
    	PW = nextDouble();
    	PD = nextDouble();
    	PL = nextDouble();   
    	
    	cache = new double[K][K][1001];
    	for(int i = 0; i < K; i++){
    		for(int j = 0; j < K; j++){
    			Arrays.fill(cache[i][j], -1);
    		}
    	}
    	double ans = dfs(0, 0, PI);
    	
    	DecimalFormat df = new DecimalFormat("0.000000");
        out.println(df.format(ans));    	
    }
    
    public double dfs(int win, int lose, double psun){
    	if(lose == K) return 0;
    	if(win == K) return 1;    	
    	if(psun > 1) psun = 1;
    	if(psun < 0) psun = 0;
    	
    	int psunI = (int) (psun*1000);
    	if(cache[win][lose][psunI] != -1){
    		return cache[win][lose][psunI]; 
    	}
    	
    	double p = 0;
    	p += PS * psun * PW * dfs(win+1, lose, psun + PU);
    	p += PS * psun * (1-PW) * dfs(win+1, lose, psun);
    	p += (1-PS) * psun * PL * dfs(win, lose+1, psun - PD);
    	p += (1-PS) * psun * (1-PL) * dfs(win, lose+1, psun);
    	
    	p += PR * (1-psun) * PW * dfs(win+1, lose, psun + PU);
    	p += PR * (1-psun) * (1-PW) * dfs(win+1, lose, psun);
    	p += (1-PR) * (1-psun) * PL * dfs(win, lose+1, psun - PD);
    	p += (1-PR) * (1-psun) * (1-PL) * dfs(win, lose+1, psun);
    	
    	cache[win][lose][psunI] = p;
    	return p;
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
		new C().run();
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

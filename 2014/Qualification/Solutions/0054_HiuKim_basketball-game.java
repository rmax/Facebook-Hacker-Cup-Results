import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class B {	
	BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter out;
    
    class Player {
    	String name;
    	int rate;
    	int height;
    	
    	int rank;
    	int played = 0;
    	public Player(String name, int rate, int height) {
    		this.name = name;
    		this.rate = rate;
    		this.height = height;
    	}
    }
    
    public void task() throws IOException {
    	int N = nextInt();
    	int M = nextInt();
    	int P = nextInt();
    	Player[] players = new Player[N];
    	for(int i = 0; i < N; i++){
    		String[] ss = reader.readLine().split(" ");
    		players[i] = new Player(ss[0], Integer.parseInt(ss[1]), Integer.parseInt(ss[2]));
    	}
    	Arrays.sort(players, new Comparator<Player>(){
    		@Override
    		public int compare(Player a, Player b){
    			if(a.rate > b.rate) return -1;
    			if(a.rate == b.rate && a.height > b.height) return -1;
    			return 1;
    		}
    	});
    	for(int i = 0; i < N; i++){
    		players[i].rank = i;
    	}
    	
    	ArrayList<Player> team1 = new ArrayList<Player>();
    	ArrayList<Player> team2 = new ArrayList<Player>();
    	for(int i = 0; i < N; i++){
    		if(i % 2 == 0)
    			team1.add(players[i]);
    		else
    			team2.add(players[i]);
    	}
    	
    	Comparator<Player> pc = new Comparator<Player>(){
    		@Override
    		public int compare(Player a, Player b){
    			if(a.played > b.played) return -1;
    			if(a.played == b.played && a.rank > b.rank) return -1;
    			return 1;    				
    		}
    	};
    	Comparator<Player> rc = new Comparator<Player>(){
    		@Override
    		public int compare(Player a, Player b){
    			if(a.played < b.played) return -1;
    			if(a.played == b.played && a.rank < b.rank) return -1;
    			return 1;    				
    		}
    	};
    	PriorityQueue<Player> p1 = new PriorityQueue<Player>(11, pc);
    	PriorityQueue<Player> p2 = new PriorityQueue<Player>(11, pc);
    	PriorityQueue<Player> r1 = new PriorityQueue<Player>(11, rc);
    	PriorityQueue<Player> r2 = new PriorityQueue<Player>(11, rc);
    	
    	for(int i = 0; i < team1.size(); i++){
    		if(i < P){
    			p1.add(team1.get(i));    			
    		} else{
    			r1.add(team1.get(i));
    		}
    	}
    	for(int i = 0; i < team2.size(); i++){
    		if(i < P){
    			p2.add(team2.get(i));    			
    		} else{
    			r2.add(team2.get(i));
    		}
    	}
    	
    	
    	for(int i = 0; i < M; i++){
    		for(Player p: p1) {
    			p.played++;
    		}
    		for(Player p: p2) {
    			p.played++;
    		}
    		r1.add(p1.remove());
    		p1.add(r1.remove());
    		r2.add(p2.remove());
    		p2.add(r2.remove());
    	}
    	
    	ArrayList<String> ans = new ArrayList<String>();
    	for(Player p: p1) {
			ans.add(p.name);
		}
		for(Player p: p2) {
			ans.add(p.name);
		}
		Collections.sort(ans);
		
		for(int i = 0; i < ans.size(); i++){
			out.print(ans.get(i));
			if(i < ans.size()-1){
				out.print(" ");
			}
		}
		out.println();
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
		new B().run();
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

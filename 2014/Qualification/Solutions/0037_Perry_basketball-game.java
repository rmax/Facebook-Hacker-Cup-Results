import java.util.*;

public class R0B {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int ncs = sc.nextInt();
		for(int cs = 0; cs < ncs; cs++) {
			int n = sc.nextInt(); // num people
			int m = sc.nextInt(); // num rotations/mins
			int p = sc.nextInt(); // max ppl on
			
			Player[] players = new Player[n];
			for(int i = 0; i < n; i++) players[i] = new Player(sc.next(), sc.nextInt(), sc.nextInt());
			
			Arrays.sort(players, new Comparator<Player>() {
				public int compare(Player o1, Player o2) {
					if(o1.percent != o2.percent) return o2.percent - o1.percent;
					return o2.height - o1.height;
				}
			});
			for(int i = 0; i < players.length; i++) players[i].draftn = i;
			for(int i = 0; i < 2 * p; i++) players[i].in = true;
			Player[] t1 = new Player[n % 2 == 1 ? n/2+1 : n/2], t2 = new Player[n/2];
			for(int i = 0; i < n; i += 2){
				t1[i/2] = players[i];
				if(i + 1 < n) t2[i/2] = players[i+1];
			}
			for(int i = 0; i < m; i++) {
				turn(t1, p);
				turn(t2, p);
			}
			
			String[] names = new String[2 * p];
			int wr = 0;
			for(Player pl : players)
				if(pl.in) names[wr++] = pl.name;
			Arrays.sort(names);
			System.out.printf("Case #%d: %s\n", cs+1, Arrays.toString(names).replaceAll("[\\[\\],]", ""));
		}
	}
	
	static void turn(Player[] players, int p) {
		for(Player pl : players) 
			if(pl.in) pl.time++;
		if(players.length <= p) return;
		Player leave = players[0];
		for(Player pl : players) 
			if(pl.in && (!leave.in || pl.time > leave.time || (pl.time == leave.time && pl.draftn > leave.draftn))) leave = pl;
		Player enter = players[0];
		for(Player pl : players)
			if(!pl.in && (enter.in || pl.time < enter.time || (pl.time == enter.time && pl.draftn < enter.draftn))) enter = pl;
		leave.in = !(enter.in = true);

	}
	
	static class Player {
		String name;
		int percent, height;
		
		public int draftn = 0;
		public boolean in = false;
		public int time = 0;
		
		public Player(String name, int percent, int height) {
			super();
			this.name = name;
			this.percent = percent;
			this.height = height;
		}

		@Override
		public String toString() {
			return "Player [name=" + name + "]";
		}
		
	}
	
}

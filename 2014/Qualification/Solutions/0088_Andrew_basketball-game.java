import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class BasketballGame {

	public void run() {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			int P = sc.nextInt();
			sc.nextLine();
			List<Player> players = new ArrayList<Player>();
			
			for (int n = 0; n < N; n++) {
				String[] stats = sc.nextLine().split(" ");
				
				Player player = new Player(stats[0], Integer.parseInt(stats[1]), Integer.parseInt(stats[2]));
				
				players.add(player);
			}

			String answer = solve(players, P, M);

			System.out.println(String.format("Case #%d: %s", t, answer));
		}

	}

	private String solve(List<Player> players, int numPlaying, int minutes) {
		calculateDraft(players);
		Team[] teams = getTeams(players);
		Team team1 = teams[0];
		Team team2 = teams[1];
		
		Court court1 = new Court(team1, numPlaying);
		Court court2 = new Court(team2, numPlaying);
		
		while (minutes > 0) {
			court1.updateMinutes();
			court2.updateMinutes();
			court1.substitute(team1);
			court2.substitute(team2);
			minutes--;
		}
		
		List<Player> remaining = new ArrayList<Player>();
		remaining.addAll(court1.players);
		remaining.addAll(court2.players);
		
		return getSortedNames(remaining);
	}

	private String getSortedNames(List<Player> remaining) {
		List<String> names = new ArrayList<String>();
		
		for(Player player : remaining) {
			names.add(player.name);
		}
		
		Collections.sort(names);
		String namesString = "";
		
		for(String name : names) {
			namesString += name + " ";
		}
		
		return namesString.trim();
	}

	private Team[] getTeams(List<Player> sortedPlayers) {
		Team team1 = new Team();
		Team team2 = new Team();
		
		for(int i=1; i<=sortedPlayers.size(); i++) {
			if (i%2==1) team1.players.add(sortedPlayers.get(i-1));
			else team2.players.add(sortedPlayers.get(i-1));
		}
		
		return new Team[] {team1, team2};
	}

	private void calculateDraft(List<Player> players) {
		Collections.sort(players);
		Collections.reverse(players);
		
		int r=1;
		for(Player player : players) {
			player.rank = r;
			r++;
		}
		
	}

	public static void main(String[] args) {
		BasketballGame bg = new BasketballGame();
		bg.run();
	}
	
	public class Player implements Comparable<Player> {
		String name;
		int shotPct;
		int height;
		int rank;
		int minutes;
		
		public Player(String n, int s, int h) {
			name = n;
			shotPct = s;
			height = h;
			minutes = 0;
		}

		@Override
		public int compareTo(Player otherPlayer) {
			if (this.shotPct == otherPlayer.shotPct) {
				return this.height > otherPlayer.height ? 1:-1;
			}
			
			return this.shotPct > otherPlayer.shotPct ? 1:-1;
		}
	}
	
	public class PlayerCollection {
		List<Player> players;
		
		public PlayerCollection() {
			players = new ArrayList<Player>();
		}
	}
	
	public class Team extends PlayerCollection {
		
		public Team() {
			super();
		}
		
		Player getBestPlayer() {
			Player bestPlayer = null;
			
			for(Player player : players) {
				if (bestPlayer == null || player.rank < bestPlayer.rank) bestPlayer = player;
			}
			
			players.remove(bestPlayer);
			
			return bestPlayer;
		}
		
	}
	
	public class Court extends PlayerCollection {
		
		public Court() {
			super();
		}
		
		public Court(Team team, int numPlaying) {
			for(int p=1; p<=numPlaying; p++) {
				players.add(team.getBestPlayer());
			}
		}
		
		public void substitute(Team bench) {
			if (bench.players.size() > 0) {
				Player nextOff = null;
				Player nextOn = null;
				
				for(Player player : bench.players) {
					if (nextOn == null) nextOn = player;
					else if (player.minutes == nextOn.minutes && player.rank < nextOn.rank) nextOn = player; 
					else if (player.minutes < nextOn.minutes) nextOn = player;
				}
				
				for(Player player : players) {
					if (nextOff == null) nextOff = player;
					else if (player.minutes == nextOff.minutes && player.rank > nextOff.rank) nextOff = player; 
					else if (player.minutes > nextOff.minutes) nextOff = player;
				}
				
				players.add(nextOn);
				bench.players.add(nextOff);
				
				bench.players.remove(nextOn);
				players.remove(nextOff);
			}
		}
		
		public void updateMinutes() {
			for(Player player : players) {
				player.minutes++;
			}
		}
	}

}


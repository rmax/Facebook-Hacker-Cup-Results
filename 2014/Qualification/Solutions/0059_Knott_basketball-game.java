import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class BasketballGame {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		new BasketballGame();
	}

	int T;

	public BasketballGame() throws FileNotFoundException {
		String inputFile = "/Users/kwittawat/Downloads/basketball_game.txt";
		Scanner scanner = new Scanner(new File(inputFile));
		T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = scanner.nextInt();
			int M = scanner.nextInt();
			int P = scanner.nextInt();
			Player[] players = new Player[N];
			for (int j = 0; j < N; j++) {
				players[j] = new Player(scanner.next(), scanner.nextInt(), scanner.nextInt());
			}
			System.out.println("Case #" + i + ": " + solve(N, M, P, players));
		}
	}

	private class Player {

		String name;
		int shotPercentage, height, draftNumber, minutesPlayed = 0;

		public Player(String name, int shotPercentage, int height) {
			this.name = name;
			this.shotPercentage = shotPercentage;
			this.height = height;
		}

		@Override
		public String toString() {
			return this.name+"("+this.minutesPlayed+")";
		}
	}

	private String solve(int N, int M, int P, Player[] players) {
		// Sort players by draft number
		Arrays.sort(players, draftNumberComparator);
		// Assign draft number and set each player a team.
		// Then, put him on a game or a bench
		Queue<Player>[] bench = new Queue[2];
		HashSet<Player>[] game = new HashSet[2];
		for (int i = 0; i < 2; i++) {
			bench[i] = new PriorityQueue<Player>(P, benchComparator);
			game[i] = new HashSet<Player>();
		}
		for (int i = 0; i < players.length; i++) {
			players[i].draftNumber = (i+1);
			if (i % 2 == 0) {
				if (game[0].size() < P) {
					game[0].add(players[i]);
				} else {
					bench[0].add(players[i]);
				}
			} else {
				if (game[1].size() < P) {
					game[1].add(players[i]);
				} else {
					bench[1].add(players[i]);
				}
			}
		}
		// Run the game
		for (int i = 0; i < M; i++) {
			// Increase minutes played of each player in the game
			for (int j = 0; j < 2; j++) {
				Iterator<Player> iter = game[j].iterator();
				while (iter.hasNext()) {
					Player player = iter.next();
					player.minutesPlayed++;
				}

				if (!bench[j].isEmpty()) {
					// Search for a player who needs to leave
					Player playerToBench = null;
					iter = game[j].iterator();
					while (iter.hasNext()) {
						Player player = iter.next();
						if (playerToBench == null)
							playerToBench = player;
						else {
							if (player.minutesPlayed > playerToBench.minutesPlayed) {
								playerToBench = player;
							} else if (player.minutesPlayed == playerToBench.minutesPlayed) {
								if (player.draftNumber > playerToBench.draftNumber) {
									playerToBench = player;
								}
							}
						}
					}
				
					// Search for a player in the bench to play
					Player playerToGame = bench[j].remove();
					game[j].add(playerToGame);

					game[j].remove(playerToBench);
					bench[j].add(playerToBench);
				}
			}
		}
		
		// Sort all players in the game to result
		ArrayList<Player> allPlayersInGame = new ArrayList<Player>(players.length);
		for (int i = 0; i < 2; i++) {
			Iterator<Player> iter = game[i].iterator();
			while (iter.hasNext()) {
				allPlayersInGame.add(iter.next());
			}
		}
		Player[] result = new Player[allPlayersInGame.size()];
		for (int i = 0; i < allPlayersInGame.size(); i++) {
			result[i] = allPlayersInGame.get(i);
		}
		Arrays.sort(result, nameComparator);
		StringBuffer answer = new StringBuffer();
		for (Player p: result) {
			answer.append(p.name+" ");
		}
		
		return answer.substring(0, answer.length()-1);
	}
	
	Comparator<Player> draftNumberComparator = new Comparator<Player>() {
		@Override
		public int compare(Player o1, Player o2) {
			if (o1.shotPercentage > o2.shotPercentage) {
				return -1;
			} else if (o1.shotPercentage < o2.shotPercentage) {
				return 1;
			} else {
				if (o1.height > o2.height) {
					return -1;
				} else {
					// It's sure that there is no player with same shot percentage & height
					return 1;
				}
			}
		}
	}; 
	
	Comparator<Player> benchComparator = new Comparator<Player>() {
		@Override
		public int compare(Player o1, Player o2) {
			if (o1.minutesPlayed < o2.minutesPlayed) {
				return -1;
			} else if (o1.minutesPlayed > o2.minutesPlayed) {
				return 1;
			} else {
				if (o1.draftNumber < o2.draftNumber) {
					return -1;
				} else {
					return 1;
				}
			}
		}
	}; 
	
	Comparator<Player> nameComparator = new Comparator<Player>() {
		@Override
		public int compare(Player o1, Player o2) {
			return o1.name.compareTo(o2.name);
		}
	}; 

}

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.lang.reflect.Constructor;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class FacebookB 
{
	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		public String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException());
			}
		}
		
		public String next()
		{
			while(!st.hasMoreTokens())
			{
				String l = nextLine();
				if(l == null)
					return null;
				st = new StringTokenizer(l);
			}
			return st.nextToken();
		}
		
		public int nextInt()
		{
			return Integer.parseInt(next());
		}
		
		public long nextLong()
		{
			return Long.parseLong(next());
		}
		
		public double nextDouble()
		{
			return Double.parseDouble(next());
		}
		
		public int[] nextIntArray(int n)
		{
			int[] res = new int[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextInt();
			return res;
		}
		
		public long[] nextLongArray(int n)
		{
			long[] res = new long[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextLong();
			return res;
		}
		
		public double[] nextDoubleArray(int n)
		{
			double[] res = new double[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextDouble();
			return res;
		}
		public void sortIntArray(int[] array)
		{
			Integer[] vals = new Integer[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortLongArray(long[] array)
		{
			Long[] vals = new Long[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
		
		public void sortDoubleArray(double[] array)
		{
			Double[] vals = new Double[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}

		public String[] nextStringArray(int n) 
		{	
			String[] vals = new String[n];
			for(int i = 0; i < n; i++)
				vals[i] = next();
			return vals;
		}
		
		public Integer nextInteger()
		{
			String s = next();
			if(s == null)
				return null;
			return Integer.parseInt(s);
		}
		
		public int[][] nextIntMatrix(int n, int m)
		{
			int[][] ans = new int[n][];
			for(int i = 0; i < n; i++)
				ans[i] = nextIntArray(m);
			return ans;
		}
		
		public char[][] nextGrid(int r) 
		{
			char[][] grid = new char[r][];
			for(int i = 0; i < r; i++)
				grid[i] = next().toCharArray();
			return grid;
		}
		
		public static <T> T fill(T arreglo, int val)
		{
			if(arreglo instanceof Object[])
			{
				Object[] a = (Object[]) arreglo;
				for(Object x : a)
					fill(x, val);
			}
			else if(arreglo instanceof int[])
				Arrays.fill((int[]) arreglo, val);
			else if(arreglo instanceof double[])
				Arrays.fill((double[]) arreglo, val);
			else if(arreglo instanceof long[])
				Arrays.fill((long[]) arreglo, val);
			return arreglo;
		}
		
		<T> T[] nextObjectArray(Class <T> clazz, int size)
		{
			@SuppressWarnings("unchecked")
			T[] result = (T[]) java.lang.reflect.Array.newInstance(clazz, size);
			for(int c = 0; c < 3; c++)
			{
				Constructor <T> constructor;
				try 
				{
					if(c == 0)
						constructor = clazz.getDeclaredConstructor(Scanner.class, Integer.TYPE);
					else if(c == 1)
						constructor = clazz.getDeclaredConstructor(Scanner.class);
					else
						constructor = clazz.getDeclaredConstructor();
				} 
				catch(Exception e)
				{
					continue;
				}
				try
				{
					for(int i = 0; i < result.length; i++)
					{
						if(c == 0)
							result[i] = constructor.newInstance(this, i);
						else if(c == 1)
							result[i] = constructor.newInstance(this);
						else
							result[i] = constructor.newInstance();	
					}
				}
				catch(Exception e)
				{
					throw new RuntimeException(e);
				}
				return result;
			}
			throw new RuntimeException("Constructor not found");
		}
		
		public void printLine(int... vals)
		{
			if(vals.length == 0)
				System.out.println();
			else
			{
				System.out.print(vals[0]);
				for(int i = 1; i < vals.length; i++)
					System.out.print(" ".concat(String.valueOf(vals[i])));
				System.out.println();
			}
		}
		
		public void printLine(long... vals)
		{
			if(vals.length == 0)
				System.out.println();
			else
			{
				System.out.print(vals[0]);
				for(int i = 1; i < vals.length; i++)
					System.out.print(" ".concat(String.valueOf(vals[i])));
				System.out.println();
			}
		}
		
		public void printLine(double... vals)
		{
			if(vals.length == 0)
				System.out.println();
			else
			{
				System.out.print(vals[0]);
				for(int i = 1; i < vals.length; i++)
					System.out.print(" ".concat(String.valueOf(vals[i])));
				System.out.println();
			}
		}
		
		public void printLine(int prec, double... vals)
		{
			if(vals.length == 0)
				System.out.println();
			else
			{
				System.out.printf("%." + prec + "f", vals[0]);
				for(int i = 1; i < vals.length; i++)
					System.out.printf(" %." + prec + "f", vals[i]);
				System.out.println();
			}
		}
		
		public Collection <Integer> wrap(int[] as)
		{
			ArrayList <Integer> ans = new ArrayList <Integer> ();
			for(int i : as)
				ans.add(i);
			return ans;
		}
		
		public int[] unwrap(Collection <Integer> collection)
		{
			int[] vals = new int[collection.size()];
			int index = 0;
			for(int i : collection) vals[index++] = i;
			return vals;
		}
	}

	static class Player
	{
		int shotPercentage;
		int height;
		int playedMinutes = 0;
		String name;
		int draftNumber = 0;
		
		public Player(Scanner sc)
		{
			name = sc.next();
			shotPercentage = sc.nextInt();
			height = sc.nextInt();
		}
	}
	
	static final Comparator <Player> draftComparator = new Comparator <Player> () 
	{
		@Override
		public int compare(Player o1, Player o2) 
		{
			if(o1.shotPercentage != o2.shotPercentage)
				return o2.shotPercentage - o1.shotPercentage;
			return o2.height - o1.height;
		}
	};
	
	static final Comparator <Player> onCourtComparator = new Comparator <Player> () 
	{
		@Override
		public int compare(Player o1, Player o2) 
		{
			if(o1.playedMinutes != o2.playedMinutes)
				return o2.playedMinutes - o1.playedMinutes;
			return o2.draftNumber - o1.draftNumber;
		}
	};
	
	static final Comparator <Player> offCourtComparator = new Comparator <Player> () 
	{
		@Override
		public int compare(Player o1, Player o2) 
		{
			if(o1.playedMinutes != o2.playedMinutes)
				return o1.playedMinutes - o2.playedMinutes;
			return o1.draftNumber - o2.draftNumber;
		}
	};

	static final Comparator <Player> nameComparator = new Comparator <Player> () 
	{
		@Override
		public int compare(Player o1, Player o2) 
		{
			return o1.name.compareTo(o2.name);
		}
	};
	
	static List <Player> solve(ArrayList <Player> allPlayers, int n, int m, int p)
	{
		if(allPlayers.size() <= p)
			return allPlayers;
		LinkedList <Player> onCourt = new LinkedList <Player> ();
		TreeSet <Player> offCourt = new TreeSet <Player> (offCourtComparator);
		for(int i = 0; i < p; i++)
			onCourt.add(allPlayers.get(i));
		for(int i = p; i < allPlayers.size(); i++)
			offCourt.add(allPlayers.get(i));
		for(int i = 0; i < m; i++)
		{
			for(Player p1 : onCourt)
				p1.playedMinutes++;
			Collections.sort(onCourt, onCourtComparator);
			Player out = onCourt.pollFirst();
			Player in = offCourt.pollFirst();
			onCourt.add(in);
			offCourt.add(out);
		}
		return onCourt;
	}
	
	public static void main(String[] args) throws FileNotFoundException
	{
		System.setIn(new FileInputStream("inputB.in"));
		System.setOut(new PrintStream("outputB.out"));
		Scanner sc = new Scanner();
		int t = sc.nextInt();
		for(int c = 1; c <= t; c++)
		{
			int n = sc.nextInt();
			int m = sc.nextInt();
			int p = sc.nextInt();
			Player[] players = sc.nextObjectArray(Player.class, n);
			Arrays.sort(players, draftComparator);
			for(int i = 0; i < n; i++)
				players[i].draftNumber = i + 1;
			ArrayList <Player> teamA = new ArrayList <Player> ();
			ArrayList <Player> teamB = new ArrayList <Player> ();
			for(int i = 0; i < n; i++)
				(((i & 1) == 0) ? teamA : teamB).add(players[i]);
			ArrayList <Player> answer = new ArrayList <Player> ();
			answer.addAll(solve(teamA, n, m, p));
			answer.addAll(solve(teamB, n, m, p));
			Collections.sort(answer, nameComparator);
			System.out.print("Case #" + c + ":");
			for(Player p1 : answer)
				System.out.print(" " + p1.name);
			System.out.println();
		}
	}
}
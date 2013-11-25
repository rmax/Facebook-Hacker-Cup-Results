import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
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
			int m = readInt();
			int p = readInt();
			PriorityQueue<StartState> q = new PriorityQueue<StartState>();
			while(n-- > 0) {
				q.add(new StartState(nextToken(), readInt(), readInt()));
			}
			ArrayList<State> list = new ArrayList<State>();
			int draft = 0;
			while(!q.isEmpty()) {
				StartState temp = q.poll();
				State curr = new State(temp.name, draft++, 0);
				list.add(curr);
			}
			TreeSet<State> playingSet1 = new TreeSet<State>(new RemoveCompare());
			TreeSet<State> benchSet1 = new TreeSet<State>(new PlayCompare());
			TreeSet<State> playingSet2 = new TreeSet<State>(new RemoveCompare());
			TreeSet<State> benchSet2 = new TreeSet<State>(new PlayCompare());
			while(playingSet1.size() < p) {
				playingSet1.add(list.remove(0));
				playingSet2.add(list.remove(0));
			}
			while(!list.isEmpty()) {
				benchSet1.add(list.remove(0));
				if(!list.isEmpty()) {
					benchSet2.add(list.remove(0));
				}
			}
			while(m-- > 0) {
				update(playingSet1, benchSet1);
				update(playingSet2, benchSet2);
			}
			PriorityQueue<String> qqq = new PriorityQueue<String>();
			for(State out: playingSet1) {
				qqq.add(out.name);
			}
			for(State out: playingSet2) {
				qqq.add(out.name);
			}
			StringBuilder sb = new StringBuilder();
			while(!qqq.isEmpty()) {
				sb.append(qqq.poll() + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	public static void update(TreeSet<State> playingSet, TreeSet<State> benchSet) {
		TreeSet<State> newPlaying = new TreeSet<State>(new RemoveCompare());
		for(State out: playingSet) {
			out.time++;
			newPlaying.add(out);
		}
		playingSet.clear();
		playingSet.addAll(newPlaying);
		if(!benchSet.isEmpty()) {
			State remove = playingSet.first();
			playingSet.remove(remove);
			State include = benchSet.first();
			benchSet.remove(include);
			benchSet.add(remove);
			playingSet.add(include);
		}
	}

	static class PlayCompare implements Comparator<State> {
		public int compare(State a, State b) {
			if(a.time != b.time) {
				return a.time - b.time;
			}
			return a.draft - b.draft;
		}
	}

	static class RemoveCompare implements Comparator<State> {
		public int compare(State a, State b) {
			if(a.time != b.time) {
				return b.time - a.time;
			}
			return b.draft - a.draft;
		}
	}

	static class State {
		public String name;
		public int draft;
		public int time;
		public State(String name, int draft, int time) {
			super();
			this.name = name;
			this.draft = draft;
			this.time = time;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + draft;
			result = prime * result + ((name == null) ? 0 : name.hashCode());
			result = prime * result + time;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (draft != other.draft)
				return false;
			if (name == null) {
				if (other.name != null)
					return false;
			} else if (!name.equals(other.name))
				return false;
			if (time != other.time)
				return false;
			return true;
		}
		@Override
		public String toString() {
			return "State [name=" + name + ", draft=" + draft + ", time="
					+ time + "]";
		}

	}

	static class StartState implements Comparable<StartState>{
		public String name;
		public int p,h;
		public StartState(String name, int p, int h) {
			super();
			this.name = name;
			this.p = p;
			this.h = h;
		}
		public int compareTo(StartState s) {
			if(s.p != p) {
				return s.p - p;
			}
			return s.h - h;
		}
		@Override
		public String toString() {
			return "StartState [name=" + name + ", p=" + p + ", h=" + h + "]";
		}
		
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
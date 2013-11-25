import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class BasketBallGame
{
    private static class Player implements Comparable<Player> {
        public String name;
        public int shotPercent;
        public int height;
        public int time;
        public Player(String n, int s, int h) {
            name = n;
            shotPercent = s;
            height = h;
            time = 0;
        }
        public int compareTo(Player p) {
            if(time != p.time) {
                return p.time-time;
            } else if(shotPercent != p.shotPercent) {
                return shotPercent-p.shotPercent;
            } else {
                return height-p.height;
            }
        }
    }
    public static void main (String [] args) throws Exception 
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st = new StringTokenizer(in.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            Player[] players = new Player[N];
            for(int i=0;i<N;i++) {
                st = new StringTokenizer(in.readLine());
                players[i] = new Player(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }
            Arrays.sort(players);
            Player[] bench1 = new Player[(N+1)/2-P];
            Player[] bench2 = new Player[N/2-P];
            Player[] onField1 = new Player[P];
            Player[] onField2 = new Player[P];
            int onFieldNum = 0;
            for(int i=0;i<N;i++) {
                if(i%2==0) {
                    if(i<N-2*P) {
                        bench1[i/2] = players[i];
                    } else {
                        onField1[onFieldNum/2] = players[i];
                        onFieldNum++;
                    }
                } else {
                    if(i<N-2*P) {
                        bench2[i/2] = players[i];
                    } else {
                        onField2[onFieldNum/2] = players[i];
                        onFieldNum++;
                    }
                }
            }
            for(int i=0;i<M;i++) {
                for(int j=0;j<P;j++) {
                    onField1[j].time++;
                    onField2[j].time++;
                }
                Arrays.sort(onField1);
                Arrays.sort(onField2);
                Arrays.sort(bench1);
                Arrays.sort(bench2);
                if(bench1.length>0) {
                    Player temp = bench1[bench1.length-1];
                    bench1[bench1.length-1] = onField1[0];
                    onField1[0] = temp;
                }
                if(bench2.length>0) {
                    Player temp = bench2[bench2.length-1];
                    bench2[bench2.length-1] = onField2[0];
                    onField2[0] = temp;
                }
            }
            ArrayList<String> names = new ArrayList<String>();
            for(int i=0;i<P;i++) {
                names.add(onField1[i].name);
                names.add(onField2[i].name);
            }
            Collections.sort(names);
            System.out.print("Case #"+(t+1)+":");
            for(String name: names) {
                System.out.print(" "+name);
            }
            System.out.println();
        }
    }
}

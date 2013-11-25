import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Tennison
{
    private static class Pair {
        public int first;
        public double second;
        public Pair(int f, double s) {
            first = f;
            second = s;
        }
        public int hashCode() {
            return first+(int)(second*1000000);
        }
    
        public boolean equals(Object obj) {
            if (obj == null)
                return false;
            if (obj == this)
                return true;
            if (!(obj instanceof Pair))
                return false;
    
            Pair rhs = (Pair) obj;
            return first==rhs.first&&second==rhs.second;
        }
    }
    public static void main (String [] args) throws Exception 
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=1;t<=T;t++) {
            st = new StringTokenizer(in.readLine());
            int K = Integer.parseInt(st.nextToken());
            double ps = Double.parseDouble(st.nextToken());
            double pr = Double.parseDouble(st.nextToken());
            double pi = Double.parseDouble(st.nextToken());
            double pu = Double.parseDouble(st.nextToken());
            double pw = Double.parseDouble(st.nextToken());
            double pd = Double.parseDouble(st.nextToken());
            double pl = Double.parseDouble(st.nextToken());
            HashMap<Pair,Double> gameChance = new HashMap<Pair,Double>();
            gameChance.put(new Pair(0, pi), 1.0);
            double ans = 0;
            for(int i=0;i<2*K-1;i++) { //Played i games
                HashMap<Pair,Double> nextChance = new HashMap<Pair,Double>();
                Iterator it = gameChance.entrySet().iterator();
                while (it.hasNext()) {
                    Map.Entry pairs = (Map.Entry)it.next();
                    Pair p = (Pair)pairs.getKey();
                    int j = p.first;
                    double k = p.second;
                    double thisChance = (Double)pairs.getValue();
                    if(j < Math.max(0, i-K)) continue;
                    if(j > Math.min(K-1,i)) continue;
                    double winChance = ps*k + pr*(1-k);
                    if(i+1-j < K) {
                        if(nextChance.containsKey(new Pair(j, k))) {
                            double curr = nextChance.get(new Pair(j, k));
                            nextChance.put(new Pair(j, k), curr + thisChance*(1-winChance)*(1-pl));
                        } else {
                            nextChance.put(new Pair(j, k), thisChance*(1-winChance)*(1-pl));
                        }
                        if(nextChance.containsKey(new Pair(j, Math.max(0, k-pd)))) {
                            double curr = nextChance.get(new Pair(j, Math.max(0, k-pd)));
                            nextChance.put(new Pair(j, Math.max(0, k-pd)), curr + thisChance*(1-winChance)*pl);
                        } else {
                            nextChance.put(new Pair(j, Math.max(0, k-pd)), thisChance*(1-winChance)*pl);
                        }
                    }
                    if(j+1 == K) {
                        ans += thisChance*winChance;
                    } else if(j+1 < K) {
                        if(nextChance.containsKey(new Pair(j+1, k))) {
                            double curr = nextChance.get(new Pair(j+1, k));
                            nextChance.put(new Pair(j+1, k), curr + thisChance*winChance*(1-pw));
                        } else {
                            nextChance.put(new Pair(j+1, k), thisChance*winChance*(1-pw));
                        }
                        if(nextChance.containsKey(new Pair(j+1, Math.min(1, k+pu)))) {
                            double curr = nextChance.get(new Pair(j+1, Math.min(1, k+pu)));
                            nextChance.put(new Pair(j+1, Math.min(1, k+pu)), curr + thisChance*winChance*pw);
                        } else {
                            nextChance.put(new Pair(j+1, Math.min(1, k+pu)), thisChance*winChance*pw);
                        }
                    }
                }
                gameChance = nextChance;
            }
            BigDecimal d = new BigDecimal(ans);
            d = d.setScale(6, BigDecimal.ROUND_HALF_UP);
            System.out.println("Case #"+t+": "+d.toString());
        }
    }
}

import java.io.IOException;
import java.util.*;

public class Main{
    public static void main(String [] args) throws IOException{
        Scanner in = new Scanner(System.in);

        int T = in.nextInt(), N;
        int[] dp;
        for(int t =0; t< T;t++){
            N = in.nextInt();
            dp = new int[N+1];
            dp[0] = 1;
            for(int i = 1; i<=N; i++){
                for(int c =1; c<=3;c++){
                    if(i - c >= 0){
                        dp[i] += dp[i-c];
                    }
                }
            }
            System.out.println(dp[N]);
        }
    }
}
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int dp[];
        int coins[];
        for(int i =0; i< T; i++){
            int N = sc.nextInt();
            coins = new int[N+1];
            for(int j=1; j<=N; j++){
                coins[j] = sc.nextInt();
            }
            int M = sc.nextInt();
            dp = new int[M+1];
            dp[0] =1;
            for(int num=1; num<= N; num++){
                for(int val= coins[num]; val <=M; val++){
                    dp[val] += dp[val - coins[num]]; 
                }
            }
            System.out.println(dp[M]);
        }
    }
}
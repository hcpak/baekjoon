import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), k = sc.nextInt(), answer =0;
        int[] weight = new int[n+1], value = new int[n+1]; 
        int[][] dp = new int[n+1][k+1];
        for(int i = 1; i <= n; i++){
            weight[i] = sc.nextInt();
            value[i] = sc.nextInt();
        }

        for(int i=1; i<=n; i++){
            for(int val=1; val<= k; val++){
                dp[i][val] = dp[i-1][val];
                if(val - weight[i]>=0){
                    dp[i][val] = Math.max(dp[i][val], dp[i-1][val-weight[i]] + value[i]);
                }
                answer = Math.max(answer, dp[i][val]);
            }
        }
        System.out.println(answer);
    }
}
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int[] dp = new int[x+1];
        int[] before = new int[x+1];
        before[1] = 0;
        for(int i =2; i <= x; i++){
            dp[i] = dp[i-1] +1;
            before[i] = i-1;
            if(i%2 ==0 && dp[i] > dp[i/2] +1){
                dp[i] = dp[i/2] +1;
                before[i] = i/2;
            }

            if(i%3 ==0 && dp[i] > dp[i/3] +1){
                dp[i] = dp[i/3] +1;
                before[i] = i/3;
            }
        }
        System.out.println(dp[x]);
        int i = x;
        while(i != 0){
            System.out.print(i+" ");
            i = before[i];
        }
    }
}

import java.io.IOException;
import java.util.*;

public class Main{
    public static void main(String [] args) throws IOException{
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int[] dp = new int[N+1];
        for(int i =1; i<= N;i++){
            dp[i] = dp[i-1] +1;
            if(i/2 == 0){
                dp[i] = dp[i/2] +1;
            }
            if(i/3 == 0){
                dp[i] = dp[i/3] +1;
            }
        }
        System.out.println(dp[N]);
    }
}

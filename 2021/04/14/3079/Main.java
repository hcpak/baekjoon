

import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong(), M = sc.nextLong();
        long max = 0;
        long[] arr = new long[(int)N+1];
        for(int i =1; i <= N; i++){
            arr[i] = sc.nextInt();
            max = Math.max(max,arr[i]);
        }
        long start = 0l, end = max*M+1;
        while(start+1< end){
            long mid = (start+end)/2, sum = 0l;
            for(int i=1; i<= N;i++){
                sum += mid/arr[i];
            }
            if( sum<M){
                start = mid;
            }else{
                end = mid;
            }
        }
        System.out.println(end);
    }
}

import java.util.*;

public class Main{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);

        int N = in.nextInt(), M = in.nextInt();
        int[] arr = new int[N];
        for(int i =0; i< N;i++){
            arr[i] = in.nextInt();
        }
        int start = 1, end = 2000000001;
        while(end - start >1){
            int mid = (start + end)/2;
            long sum =0;
            for(int i=0; i < N; i++){
                if(arr[i] > mid){
                    sum += arr[i] - mid ;
                }
            }
            if(sum >= M){
                start = mid;
            }else{
                end = mid;
            }
        }
        System.out.println(start);
    }
}

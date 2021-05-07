import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt();
        int[] arr = new int[N];
        for(int i=0; i< N; i++){
            arr[i] = sc.nextInt();
        }
        int begin=0, end =0;
        long sum = arr[end], answer=0l;
        while(end < N){
            if(sum > M){
                sum -= arr[begin];
                begin++;
            }else{
                if(sum == M){
                    answer += 1;
                }
                end++;
                if(end ==N){
                    break;
                }
                sum += arr[end];
            }
        }
        System.out.println(answer);
    }

    
}

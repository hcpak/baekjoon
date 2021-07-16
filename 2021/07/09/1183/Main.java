import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] distance = new int[N];
        for(int i =0; i< N; i++){
            distance[i] = sc.nextInt() - sc.nextInt();
        }
        Arrays.sort(distance);
        if( N % 2 ==0){ // 짝수일때
            System.out.println(distance[N/2] - distance[N/2-1]+1);
        }else{ // 홀수일때
            System.out.println(1);
        }
    }
}
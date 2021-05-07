import java.util.*;
public class Main {
    static int N, answer =0;
    static int[] arr;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        arr = new int[N];
        for(int i=0; i < N; i++){
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        for(int i=0; i < N; i++){
            answer += (N -i) * arr[i];
        }
        System.out.println(answer);
    }
}

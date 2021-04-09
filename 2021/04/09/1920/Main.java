import java.util.*;

public class Main{
    public static void main(String [] args){
        Scanner in = new Scanner(System.in);

        int N = in.nextInt();
        int[] A = new int[N];
        for(int i =0; i< N;i++){
            A[i] = in.nextInt();
        }
        Arrays.sort(A);
        int M = in.nextInt();
        for(int i=0; i < M; i++){
            int target = in.nextInt();
            int left = 0, right = N;
            while(right - left >1){
                int mid = (left + right)/2;
                if(A[mid] <= target){
                    left = mid;
                }else{
                    right = mid;
                }
            }
            if(A[left] == target){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }
    }
}

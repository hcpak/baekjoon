import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(), max = 0;
        int[][] triangle = new int[n][n];
        for(int i =0; i< n; i++){
            for(int j = 0; j <= i; j++){
                if(i >=1){
                    if( j > 0){
                        triangle[i][j] = Math.max(triangle[i][j], triangle[i-1][j-1]);
                    }
                    if( j < i){
                        triangle[i][j] = Math.max(triangle[i][j], triangle[i-1][j]);
                    }
                }
                triangle[i][j] += sc.nextInt();
                max = Math.max(max, triangle[i][j]);
            }
        }
        System.out.println(max);
    }
}
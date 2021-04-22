import java.util.*;
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), weight[] = new int[N], height[] = new int[N];
        for(int i =0; i < N; i++){
            weight[i] = sc.nextInt();
            height[i] = sc.nextInt();
        }
        List<List<Integer>> rating = new ArrayList<>();
        for(int i =0; i< N;i++){
            rating.add(new ArrayList<>());
        }
        for(int i = 0; i < N; i++){
            for(int j =0; j< N; j++){
                if(weight[j] > weight[i] && height[j] > height[i]){
                    rating.get(i).add(j);
                }
            }
        }
        for(int i = 0; i < N; i++){
            System.out.print(rating.get(i).size()+1 +" ");
        }
    }
}

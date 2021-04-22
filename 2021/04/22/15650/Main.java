import java.util.*;
public class Main {
    static int N, M;
    static List<Integer> list;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        list = new ArrayList<>();
        dfs(1);
    }

    public static void dfs(int k ){
        if(list.size() == M){
            for(int i =0; i <list.size(); i++){
                System.out.print(list.get(i) +" ");
            }
            System.out.print("\n");
        }else{
            for(int i = k; i <= N ;i++){
                list.add(i);
                dfs(i+1);
                list.remove(list.size()-1);
            }
        }
    }
}

import java.util.*;
public class Main {
    static int N, M;
    static List<Integer> list;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        list = new ArrayList<>();
        dfs();
    }

    public static void dfs(){
        if(list.size() == M){
            for(int i =0; i <list.size(); i++){
                System.out.print(list.get(i) +" ");
            }
            System.out.print("\n");
        }else{
            for(int i = 1; i <= N ;i++){
                if(!list.contains(i)){
                    list.add(i);
                    dfs();
                    list.remove(list.size()-1);
                }
            }
        }
    }
}

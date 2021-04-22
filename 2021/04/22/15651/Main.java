import java.util.*;
public class Main {
    static int N, M;
    static List<Integer> list;
    static StringBuilder sb = new StringBuilder();
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        list = new ArrayList<>();
        dfs();
        System.out.println(sb);
    }

    public static void dfs(){
        if(list.size() == M){
            for(int i =0; i <list.size(); i++){
                sb.append(list.get(i) +" ");
            }
            sb.append('\n');
        }else{
            for(int i = 1; i <= N ;i++){
                list.add(i);
                dfs();
                list.remove(list.size()-1);
            }
        }
    }
}

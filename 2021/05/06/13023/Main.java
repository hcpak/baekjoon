import java.awt.Point;
import java.util.*;
public class Main {
    static int N, M;
    static List<List<Integer>> arr;
    static boolean[] visited;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        arr = new ArrayList<>();
        for(int i =0; i< N; i++){
            arr.add(new ArrayList<Integer>());
        }
        int a,b;
        for(int i =0; i< M; i++){
            a = sc.nextInt();
            b = sc.nextInt();
            arr.get(a).add(b);
            arr.get(b).add(a);
        }
        for(int i=0; i< N; i++){
            visited = new boolean[N];
            visited[i] = true;
            if(dfs(i,0)){
                System.out.println("1");
                return;
            }
        }
        System.out.println("0");
    }

    static boolean dfs(int start, int cnt){
        if(cnt == 4){
            return true;
        }
        for(int i=0; i < arr.get(start).size(); i++){
            int next = arr.get(start).get(i);
            if(visited[next] == false){
                visited[next] = true;
                if(dfs(next, cnt+1)){
                    return true;
                }
                visited[next] = false;
            }
        }
        return false;
    }

    static class point{
        int cur;
        int count;

        point(int cur, int count){
            this.cur = cur;
            this.count = count;
        }
    }
}

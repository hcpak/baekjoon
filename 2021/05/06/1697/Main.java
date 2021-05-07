import java.awt.Point;
import java.util.*;
public class Main {
    static int N, K, answer;
    static Queue<Integer> q;
    static int[] visited;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        bfs();
        System.out.println(answer);
    }

    static void bfs(){
        q = new LinkedList<>();
        visited = new int[100_001];
        q.add(N);
        while(!q.isEmpty()){
            int cur = q.poll();
            if(cur == K){
                answer = visited[cur];
                break;
            }
            visit(cur, cur-1);
            visit(cur, cur+1);
            visit(cur, 2*cur);
        }
    }

    static void visit(int cur, int next){
        if(rangeCheck(next) && visited[next] ==0){
            visited[next] = visited[cur] +1;
            q.add(next);
        }
    }
    static boolean rangeCheck(int cur){
        if(cur <0 || cur> 100_000){
            return false;
        }
        return true;
    }
}

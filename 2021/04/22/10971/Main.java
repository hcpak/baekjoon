import java.util.*;
public class Main {
    static int [][] graph;
    static int N, answer = Integer.MAX_VALUE;
    static StringBuilder sb = new StringBuilder();
    static boolean visited[];
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        graph = new int[N][N];
        for(int i = 0; i < N ; i++){
            for(int j = 0; j < N; j++){
                graph[i][j] = sc.nextInt();
            }
        }
        visited = new boolean[N];
        dfs(0,0,0);
        System.out.println(answer);
    }

    static void dfs(int visit_count, int cost, int last_city){
        if(visit_count == N -1 && graph[last_city][0] != 0){
            answer = Math.min(answer, cost + graph[last_city][0]);
        }else{
            for(int i=1; i< N; i++ ){
                if(!visited[i] && graph[last_city][i] != 0){
                    visited[i] = true;
                    dfs(visit_count+1, cost + graph[last_city][i], i);
                    visited[i] = false;
                }
            }
        }
    }
}

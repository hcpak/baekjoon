import java.util.*;
public class Main{
    static Set<Integer> a_set;
    static boolean[] visited;
    static int STACK_MAX_SIZE;
    static int[][] map;
    static int answer =Integer.MAX_VALUE;

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        map = new int[N+1][N+1];
        for(int y = 1; y <= N; y++){
            for(int x = 1; x <= N; x++){
                map[y][x] = in.nextInt();
            }
        }
        STACK_MAX_SIZE = N/2;
        a_set = new HashSet<>();  
        visited = new boolean[N+1]; 
        dfs(1, 0);
        System.out.println(answer);
    }

    static void dfs(int start_num, int size){
        if(size == STACK_MAX_SIZE){
            int a_sum =0, b_sum =0;
            for(int i = 1; i<= 2* STACK_MAX_SIZE; i++){
                for(int j = i+1; j <= 2 * STACK_MAX_SIZE; j++){
                    if(visited[i] == false && visited[j] == false){
                        a_sum += (map[i][j] + map[j][i]);
                    }else if(visited[i] == true && visited[j] == true){
                        b_sum += (map[i][j] + map[j][i]);
                    }
                }
            }
            int diff = Math.abs(a_sum - b_sum);
            answer = Math.min(answer, diff);
        }else{
            for(int i = start_num; i <= 2 * STACK_MAX_SIZE; i++){
                visited[i] = true;
                dfs(i+1, size+1);
                visited[i] = false;
            }
        }
    }
}
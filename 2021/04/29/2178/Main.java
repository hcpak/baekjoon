import java.util.*;
public class Main {
    static int [][] Map, visited;
    static int N, M;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Map = new int[N][M];
        for(int i=0; i < N; i++){
            String input = sc.next();
            for(int j=0; j< M; j++){
                Map[i][j] = input.charAt(j) - '0';
            }
        }
        visited = new int[N][M];
        System.out.println(bfs(0,0));
    }

    static int bfs(int y, int x){
        int [] direction_x = {1,-1,0,0}, direction_y = {0,0,1,-1};
        Queue<Pair> q = new LinkedList<>();
        visited[y][x] = 1;
        q.add(new Pair(y,x));
        int count =1;
        while(!q.isEmpty()){
            int cur_y = q.peek().y, cur_x = q.poll().x;
            for(int i=0; i<4; i++){
                int next_y = cur_y + direction_y[i], next_x = cur_x + direction_x[i];
                if(next_y >= N || next_y <0 || next_x >= M || next_x <0){
                    continue;
                }
                if(next_y == N-1 && next_x == M-1){
                    return visited[cur_y][cur_x]+1;
                }
                if(Map[next_y][next_x] == 1 && visited[next_y][next_x] == 0){
                    visited[next_y][next_x] = visited[cur_y][cur_x] +1;
                    q.add(new Pair(next_y,next_x));
                    count++;
                }
            } 
        }
        return count;
    }

    static class Pair{
        int y;
        int x;

        Pair(int y, int x){
            this.x = x;
            this.y = y;
        }
    }
}

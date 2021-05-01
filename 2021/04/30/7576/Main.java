import java.util.*;
public class Main {
    static int N, M, max = 0;
    static int[][] Map, visited;
    static Queue<Pair> q;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        M = sc.nextInt();
        N = sc.nextInt();
        Map = new int[N][M];
        q = new LinkedList<>();
        visited = new int[N][M];
        for(int i =0; i< N; i++){
            for(int j=0; j< M; j++){
                Map[i][j] =sc.nextInt();
                if(Map[i][j] ==1){
                    q.add(new Pair(i,j));
                }
            }
        }
        bfs();
        boolean flag = true;
        for(int i=0; i<N; i++){
            for(int j=0; j< M; j++){
                if(Map[i][j] == 0){
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            System.out.println(max);
        else
            System.out.println(-1);
    }

    static void bfs(){
        int [] direction_x = {1,-1,0,0}, direction_y = {0,0,1,-1};
        while(!q.isEmpty()){
            int cur_y = q.peek().y, cur_x = q.poll().x;
            for(int i=0; i<4; i++){
                int next_y = cur_y + direction_y[i], next_x = cur_x + direction_x[i];
                if(next_y >= N || next_y <0 || next_x >= M || next_x <0){
                    continue;
                }
                if(Map[next_y][next_x] == 0){
                    Map[next_y][next_x] = 1;
                    visited[next_y][next_x] = visited[cur_y][cur_x]+1;
                    max = Math.max(max, visited[next_y][next_x]);
                    q.add(new Pair(next_y,next_x));
                }
            } 
        }
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
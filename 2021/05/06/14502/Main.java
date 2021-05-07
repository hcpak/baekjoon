import java.util.*;
public class Main {
    static int N, M, answer = 0;
    static int[][] Map;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        Map = new int[N][M];
        for(int i=0; i< N; i++){
            for(int j=0; j<M; j++){
                Map[i][j] = sc.nextInt();
            }
        }
        CreateWall(0, 0);
        System.out.println(answer);
    }

    static void CreateWall(int cur, int cnt){
        if(cnt ==3){
            bfs();
        }else{
            for(int i= cur; i< N*M; i++){
                if(Map[i/M][i%M] ==0){
                    Map[i/M][i%M] = 1;
                    CreateWall(i+1, cnt+1);
                    Map[i/M][i%M] = 0;
                }
            }
        }
    }

    static void bfs(){
        int[] diff_x = {1,-1,0,0}, diff_y = {0,0,1,-1};
        Queue<point> q = new LinkedList<>();
        int[][] copyMap = new int[N][M];
        for(int i=0; i < N; i++){
            for(int j =0; j < M ; j++){
                copyMap[i][j] = Map[i][j];
                if(Map[i][j] == 2){
                    q.add(new point(i,j));
                }
            }
        }
        
        while(!q.isEmpty()){
            int cur_x = q.peek().x, cur_y = q.poll().y;
            for(int i=0; i< 4; i++){
                int next_x = cur_x + diff_x[i], next_y = cur_y + diff_y[i];
                if( next_x < 0 || next_x >= M || next_y <0 || next_y >= N){
                    continue;
                }
                if(copyMap[next_y][next_x] == 0){
                    copyMap[next_y][next_x] = 2;
                    q.add(new point(next_y, next_x));
                }
            }
        }
        int count=0;
        for(int i=0; i< N; i++){
            for(int j =0; j< M; j++){
                if(copyMap[i][j] ==0){
                    count++;
                }
            }
        }
        answer = Math.max(answer, count);
    }

    static class point{
        int x,y;

        public point(int y, int x){
            this.x = x;
            this.y = y;
        }
    }
}

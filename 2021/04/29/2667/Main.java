import java.util.*;
public class Main {
    static int [][] Map;
    static boolean [][] visited;
    static int N;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        Map = new int[N][N];
        for(int i=0; i < N; i++){
            String input = sc.next();
            for(int j=0; j< N; j++){
                Map[i][j] = input.charAt(j) - '0';
            }
        }
        visited = new boolean[N][N];
        int count = 0;
        List<Integer> list = new ArrayList<>();
        for(int y=0; y < N; y++){
            for(int x =0; x < N; x++){
                if(Map[y][x] == 1 &&! visited[y][x]){
                    list.add(bfs(y,x));
                    count++;
                }
            }
        }
        list.sort(null);
        System.out.println(count);
        for(int i=0; i<list.size(); i++){
            System.out.println(list.get(i));
        }
    }

    static int bfs(int y, int x){
        int [] direction_x = {1,-1,0,0}, direction_y = {0,0,1,-1};
        Queue<Pair> q = new LinkedList<>();
        visited[y][x] = true;
        q.add(new Pair(y,x));
        int count =1;
        while(!q.isEmpty()){
            int cur_y = q.peek().y, cur_x = q.poll().x;
            for(int i=0; i<4; i++){
                int next_y = cur_y + direction_y[i], next_x = cur_x + direction_x[i];
                if(next_y >= N || next_y <0 || next_x >= N || next_x <0){
                    continue;
                }
                if(Map[next_y][next_x] == 1 &&!visited[next_y][next_x]){
                    visited[next_y][next_x] = true;
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

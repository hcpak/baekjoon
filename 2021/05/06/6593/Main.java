import java.util.*;
public class Main {
    static int L, R, C;
    static char[][][] Map;
    static boolean[][][] visited;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Queue<point> q = new LinkedList<>();
        L = sc.nextInt();
        R = sc.nextInt();
        C = sc.nextInt();
        while(L != 0 || R != 0 || C != 0){
            int answer = -1;
            Map = new char[L][R][C];
            visited = new boolean[L][R][C];
            for(int l=0; l <L; l++){
                for(int r =0; r < R; r++){
                    String str = sc.next();
                    for(int c =0; c< C; c++){
                        Map[l][r][c] = str.charAt(c);
                        if(str.charAt(c) == 'S'){
                            q.add(new point(l, r, c,0));
                        }
                    }
                }
            }

            while(!q.isEmpty()){
                int cur_z = q.peek().z, cur_y = q.peek().y, cur_x = q.peek().x, cnt = q.poll().cnt;
                int[] diff_z ={0,0,0,0,-1,1}, diff_y = {0,0,1,-1,0,0}, diff_x = {1,-1,0,0,0,0};
                for(int i=0; i< 6;i++){
                    int next_z = cur_z + diff_z[i], next_y = cur_y + diff_y[i], next_x = cur_x + diff_x[i];
                    if(next_z<0 || next_z >= L || next_y <0 || next_y >=R || next_x <0 || next_x >=C){
                        continue;
                    }
                    if(Map[next_z][next_y][next_x] == '.' && !visited[next_z][next_y][next_x]){
                        visited[next_z][next_y][next_x] = true;
                        q.add(new point(next_z, next_y, next_x,cnt+1));
                    }else if(Map[next_z][next_y][next_x] == 'E'){
                        answer = cnt+1;
                        break;
                    }
                }
            }
            if(answer == -1){
                System.out.println("Trapped!");
            }else{
                System.out.println("Escaped in "+answer +" minute(s).");
            }
            L = sc.nextInt();
            R = sc.nextInt();
            C = sc.nextInt();
        }
    }

    static class point{
        int x,y,z;
        int cnt;
        public point(int z, int y, int x, int cnt){
            this.x = x;
            this.y = y;
            this.z = z;
            this.cnt = cnt;
        }
    }
}

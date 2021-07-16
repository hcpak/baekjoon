import java.util.*;
public class Main {
    static int [][] map;
    static int N, M, x, y, K;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        K = sc.nextInt();
        map = new int[N][M];
        int[] dice = new int[7];
        for(int i=0; i<N;i++){
            for(int j=0; j<M; j++){
                map[i][j] = sc.nextInt();
            }
        }
        int instruction, cur_x = x, cur_y =y, top = 1, right =3, up =2, temp;
        for(int i=0; i<K;i++){
            instruction = sc.nextInt();
            switch(instruction){// 방향대로 움직이기
                case 1: // 동쪽
                    if(!checkMap(cur_x, cur_y+1)){
                        continue;
                    }
                    cur_y++;
                    temp = top;
                    top = right;
                    right = 7 - temp;
                    break;
                case 2: // 서쪽
                    if(!checkMap(cur_x, cur_y-1)){
                        continue;
                    }
                    cur_y--;
                    temp = top;
                    top = 7 - right;
                    right = temp;
                    break;
                case 3: // 북쪽
                    if(!checkMap(cur_x-1, cur_y)){
                        continue;
                    }
                    cur_x--;
                    temp = top;
                    top = 7 - up;
                    up = temp;
                    break;
                case 4: // 남쪽
                    if(!checkMap(cur_x+1, cur_y)){
                        continue;
                    }
                    cur_x++;
                    temp = top;
                    top = up;
                    up = 7 - temp;
                    break;
            }
            if(map[cur_x][cur_y] ==0){ // 주사위에 있는 거 적기
                map[cur_x][cur_y] = dice[7-top];
            }else{ // 주사위에 적기
                dice[7-top] = map[cur_x][cur_y];
                map[cur_x][cur_y] =0;
            }
            System.out.println(dice[top]);
        }
    }

    public static boolean checkMap(int x, int y){
        if(x >= N || y >= M || x <0 || y <0){//지도 밖으로 벗어날 시
            return false;
        }
        return true;
    }
}

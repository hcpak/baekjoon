import java.util.*;

import javax.naming.directory.DirContext;

public class Main {
    static int[][] gears = new int[4][8];
    static int[] gear_loc = new int[4];
    static int gear_number, direction, K;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i=0; i< 4; i++){
            String gear = sc.nextLine();
            for(int j=0; j < 8; j++){
                gears[i][j] = Character.getNumericValue(gear.charAt(j));
            }
        }
        K = sc.nextInt();
        for(int i=0; i < K; i++){
            Queue<pair> queue = new LinkedList<pair>();
            gear_number = sc.nextInt() - 1;
            direction = sc.nextInt();
            queue.add(new pair(gear_number, direction));
            int current_gear_number = gear_number, cur_dir = direction;
            while(current_gear_number<3){
                int right_gear_number = current_gear_number+1;
                int cur_gear_right, right_gear_left;
                //오른쪽으로 가기
                if(gear_loc[current_gear_number] + 2 >= 8){
                    cur_gear_right = gear_loc[current_gear_number] + 2 - 8;
                }else{
                    cur_gear_right = gear_loc[current_gear_number] + 2;
                }
                if(gear_loc[right_gear_number] - 2 < 0){
                    right_gear_left = gear_loc[right_gear_number] - 2 + 8;
                }else{
                    right_gear_left = gear_loc[right_gear_number] - 2;
                }
                
                if(gears[current_gear_number][cur_gear_right] + gears[right_gear_number][right_gear_left] == 1){// N극, S극일떄
                    cur_dir = -cur_dir;
                    queue.add(new pair(right_gear_number, cur_dir));
                }else{
                    break;
                }
                current_gear_number += 1;
            }
        
            current_gear_number = gear_number;
            cur_dir = direction;
            while(current_gear_number>0){// 왼쪽
                int left_gear_number = current_gear_number -1;
                int cur_gear_left, left_gear_right;
                if(gear_loc[current_gear_number] - 2 < 0){
                    cur_gear_left = gear_loc[current_gear_number] - 2 + 8;
                }else{
                    cur_gear_left = gear_loc[current_gear_number] - 2;
                }
                if(gear_loc[left_gear_number] + 2 >= 8){
                    left_gear_right = gear_loc[left_gear_number] + 2 - 8;
                }else{
                    left_gear_right = gear_loc[left_gear_number] + 2;
                }
                
                if(gears[current_gear_number][cur_gear_left] + gears[left_gear_number][left_gear_right] == 1){
                    cur_dir = -cur_dir;
                    queue.add(new pair(left_gear_number, cur_dir));
                }else{
                    break;
                }
                current_gear_number -= 1;
            }
            
            while(!queue.isEmpty()){
                int g_number = queue.peek().x, dir = queue.peek().y;
                if(dir == -1){
                    if(gear_loc[g_number] +1 >= 8){
                        gear_loc[g_number] = 0;
                    }else{
                        gear_loc[g_number] += 1;
                    }
                }else{
                    if(gear_loc[g_number] -1 <0){
                        gear_loc[g_number] = 7;
                    }else{
                        gear_loc[g_number] -= 1;
                    }
                }
                queue.poll();
            }
        }

        int sum = 0;
        for(int i=0; i < 4; i++){
            if(gears[i][gear_loc[i]] == 1)
                sum += Math.pow(2, i);
        }
        System.out.println(sum);
    }

    static class pair{
        int x, y;

        pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}

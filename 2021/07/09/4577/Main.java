import java.util.*;
public class Main {
    static int r, c, user_r, user_c;
    static char[][] map;
    static class pair{
        int x, y;
        pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            r = sc.nextInt();
            c = sc.nextInt();
            if(r == 0 && c == 0){
                break;
            }
            map = new char[r][c];
            for(int i =0; i<r; i++){
                String str = sc.nextLine();
                for(int j =0; j<c; j++){
                    map[i][j] = str.charAt(j);
                    if(str.charAt(j) == 'w'){
                        user_r = i;
                        user_c = j;
                    }else if(str.charAt(j) == '+'){
                        user_r = i;
                        user_c = j;
                    }
                }
            }
            String str = sc.nextLine();
            for(int i=0; i< str.length(); i++){
                if(str.charAt(i) == 'U'){
                    
                }else if(str.charAt(i) == 'D'){

                }else if(str.charAt(i) == 'R'){
                    
                }else if(str.charAt(i) == 'L'){

                }
            }
        }
    }

    public static boolean CanGo(int r, int c, int next_r, int next_c){
        switch(map[next_r][next_c]){
            case '.':
                map[r][c] = '.';
                map[next_r][next_c] = 'W';
                break;
            case '#':

                break;
            case 'b':

                break;
            case '+':

                break;
        }
        return true;
    }
}

import java.io.*;
import java.util.*;

public class Main {
    static int N,M,T;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        M = Integer.parseInt(params[1]);
        T = Integer.parseInt(params[2]);
        int[][] circles = new int[N+1][M];
        boolean[][] circles_check = new boolean[N+1][M]; 
        for(int i=1; i<= N; i++){
            params = br.readLine().split(" ");
            for(int j=0;j<M;j++){
                circles[i][j] = Integer.parseInt(params[j]);
            }
        }

        int[] circle_loc = new int[N+1];

        for(int i=0; i< T; i++){
            params = br.readLine().split(" ");
            int x = Integer.parseInt(params[0]), d = Integer.parseInt(params[1]), k = Integer.parseInt(params[2]);
            for(int j=1; j<= N; j++){
                if(j % x ==0){ // 돌린다.
                    if(d == 0){// 시계 방향
                        circle_loc[j] = inbound(circle_loc[j] - k);
                    }else{// 반시계
                        circle_loc[j] = inbound(circle_loc[j] + k);
                    }
                }
            }
            // 인접한 거 찾기
            boolean search_flag = false;
            int sum =0, count =0;
        
            for(int j = 1; j<= N; j++){
                for(int h = 0; h < M; h++){
                    int loc = inbound(h + circle_loc[j]);
                    int bigger_loc = inbound(loc+1);
                    if(circles[j][loc] != 0){
                        sum += circles[j][loc];
                        count++;
                        if(j != N){ // 바깥과 비교
                            int outter_loc = inbound(h + circle_loc[j+1]);
                            if(circles[j][loc] == circles[j+1][outter_loc]){
                                search_flag = true;
                                circles_check[j][loc] = true;
                                circles_check[j+1][outter_loc] = true;
                            }
                        } 
                        // 같은 서클 내에 비교
                        if(circles[j][loc] == circles[j][bigger_loc]){
                            search_flag = true;
                            circles_check[j][loc] = true;
                            circles_check[j][bigger_loc] = true;
                        }
                    }
                }
            }
            // 인접한 거 없으면 평균 구해서 평균에 따라 처리
            float average = (float)sum/count;
            if(!search_flag){
                for(int j=1; j<=N; j++){
                    for(int h=0; h<M; h++){
                        if(circles[j][h] != 0){
                            if(circles[j][h] > average){
                                circles[j][h]--;
                            }else if(circles[j][h] < average){
                                circles[j][h]++;
                            }
                        }
                    }
                }
            }else{// 인접한 거 있으면 인접한 수 지우기
                for(int j=1; j<=N; j++){
                    for(int h=0; h<M; h++){
                        if(circles[j][h] != 0 && circles_check[j][h] == true){
                            circles[j][h] = 0;
                        }
                    }
                }
            }
        }

        int sum = 0;
        for(int i=1; i<=N; i++){
            for(int j =0; j<M; j++){
                sum += circles[i][j];
            }
        }
        bw.write(sum+"\n");
        bw.flush();
        bw.close();
    }

    static int inbound(int value){
        if(value >= M){
            value -= M;
        }else if(value <0){
            value += M;
        }
        return value;
    }
}

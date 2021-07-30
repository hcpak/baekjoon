import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main {
    static int R, C, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] params = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        R = params[0];
        C = params[1];
        M = params[2];
        List<Shark> sharks = new ArrayList<>();
        
        for(int i =0; i< M; i++){
            params = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int r = params[0], c = params[1], s =params[2], d = params[3], z = params[4];
            // if(d == 1 || d == 2){
            //     s %= ((R-1 ) * 2);
            // }else if(d ==3 || d == 4){
            //     s %= ((C-1) *2);
            // }
            sharks.add(new Shark(i+1,r,c,s,d,z));
        }

        int answer =0;
        PriorityQueue<Shark> pq = new PriorityQueue<>();;
        Queue<Point> points = new LinkedList<>();
        int[][] mapSharkCount = new int[R+1][C+1];
        PriorityQueue<IndexSize> eatSharks = new PriorityQueue<>();;

        for(int col=1; col<=C;col++){
            pq.clear();
            
            //낚시왕 잡기
            for(int j=0; j< sharks.size(); j++){
                Shark shark = sharks.get(j);
                if(shark.check(col)){
                    pq.add(shark);
                }
            }

            //상어 제거
            if(!pq.isEmpty()){
                int catchShark = pq.poll().i;
                for(int j=0; j< sharks.size(); j++){
                    Shark shark = sharks.get(j);
                    if(shark.i == catchShark){
                        answer += shark.z;
                        sharks.remove(j);
                        break;
                    }
                }
            }
            
            for(int i = 1; i<= R; i++){
                for(int j=1; j<=C; j++){
                    mapSharkCount[i][j] =0;
                }
            }
            points.clear();

            // 상어 이동
            for(int j=0; j< sharks.size(); j++){
                Shark shark = sharks.get(j);
                shark.move();
                mapSharkCount[shark.r][shark.c]++;
                if(mapSharkCount[shark.r][shark.c] == 2){
                    points.add(new Point(shark.r, shark.c));
                }
            }

            //같은 곳에 있는 상어끼리 잡아 먹기
            while(!points.isEmpty()){
                Point point = points.poll();
                eatSharks.clear();
                // 같은 곳에 있는 상어 찾고 사이즈 비교
                for(int h=0; h<sharks.size(); h++){
                    Shark shark = sharks.get(h);
                    if(shark.check(point.r, point.c)){
                        eatSharks.add(new IndexSize(shark.i, shark.z));
                    }
                }
                eatSharks.poll(); // 가장 사이즈 큰 거 빼기

                // 잡아 먹기
                while(!eatSharks.isEmpty()){
                    int index = eatSharks.poll().i;
                    for(int h=0; h< sharks.size(); h++){
                        Shark shark = sharks.get(h);
                        if(index == shark.i){
                            sharks.remove(h);
                            break;
                        }
                    }
                }
            }
        }
        bw.write(answer+"\n");
        bw.flush();
        bw.close();
    }

    static class Point{
        public int r, c;

        public Point(int r, int c){
            this.r = r;
            this.c = c;
        }
    }

    static class IndexSize implements Comparable<IndexSize>{
        public int i,z;

        public IndexSize(int i, int z){
            this.i = i;
            this.z = z;
        }

        @Override
        public int compareTo(IndexSize i){
            return i.z - this.z;
        }
    }

    static class Shark implements Comparable<Shark>{
        public int i,r,c,s,z,d;

        public Shark(int i, int r, int c,int s, int d, int z){
            this.i = i;
            this.r = r;
            this.c = c;
            this.s = s;
            this.d = d;
            this.z = z;
        }

        public void move(){
            int go = this.s;
            while(go != 0){
                switch(this.d){
                    case 1:
                        if(this.r - go < 1){
                            go -= (this.r -1);
                            this.r = 1;
                            this.d = 2;
                        }else{
                            this.r -= go;
                            go =0;
                        }
                        break;
                    case 2:
                        if(this.r + go > R){
                            go -= (R - this.r);
                            this.r = R;
                            this.d = 1;
                        }else{
                            this.r += go;
                            go =0;
                        }
                        break;

                    case 3:
                        if(this.c + go > C){
                            go -= (C -this.c);
                            this.c = C;
                            this.d =4;
                        }else{
                            this.c += go;
                            go =0;
                        }
                        break;
                    case 4:
                        if(this.c - go < 1){
                            go -= (this.c - 1);
                            this.c = 1;
                            this.d = 3;
                        }else{
                            this.c -= go;
                            go =0;
                        }
                        break;
                }
            }
        }

        public boolean check(int c){
            if(this.c == c){
                return true;
            }
            return false;
        }

        public boolean check(int r, int c){
            if(this.r == r && this.c == c)
                return true;
            return false;
        }

        @Override
        public int compareTo(Shark s){
            if(this.r > s.r)
                return 1;
            else if(this.r == s.r)
                return 0;
            return -1;
        }
    }
}

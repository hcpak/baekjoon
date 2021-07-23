import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> maxPq = new PriorityQueue<>(Collections.reverseOrder()), minPq = new PriorityQueue<>();
        for(int i=0; i< N;i++){
            int input = Integer.parseInt(br.readLine());
            if(i == 0){
                maxPq.add(input);
            }else{
                if(maxPq.peek() > input){
                    maxPq.add(input);
                    if(maxPq.size() == minPq.size() + 2){
                        minPq.add(maxPq.poll());
                    }
                }else if(maxPq.peek() < input){
                    minPq.add(input);
                    if(maxPq.size() < minPq.size()){ 
                        maxPq.add(minPq.poll());
                    }
                }else{
                    if(minPq.size() == maxPq.size()){
                        maxPq.add(input);
                    }else{
                        minPq.add(input);
                    }
                }
            }
            bw.write(maxPq.peek()+"\n");
        }
        bw.flush();
        bw.close();
    }
}

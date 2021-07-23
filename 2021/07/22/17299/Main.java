import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int[] arr = Stream.of(str.split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] count = new int[1_000_001], answer = new int[N];
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i< N; i++){
            count[arr[i]] += 1;
            answer[i] = -1;
        }
        
        for(int i=0; i< N; i++){
            while(!stack.empty() && count[arr[i]] > count[arr[stack.peek()]]){
                answer[stack.pop()] = arr[i];
            }
            stack.push(i);
        }
        for(int i=0; i < N; i++){
            bw.write(answer[i] +" ");
        }
        bw.flush();
        bw.close();
    }
}

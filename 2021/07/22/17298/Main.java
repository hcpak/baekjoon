import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.*;
import java.util.stream.*;
import java.util.Scanner;
import java.util.Stack;
import java.util.*;



public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int[] arr = Stream.of(str.split(" ")).mapToInt(Integer::parseInt).toArray();
        int[] answer = new int[N];
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<N;i++){
            answer[i] = -1;
            while(!stack.empty()&& arr[i] > arr[stack.peek()]){
                answer[stack.pop()] = arr[i];
            }
            stack.push(i);
        }
        for(int i=0; i<N;i++){
            bw.write(answer[i]+" ");
        }
        bw.flush();
        bw.close();
    }
}

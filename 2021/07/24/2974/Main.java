import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int size = arr.length;
        boolean flag = true;
        
        while(flag){
            for(int i=0; i< size-1;i++){
                if(arr[i] > arr[i+1]){
                    int temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    for(int j=0; j< size;j++){
                        System.out.print(arr[j]+ " ");
                    }
                    System.out.println();
                }
            }
            flag = false;
            for(int i=0; i< size-1; i++){
                if(arr[i] > arr[i+1]){
                    flag = true;
                    break;
                }
            }
        }
    }
}
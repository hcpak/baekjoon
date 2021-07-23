import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String instruction = br.readLine();
        while(instruction.compareTo("QUIT") != 0){
            String[] instructions = instruction.split(" ");
            for(int i=0; i<instructions.length; i++){
                System.out.print(instructions[i]);
            }
            System.out.println();
            instruction = br.readLine();
        }
        
    }
}

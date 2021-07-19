import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

		String str1 = sc.nextLine();
		String str2 = sc.nextLine();

        Stack<Integer>  count_stack = new Stack<>();
        Stack<Character> stack =new Stack<>();
        
        int count =0;
        for(int i=0; i< str1.length(); i++){
            stack.push(str1.charAt(i));
            if(str1.charAt(i) == str2.charAt(count)){
                if(count + 1 == str2.length()){//폭발할 때
                    for(int j=0; j<str2.length(); j++){
                        stack.pop();
                    }
                    if(!count_stack.empty()){
                        count = count_stack.pop();
                    }else{
                        count =0;
                    }
                }else{
                    count++;
                }
            }else if(str1.charAt(i) == str2.charAt(0)){
                count_stack.push(count);
                count = 1;
            }else{
                count_stack.clear();
                count =0;
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.empty()){
            sb.append(stack.pop());
        }
        sb.reverse();

        if(sb.length()==0){
            System.out.println("FRULA");
        }else{
            System.out.println(sb.toString());
        }
    }
}
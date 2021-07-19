import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Stack<Character> operation_stack = new Stack<>();
        Stack<Character> operator_stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            switch(str.charAt(i)){
                case '+': case '-':
                    if(!operation_stack.empty() && (operation_stack.peek() == '*' || operation_stack.peek() == '/')){
                        if(!operator_stack.empty())
                            sb.append(operator_stack.pop());
                        sb.append(operation_stack.pop());
                    }
                    if(!operator_stack.empty()){
                        sb.append(operator_stack.pop());
                    }
                    if(!operation_stack.empty() && (operation_stack.peek() == '+' || operation_stack.peek() == '-')){
                        sb.append(operation_stack.pop());
                    }
                    operation_stack.push(str.charAt(i));
                    break;

                case '*': case '/':
                    if(!operator_stack.empty())
                        sb.append(operator_stack.pop());
                    if(!operation_stack.empty() && (operation_stack.peek() == '*' || operation_stack.peek() == '/')){
                        sb.append(operation_stack.pop());
                    }
                    operation_stack.push(str.charAt(i));
                    break;

                case '(':
                    operation_stack.push(str.charAt(i));
                    break;

                case ')':
                    while(operation_stack.peek() != '('){
                        if(!operator_stack.empty())
                            sb.append(operator_stack.pop());
                        sb.append(operation_stack.pop());
                    }
                    operation_stack.pop();
                    break;

                default:
                    operator_stack.push(str.charAt(i));
                    break;
            }
        }
        while(!operation_stack.empty() || !operator_stack.empty()){
            if(!operator_stack.empty()){
                sb.append(operator_stack.pop());
            }
            if(!operation_stack.empty())
                sb.append(operation_stack.pop());
        }
        
        System.out.println(sb.toString());
    }
}

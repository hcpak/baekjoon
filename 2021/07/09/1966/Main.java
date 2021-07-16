import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int[] importances;
        Queue<Integer> queue;
        PriorityQueue<Integer> pq;
        for(int i =0; i < T;i++){
            int N = sc.nextInt(), M = sc.nextInt();
            importances = new int[N];
            queue = new LinkedList<>();
            pq = new PriorityQueue<>(Collections.reverseOrder());
            int importance;
            for(int j=0; j<N;j++){
                queue.add(j);
                importance = sc.nextInt();
                importances[j] = importance;
                pq.add(importance);
            }
            int count =1;
            while(!queue.isEmpty()){
                if(importances[queue.peek()] != pq.peek()){
                    queue.add(queue.peek());
                    queue.poll();
                }else{
                    if(queue.peek() == M){
                        System.out.println(count);
                        break;
                    }else{
                        queue.poll();
                        pq.poll();
                        count++;
                    }
                }
            }

        }
        
    }
}
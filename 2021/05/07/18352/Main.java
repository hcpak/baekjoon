import java.util.*;
public class Main {
    static int N,M,K,X;
    static List<List<Integer>> graph;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        X = sc.nextInt();
        graph = new ArrayList<>();
        for(int i =0; i<= N; i++){
            graph.add(new ArrayList<>());
        }
        int A,B;
        for(int i =0; i< M; i++){
            A = sc.nextInt();
            B = sc.nextInt();
            graph.get(A).add(B);
        }
        int[] visited = new int[N+1];
        for(int i=0; i <= N; i++){
            visited[i] = -1;
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(X);
        visited[X] =0;
        List<Integer> list = new ArrayList<>();
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int i=0; i< graph.get(cur).size();i++){
                int next = graph.get(cur).get(i);
                if(visited[next] == -1){
                    visited[next] = visited[cur] +1;
                    if(visited[next] != K){
                        q.add(next);
                    }else{
                        list.add(next);
                    }
                }
            }
        }
        list.sort(null);
        if(list.size() ==0){
            System.out.println(-1);
        }else{
            for(int i=0; i< list.size(); i++){
                System.out.println(list.get(i));
            }
        }
    }
    
    
}

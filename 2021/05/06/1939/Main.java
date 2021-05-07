import java.util.*;
public class Main {
    static int N, M, X, Y, answer = 0;
    static List<List<point>> graph;
    static boolean[] visited;
    static PriorityQueue<Integer> pq;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        graph = new ArrayList<>();
        for(int i=0; i<= N;i++){
            graph.add(new ArrayList<>());
        }
        int A,B,C;
        for(int i=0; i < M; i++){
            A = sc.nextInt();
            B = sc.nextInt();
            C = sc.nextInt();
            graph.get(A).add(new point(B,C));
            graph.get(B).add(new point(A,C));
        }
        X = sc.nextInt();
        Y = sc.nextInt();
        int start = 0, end = 1_000_000_001;
        while(start +1 <end){
            int mid = (start +end) /2;
            boolean flag = false;
            visited = new boolean[N+1];
            Queue<Integer> q = new LinkedList<>();
            q.add(X);
            visited[X] = true;
            while(!q.isEmpty()){
                int cur = q.poll();
                if(cur == Y){
                    flag = true;
                    break;
                }
                for(int i=0; i< graph.get(cur).size(); i++){
                    int next = graph.get(cur).get(i).next, next_weight = graph.get(cur).get(i).weight;
                    if(!visited[next] && next_weight >= mid){
                        visited[next] = true;
                        q.add(next);
                    }
                }
            }
            if(flag){
                start = mid;
            }else{
                end = mid;
            }
        }
        System.out.println(start);
    }

    static class point{
        int next, weight;
        public point(int next, int weight){
            this.next = next;
            this.weight = weight;
        }
    }
}

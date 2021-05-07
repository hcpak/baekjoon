import java.util.*;
public class Main {
    static int V,E,K;
    static List<List<Node>> graph;
    static int[] dist;
    static Integer INF = 1_000_000_000;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        V = sc.nextInt();
        E = sc.nextInt();
        K = sc.nextInt();
        graph = new ArrayList<>();
        for(int i=0; i<= V; i++){
            graph.add(new ArrayList<>());
        }
        int u,v,w;
        for(int i=0; i< E; i++){
            u = sc.nextInt();
            v = sc.nextInt();
            w = sc.nextInt();
            graph.get(u).add(new Node(v,w));
        }
        dist = new int[V+1];
        for(int i=1; i<= V;i++){
            dist[i] = INF;
        }
        PriorityQueue<Node> queue = new PriorityQueue<>();
        boolean[] check = new boolean[V+1];
        queue.add(new Node(K, 0)); 
        dist[K] = 0;
        while(!queue.isEmpty()){
            Node curNode = queue.poll();
            int cur = curNode.end;
            if(check[cur] == true){
                continue;
            }
            check[cur] = true;
            for(Node node : graph.get(cur)){
                if(dist[node.end] > dist[cur] + node.weight){
                    dist[node.end] = dist[cur] + node.weight;
                    queue.add(new Node(node.end, dist[node.end]));
                }
            }
        }
        for(int i=1; i<= V; i++){
            if(dist[i] == INF){
                System.out.println("INF");
            }else{
                System.out.println(dist[i]);
            }
        }
    }
    static class Node implements Comparable<Node>{
        int end, weight;

        public Node(int end, int weight){
            this.end = end;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o){
            return weight - o.weight;
        }
    }
}

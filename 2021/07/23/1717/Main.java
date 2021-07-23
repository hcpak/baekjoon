import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {
    static int[] parent, rank;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] params = br.readLine().split(" ");
        int n = Integer.parseInt(params[0]), m = Integer.parseInt(params[1]);
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i=1; i<= n; i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0; i< m; i++){
            params = br.readLine().split(" ");
            int instruction = Integer.parseInt(params[0]), a = Integer.parseInt(params[1]), b = Integer.parseInt(params[2]);
            if(instruction == 0){
                // 합집합
                union(a,b);
            }else{
                // 물어보기
                if(find(a) == find(b)){
                    bw.write("YES\n");
                }else{
                    bw.write("NO\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }
    static int find(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }

    static void union(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return;

        if(rank[u] > rank[v]){
            int temp = u;
            u = v;
            v = temp;
        }

        parent[u] =v;

        if(rank[u] == rank[v]) rank[v]++;
    }
}

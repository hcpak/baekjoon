// 벡터 초기화 안해서 많이 틀렸던 문제 초기화는 늘 언제나 생각하자.
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> P;
const int INF = 1000000000;
const int MAX = 501;
int tc, n, m, w, s, e, t, dist[MAX], visited[MAX];
vector<P> adj[MAX];
bool bellman(int start){
    fill(dist, dist+n+1, INF);
    dist[start] = 0;
    visited[start] = true;
    for(int i = 0; i< n;i++){
        for(int j=1;j<=n;j++){
            for(auto &p: adj[j]){
                int next = p.first, d = p.second;
                if(dist[j] != INF && dist[next] > dist[j] +d){
                    dist[next] = dist[j] + d;
                    visited[next] = true;
                    if(i == n-1) 
                        return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d", &tc);
    for(int i = 0; i < tc;i++){
        if( i != 0){
            printf("\n");
        }
        scanf("%d %d %d", &n, &m, &w);
        for(int j =1; j<=n;j++)
            adj[j].clear();
        for(int j= 0; j<m;j++){
            int s,e,t;
            scanf("%d %d %d", &s,&e,&t);
            adj[s].push_back(P(e,t));
            adj[e].push_back(P(s,t));
        }
        for(int j = 0; j<w; j++){
            scanf("%d %d %d", &s,&e,&t);
            adj[s].push_back(P(e,-t));
        }
        bool minusCycle= false;
        fill(visited, visited+n+1, false);
        for(int j=1;j<=n;j++){
            if(visited[j] == false){
                minusCycle = bellman(j);
            }
            if(minusCycle){
                break;
            }
        }
        if(minusCycle) printf("YES");
        else
            printf("NO");
    }
}

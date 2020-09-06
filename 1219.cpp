// 정말 왜 틀린 지 몰라서 QnA를 통해 해결했다. 그리고 생각보다 어려웠다.
// 가는 경로에 minus cycle이 없는 경우에 최단경로를 출력해야 하는데, Gee를 출력했다.
// 그러므로 틀림이 매우 많이 나왔다.
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
typedef pair<int,int> P;
const int INF = 987654321;
const int MAX = 100;
int n,s,t,m,city[MAX];
long long dist[MAX];
vector<P> adj[MAX];
int main(){
    scanf("%d %d %d %d", &n,&s,&t,&m);
    for(int i= 0; i<m;i++){
        int a,b,w;
        scanf("%d %d %d", &a,&b,&w);
        adj[a].push_back(P(b,w));
    }
    for(int i=0; i<n; i++){
        scanf("%d", &city[i]);
    }
    fill(dist, dist+n, INF);
    dist[s] = -city[s];
    for(int i = 0; i < n +MAX;i++){
       for(int j =0;j<n;j++){
           for(auto &p: adj[j]){
               int next = p.first, d = p.second;
               if(dist[j] == LONG_MAX) dist[next] = LONG_MAX;
               if((dist[j] != INF && dist[next] > dist[j] +d -city[next])){
                   dist[next] = dist[j] + d - city[next];
                   if(i >= n-1){
                    // 이 부분을 QnA를 통해 해결함.
                     dist[next] = LONG_MAX;
                   }
                }
            }
        }
    }
    if(dist[t] == INF)
        printf("gg");
    else{
        if(dist[t] == LONG_MAX)
            printf("Gee");
        else
            printf("%lld",-dist[t]);
    }
    return 0;
}
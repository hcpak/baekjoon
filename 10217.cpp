// 1. dist[][요거]를 설정할 필요 없다고 느껴서 없이 짰더니 결국 필요한 거였다.
// 요거 없으면 돈은 되는데 멀리 돌아가는 경로가 끝점까지 안가는 상황이 발생함.
// 2. 메모리 초과가 발생했는데, 그건 long long 배열을 썼다. long long 배열 쓰면 2^7 *2^20
// 메모리 제한은 256mb 인데 이게 2^8*2^20이니 메모리 제한 먹는 수밖에.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <climits>
#define n_MAX 101
#define m_MAX 10001
using namespace std;
vector<tuple<int, int, int>> graph[n_MAX];
int dist[n_MAX][m_MAX];
void dijkstra(int start,int m){
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0,m, start});
    dist[start][m] = 0;
    while(!pq.empty()){
        tuple<int, int , int> _cur = pq.top();
        pq.pop();
        int cur_d = get<0>(_cur), cur = get<2>(_cur) , cur_m = get<1>(_cur);
        if(cur_d> dist[cur][cur_m]) continue;
        for(tuple<int, int, int> _next: graph[cur]){
            int next = get<0>(_next), next_m = get<1>(_next), next_d = get<2>(_next);
            if( cur_m - next_m >=0 && dist[cur][cur_m] + next_d < dist[next][cur_m - next_m] ){
                dist[next][cur_m - next_m] = dist[cur][cur_m] + next_d;
                pq.push({dist[next][cur_m - next_m], cur_m -next_m, next});
            }
        }
    }
}
int main(){
    int tc, n,m,k, u,v,c,d;
    scanf("%d", &tc);
    for(int i =0;i<tc;i++){
        if( i != 0)
            printf("\n");
        scanf("%d %d %d", &n, &m, &k);
        for(int j=0; j <=n;j++){
            graph[j].clear();
        }
        for(int j =0; j<k;j++){
            scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u].push_back({v,c,d});
        }
        for(int j =0;j<=n;j++){
            for(int l = 0; l<=m;l++){
                dist[j][l] = INT_MAX;
            }
        }
        dijkstra(1,m);
        int ans = INT_MAX;
        for(int j =0;j <=m;j++){
            ans = min(ans, dist[n][j]);
        }
        if(ans == INT_MAX)
            printf("Poor KCM");
        else
            printf("%d",ans);
    }
    return 0;
}
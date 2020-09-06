// 이 방법을 생각해내기가 너무 힘듬
// 원리를 이해하는 데에 오래 걸렸음 구현은 별로 오래 안걸림
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
#define MAX 501
using namespace std;
vector<pair<int , int >> graph[MAX];
vector<pair<int , int >> rev[MAX];
long long  dist[MAX];
bool check[MAX][MAX] ={0};
void dijkstra(long long  start) {
    priority_queue<pair<long long , long long >, vector<pair<long long , long long >>, greater<>> pq; 
    pq.push({0, start});
    dist[start] = 0; 
    while(!pq.empty()) {
        pair<long long , long long > _cur = pq.top();
        pq.pop();
        long long  d = _cur.first, cur = _cur.second;
        if(d > dist[cur]) continue; 
        for(pair<int , int > _next: graph[cur]) {
            int next = _next.first, next_d = _next.second;
            if(dist[cur] + next_d < dist[next] && check[cur][next] == false) {
                dist[next] = dist[cur] + next_d;
                pq.push({ dist[next], next });
            }
        }
    }
}
void bfs(int end){
    queue<int> q;
    q.push(end);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i =0; i<rev[tmp].size();i++){
            int next = rev[tmp][i].first, d = rev[tmp][i].second;
            if(dist[tmp] == dist[next] + d){
                check[next][tmp] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int c =0;
    while(1){
        if(c != 0)
            printf("\n");
        c++;
        int  n, m, s, t;
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            break;
        scanf("%d %d", &s, &t);
        fill_n(&dist[0], n+1, LONG_MAX);
        for(int i=0; i<=n; i++) {
           graph[i].clear();
            rev[i].clear();
           for(int j = 0; j<=n;j++){
               check[i][j] = false;
           }
        }
        for(int i=0; i<m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            graph[u].push_back({v, p});
            rev[v].push_back({u,p});
        }
        dijkstra(s);
        if(dist[t] == LONG_MAX){
            printf("-1");
            continue;
        }
        bfs(t);
        fill_n(&dist[0], n+1, LONG_MAX);
        dijkstra(s);
        if(dist[t] == LONG_MAX)
            printf("-1");
        else
            printf("%lld",dist[t]);
    }
    return 0;
}
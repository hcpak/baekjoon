#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define INF (int)(1e9)
#define MAX 1001
using namespace std;
vector<pair<int, int> > graph[MAX];
int dist[MAX];
void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        pair<int, int> _cur = pq.top();
        pq.pop();
        int d = _cur.first, cur = _cur.second;
        if(d > dist[cur]) continue;
        for(pair<int, int> _next: graph[cur]){
            int next = _next.first, next_d = _next.second;
            if(dist[cur] + next_d < dist[next]){
                dist[next] = dist[cur] + next_d;
                pq.push({dist[next], next});
            }
        }
    }
}
int main(){
    fill_n(&dist[0], sizeof(dist)/sizeof(int), INF);
    int n,m,s,t;
    scanf("%d %d", &n, &m);
    for(int i =0; i< m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    scanf("%d %d", &s, &t);
    dijkstra(s);
    printf("%d", dist[t]);
    return 0;
}
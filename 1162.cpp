// 내 힘으로 한 것이 아니라 https://m.blog.naver.com/kks227/220796029558 이 블로그에서 알려준대로 했다.
// 내 생각에는 경로마다 0으로 초기화 시켜서 순열조합 경우만큼 dijkstra를 하려고 헀다가 이 방법을 알게 되어 진행했다.
// 알고리즘만 알면 구현은 할 수 있게 된 거 같다.
// 그리고 LONG_MAX 크기와 long long의 중요성. 특히 최단거리 일때 distance가 int 범위 밖으로 벗어나갈 가능성 존재.
// 왠만하면 long long 그러나 자료형 범위와 메모리 제한을 봐가면서 할것.
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <climits>
#define MAX 10001
using namespace std;
vector<tuple<long long, long long>> graph[MAX];
long long dist[MAX][21];
void dijkstra(long long start,long long k){
    priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long>>, greater<>> pq;
    pq.push({0,start,k});
    dist[start][k] = 0;
    while(!pq.empty()){
        tuple<long long, long long , long long> _cur = pq.top();
        pq.pop();
        long long cur_d = get<0>(_cur), cur = get<1>(_cur) , cur_k = get<2>(_cur);
        if(cur_d> dist[cur][cur_k]) continue;
        for(tuple<long long, long long> _next: graph[cur]){
            long long next = get<0>(_next), next_d = get<1>(_next);
            if(dist[cur][cur_k] + next_d < dist[next][cur_k]){
                dist[next][cur_k] = dist[cur][cur_k] + next_d;
                pq.push({dist[next][cur_k], next,cur_k});
            }
            if(dist[cur][cur_k] <dist[next][cur_k-1] &&cur_k>0){
                dist[next][cur_k-1] = dist[cur][cur_k];
                pq.push({dist[next][cur_k-1],next,cur_k-1});
            }
        }
    }
}
int main(){
    fill_n(&dist[0][0], sizeof(dist)/sizeof(long long), LONG_MAX);
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    for(long long i = 0; i< m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dijkstra(1,k);
    long long ans = LONG_MAX;
    for(long long i =0; i<=k;i++){
        ans = min(ans, dist[n][i]);
    }
    cout << ans;
    return 0;
}
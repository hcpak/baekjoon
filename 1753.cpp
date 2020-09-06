#include <iostream>
#include <algorithm> // fill_n
#include <vector>
#include <queue> // priority_queue
#include <utility> // pair<>
#define INF (int)(1e9)

using namespace std;
vector<pair<int, int>> nodes[20001];
int dis[20001];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 가장 거리가 짧은 노드가 top에 있을 것이다
    pq.push({0, start}); // 가중치, 노드 순. start -> start의 가중치는 0이다
    dis[start] = 0; // 나 -> 나 의 거리는 0이다
    while(!pq.empty()) {
        pair<int, int> _cur = pq.top();
        pq.pop();
        int d = _cur.first, cur = _cur.second; // 가중치, 노드 순으로 저장했었다
        cout << "cur: " << cur  << " d: " << d <<" dis[cur]: " << dis[cur] <<endl;
        if(d > dis[cur]) continue; // 최단거리가 아니니까 패스

        for(pair<int, int> _next: nodes[cur]) {
            int next = _next.first, next_d = _next.second;
            if(dis[cur] + next_d < dis[next]) {
                dis[next] = dis[cur] + next_d;
                pq.push({ dis[next], next });
                cout << "next: " << next <<" dis[next]: " << dis[next] <<endl;
            }
        }
    }
}

int main() {
    fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);

    int n, m, k;
    // scanf("%d %d", &n, &m);
    cin >> n >> m;
    cin >> k;
    for(int i=0; i<m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        nodes[a].push_back({b, c});
        // nodes[b].push_back({a, c});
    }

    dijkstra(k); // 0 에서 다른 모든 노드들과의 최단거리를 구하려고 한다
    for(int i=1; i<=n; i++){
        if(i != 1)
            cout << "\n";
        if(dis[i] == INF)
            cout << "INF";
        else
            cout << dis[i];
        
    }
        // printf("0 과 %d 의 최단거리는? %d\n", i, dis[i]);

    return 0;
}
/*
5 6
2
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/
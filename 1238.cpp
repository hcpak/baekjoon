#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define INF (int)(1e9)
using namespace std;
vector<pair<int, int> > nodes[1001];
int dis[1001],x_dis[1001];
void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push({0, start});
    dis[start] = 0;
    while(!pq.empty()){
        pair<int,int> _cur = pq.top();
        pq.pop();
        int d = _cur.first, cur = _cur.second;
        if(d > dis[cur])
            continue;
        for(pair<int, int> _next: nodes[cur]){
            int next = _next.first, next_d = _next.second;
            if(dis[cur] + next_d < dis[next]){
                dis[next] = dis[cur] + next_d;
                pq.push({dis[next], next});
            }
        }
    }
}

int main(){
    
    int n, m,x,ans = 0 ,tmp;
    cin >> n >> m >> x;
    for(int i=0; i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({b,c});
    }
    fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);
    dijkstra(x);
    for(int i =1;i<=n;i++){
        x_dis[i] = dis[i];
    }
    // cout << endl;
    for(int i =1;i <=n;i++){
        fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);
        dijkstra(i);
        tmp = dis[x] + x_dis[i];
        if(ans < tmp){
            ans = tmp;
        }

    }
    // cout <<endl;
    cout << ans;
    return 0;
}
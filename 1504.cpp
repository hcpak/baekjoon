#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define INF (int)(1e9)
using namespace std;
vector<pair<int, int> > nodes[801];
int dis[801];
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
    fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);
    int n, m,x,y;
    cin >> n >> m;
    for(int i=0; i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({b,c});
        nodes[b].push_back({a,c});
    }
    cin >> x >> y;
    int x_1, y_1, x_y,y_x, x_n, y_n; 
    dijkstra(1);
    x_1 = dis[x];
    y_1 = dis[y];
    fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);
    dijkstra(x);
    x_y = dis[y];
    x_n = dis[n];
    fill_n(&dis[0], sizeof(dis)/sizeof(int), INF);
    dijkstra(y);
    y_x = dis[x];
    y_n = dis[n];
    // cout << y_n <<" "<< x_n << " ";
    if(x_1+x_y+y_n >= INF || y_1+y_x+x_n >= INF || x_1+x_y+y_n <0 || y_1+y_x+x_n <0){
        cout << -1 <<"\n";
        return 0;
    }
    if(x_1+x_y+y_n < y_1+y_x+x_n){
        cout << x_1+x_y+y_n << "\n";
    }else{
        cout << y_1+y_x+x_n << "\n";
    }
    return 0;
}
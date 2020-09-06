#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>
#define INF (int)(1e9)
#define MAX 101
using namespace std;
int graph[MAX][MAX] , dist[MAX][MAX], x_pos[4]= {1,-1,0,0},y_pos[4] ={0,0,1,-1};
int n,m;
char t;
void dijkstra(int x, int y) {
    priority_queue<tuple<int, int, int>, vector<tuple <int, int, int>>, greater<>> pq;
    pq.push({0, x, y});
    dist[y][x] = 0;
    while(!pq.empty()){
        tuple<int, int ,int > _cur = pq.top();
        pq.pop();
        int d = get<0>(_cur), cur_x = get<1>(_cur), cur_y = get<2>(_cur);
        if(d > dist[cur_y][cur_x]) continue;
        for(int i= 0; i< 4; i++){
            int next_x =cur_x+x_pos[i], next_y = cur_y +y_pos[i], next_d = graph[next_y][next_x];
            if(!(next_x<0|| next_y<0 || next_x> m||next_y>n)){
                if(dist[cur_y][cur_x] + next_d< dist[next_y][next_x]){
                    dist[next_y][next_x] = dist[cur_y][cur_x] + next_d;
                    pq.push({dist[next_y][next_x],next_x,next_y});
                }
            }
        }
    }
}
int main(){
    scanf("%d %d", &m, &n);
    for(int y =1; y<= n; y++){
        for(int x =1; x<= m; x++){
            scanf(" %c", &t);
            graph[y][x] =t -'0';
            dist[y][x] = INF;
        }
    }
    dijkstra(1,1);
    printf("%d",dist[n][m]);
    return 0;
}
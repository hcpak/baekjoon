#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
queue<pair<pair<int, int>, int> > q;
int map[MAX][MAX][MAX] = { 0};
bool visited[MAX][MAX][MAX] = {false};
int dx[] = {-1,1,0,0,0,0,0};
int dy[] = {0,0,0,0,-1,1};
int dz[] = {0,0,-1,1,0,0};
int main(){
    int m, n, h;
    cin >> m >> n >> h;
    for(int k = 0; k< h; k++){
        for(int i= 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j][k];
                if(map[i][j][k] ==1 ){
                    q.push(make_pair(make_pair(i,j),k));
                    visited[i][j][k] =true;
                }else if(map[i][j][k] == -1){
                    visited[i][j][k] = true;
                }
            }
        }
    }
    int ans = -1;
    while(!q.empty()){
        int size = q.size();
        ++ans;
        while(size--){
            pair<pair<int, int>, int> now = q.front();
            q.pop();
            for(int i = 0; i< 6; i++){
                int qx, qy, qz;
                qx = now.first.second + dx[i];
                qy = now.first.first + dy[i];
                qz = now.second + dz[i];
                if(qx <0 || qx >= m || qy <0 || qy >=n || qz <0 || qz>= h)
                    continue;
                if(!visited[qy][qx][qz] && map[qy][qx][qz] == 0){
                    visited[qy][qx][qz] = true;
                    q.push(make_pair(make_pair(qy,qx),qz));
                }
            }
        }
    }
    for(int k = 0; k<h; k++){
        for (int i =0;i<n;i++){
            for(int j =0; j < m; j++){
                if(!visited[i][j][k]){
                    cout << "-1";
                    return 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
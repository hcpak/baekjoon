#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int graph[8][8],temp[8][8];
bool check[8][8];
int N, M;
void bfs(int * count){
    for(int y =0;y <N; y++){
        for(int x =0; x<M; x++){
            temp[y][x] = graph[y][x];
        }
    }
    queue<pair<int,int> > q;
    for(int y =0;y <N; y++){
        for(int x =0; x<M; x++){
            if(temp[y][x] == 2){
                q.push(make_pair(x,y));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        int x_pos[4] = {x-1,x+1,x,x};
        int y_pos[4] = {y,y,y-1,y+1};
        q.pop();
        for(int i =0;i<4;i++){
            if(x_pos[i]>=0 && x_pos[i] <M && y_pos[i] >= 0 && y_pos[i] <N){
                if(temp[y_pos[i]][x_pos[i]] == 0){
                    temp[y_pos[i]][x_pos[i]] = 2;
                    q.push(make_pair(x_pos[i],y_pos[i]));
                }
            }
        }
    }
    for(int y =0; y <N; y++){
        for(int x =0; x<M; x++){
            if(temp[y][x] == 0){
                *count = *count +1;
            }
        }
    }
}
int main(){
    cin >> N >> M;
    vector<pair<int,int> > v;
    int ans = 0,count =0;
    for(int y = 0; y< N;y++){
        for(int x = 0; x< M;x++){
            cin >> graph[y][x];
            if(graph[y][x] == 0){
                v.push_back(make_pair(x,y));
            }
            check[y][x]=false;
        }
    }
    for(int i =0;i<v.size();i++){
        int x1 = v[i].first,y1=v[i].second;
        graph[y1][x1] = 1;
        for(int j =i+1;j<v.size();j++){
            int x2 = v[j].first,y2=v[j].second;
            graph[y2][x2] = 1;
            for(int k = j+1;k<v.size();k++){
                int x3 = v[k].first, y3 =v[k].second;
                graph[y3][x3] = 1;
                count =0;
                bfs(&count);
                if(ans < count){
                    ans =count;
                }
                graph[y3][x3] = 0;
            }
            graph[y2][x2] = 0;
        }
        graph[y1][x1] = 0;
    }
    cout << ans;
    return 0;
}
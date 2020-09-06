#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 50;
typedef struct{
    pair<int, int> a, b, c;
    int dir;
}Log;

queue<pair<Log, int> > q;
string graph[MAX];
bool visited[MAX][MAX][2];
void decl(Log* temp, int y1, int x1, int y2, int x2, int y3, int x3,int dir){
    temp->a.first = y1;
    temp->a.second = x1;
    temp->b.first = y2;
    temp->b.second  = x2;
    temp->c.first = y3;
    temp->c.second = x3;
    temp->dir = dir;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int cnt = 0;
    Log treeLog;
    for(int i = 0; i< N;i++){
        cin >> graph[i];
        for(int j = 0;j<N; j++){
            if(graph[i][j] == 'B'){
                switch(cnt++){
                    case 0:
                        treeLog.a = make_pair(i,j);
                        break;
                    case 1:
                        treeLog.b = make_pair(i,j);
                        break;
                    case 2:
                        treeLog.c = make_pair(i,j);
                        if( treeLog.a.first == treeLog.b.first)
                            treeLog.dir = 1;
                        else 
                            treeLog.dir = 0;
                        q.push(make_pair(treeLog,0));
                        visited[treeLog.b.first][treeLog.b.second][treeLog.dir] = true;
                        break;
                }
            }
        }
    }
    while(!q.empty()){
        Log cur = q.front().first;
        int cnt = q.front().second;
        int y = cur.a.first;
        int x = cur.a.second;
        int y2 = cur.b.first;
        int x2 = cur.b.second;
        int y3 = cur.c.first;
        int x3 = cur.c.second;
        int dir = cur.dir;
        q.pop();
        if(graph[y][x] == 'E' && graph[y2][x2] == 'E' && graph[y3][x3] == 'E'){
            cout << cnt << "\n";
            return 0;
        }
        for(int i = 0; i < 5; i++){
            Log temp;
            switch(i){
                case 0: 
                    if (y== 0 || y2 == 0 || y3 == 0)
                        break;
                    if( graph[y-1][x] == '1'|| graph[y2-1][x2] == '1' || graph[y3-1][x3] == '1')
                        break;
                    decl(&temp,y -1, x, y2 - 1, x2, y3 -1, x3, dir);
                    if(!visited[temp.b.first][temp.b.second][temp.dir]){
                        q.push(make_pair(temp, cnt +1));
                        visited[temp.b.first][temp.b.second][temp.dir] = true;
                    }
                    break;
                case 1:
                    if(y == N -1 || y2 == N -1 || y3 == N -1)
                        break;
                    if(graph[y +1][x] == '1' || graph[y2+1][x2] == '1' || graph[y3 +1][x3] == '1')
                        break;
                    decl(&temp, y+1, x, y2+1, x2, y3+1, x3, dir);
                    if(!visited[temp.b.first][temp.b.second][temp.dir]){
                        q.push(make_pair(temp,cnt +1));
                        visited[temp.b.first][temp.b.second][temp.dir] = true;
                    }
                    break;
                case 2:
                    if( x == 0 || x2 == 0 || x3 == 0)
                        break;
                    if(graph[y][x-1] == '1' || graph[y2][x2 -1] == '1' || graph[y3][x3 -1] == '1')
                        break;
                    decl(&temp, y,x-1, y2, x2-1, y3, x3-1,dir);
                    if(!visited[temp.b.first][temp.b.second][temp.dir]){
                        q.push(make_pair(temp, cnt+1));
                        visited[temp.b.first][temp.b.second][temp.dir] = true;
                    }
                    break;
                case 3:
                    if(x == N - 1 || x2 == N -1 || x3 == N-1)
                        break;
                    if(graph[y][x+1] == '1' || graph[y2][x2 +1] == '1' || graph[y3][x3 +1] == '1')
                        break;
                    decl(&temp, y, x +1, y2, x2 + 1, y3, x3 +1,dir);
                    if(!visited[temp.b.first][temp.b.second][temp.dir]){
                        q.push(make_pair(temp, cnt +1));
                        visited[temp.b.first][temp.b.second][temp.dir] = true;
                    }
                    break;
                case 4:
                    if(dir == 0){
                        if( x- 1 < 0 || x2 -1 < 0 || x3 -1 <0)
                            break;
                        if(x + 1 >= N || x2 +1 >= N || x3 +1 >= N)
                            break;
                        if(graph[y][x -1] == '1' || graph[y][x+1] == '1')
                            break;
                        if(graph[y2][x2-1] == '1' || graph[y2][x+1] == '1')
                            break;
                        if(graph[y3][x3 -1] == '1' || graph[y3][x3+1] == '1')
                            break;
                        decl(&temp, y+1, x-1, y2,x2, y3 -1, x3+1, 1-dir);
                    }else{
                        if(y-1 <0 || y2 - 1 <0 || y3 -1 < 0)
                            break;
                        if(y+1>= N || y2 + 1 >= N || y3 +1 >= N)
                            break;
                        if(graph[y -1][x] == '1' || graph[y+1][x] =='1')
                            break;
                        if(graph[y2-1][x2] == '1' || graph[y2 +1][x2] == '1')
                            break;
                        if(graph[y3-1][x3] == '1' || graph[y3+1][x3] == '1')
                            break;
                        decl(&temp,y-1, x+1, y2,x2, y3+1,x3 -1, 1 -dir);
                    }
                    if(!visited[temp.b.first][temp.b.second][temp.dir]){
                        q.push(make_pair(temp, cnt +1));
                        visited[temp.b.first][temp.b.second][temp.dir] = true;
                    }
                    break;
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}
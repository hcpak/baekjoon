#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 251
using namespace std;
int graph[MAX][MAX];
bool visited[MAX][MAX] = {};
int R,C;
int w_count, s_count;
void dfs(int x, int y){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    if(graph[x][y]  == 2){
        s_count++;
    }
    if(graph[x][y]  == 3){
        w_count++;
    }
    // cout << x << " " << y <<"/";
    visited[x][y] = true;
    int new_x, new_y;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <R){
            if(new_y>= 0 && new_y <C){
                if(graph[new_x][new_y] != 1 && visited[new_x][new_y] == false){
                    dfs(new_x,new_y);
                }
            }
        }
    }
}
int main(){
    char ch;
    cin >> R >> C;
    for(int i = 0;i <R;i++){
        for(int j =0;j<C;j++){
            cin >> ch;
            switch(ch){
                case '.':
                    graph[i][j] = 0;
                    break;
                case '#':
                    graph[i][j] = 1;
                    break;
                case 'o':
                    graph[i][j] = 2;
                    break;
                case 'v':
                    graph[i][j] = 3;
                    break;
            }
        }
    }
    int w_ans=0, s_ans=0;
    for(int x = 0; x< R; x++){
        for(int y = 0; y< C; y++){
            if(graph[x][y] != 1 && visited[x][y] == false){
                w_count =0;
                s_count = 0;
                dfs(x,y);
                if(s_count > w_count){
                    s_ans += s_count;
                }else{
                    w_ans += w_count;
                }
                // cout <<endl;
            }
        }
    }
    cout << s_ans <<" " << w_ans;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX 100
using namespace std;
void dfs(bool graph[][MAX], int x, int y,int x_end ,int y_end){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    graph[x][y] = false;
    int new_x, new_y;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <x_end){
            if(new_y>= 0 && new_y <y_end){
                if(graph[new_x][new_y] == true){
                    dfs(graph ,new_x,new_y, x_end, y_end);
                }
            }
        }
    }
}
int main(){
    int N,  BIG =0;
    int map[MAX][MAX];
    bool graph[MAX][MAX];
    cin >> N;
    for(int i =0; i< N;i++){
        for(int j=0; j< N; j++){
            cin >> map[i][j];
            if(BIG < map[i][j]){
                BIG = map[i][j];
            }
        }
    }
    int counting, answer;
    for(int i=1;i<=BIG;i++){
        for(int j =0;j < N;j++){
            memset(graph[j], false, sizeof(bool)* N);
        }
        for(int x = 0; x< N; x++){
            for(int y = 0; y< N; y++){
                if(map[x][y] >= i){
                    graph[x][y] = true;
                }
            }
        }
        counting = 0;
        for(int x = 0; x< N; x++){
            for(int y = 0; y< N; y++){
                if(graph[x][y]== true){
                    dfs(graph,x,y,N,N);
                    counting++;
                }
            }
        }
        if(counting > answer){
            answer = counting;
        }
    }
    cout << answer;
    return 0;
}
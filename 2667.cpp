#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define MAX 25
using namespace std;
void dfs(int graph[][MAX],int *counting, int x, int y,int x_end ,int y_end){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    graph[x][y] = 0;
    int new_x, new_y;
    *counting = *counting + 1;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <x_end){
            if(new_y>= 0 && new_y <y_end){
                if(graph[new_x][new_y] == 1){
                    dfs(graph,counting ,new_x,new_y, x_end, y_end);
                }
            }
        }
    }
}
int main(){
    int N;
    cin >> N;
    int map[MAX][MAX];
    vector<int> answer;
    char c;
    for(int i =0; i< N;i++){
        for(int j =0;j< N;j++){
            cin >> c;
            map[i][j] = c- 48;
        }
    }
    int counting = 0;
    int count =0;
    for(int x = 0; x< N; x++){
        for(int y = 0; y< N; y++){
            if(map[x][y] == 1){
                counting =0;
                dfs(map, &counting,x,y,N,N);
                answer.push_back(counting);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout <<answer.size()<<endl;
    for(int i = 0; i<answer.size();i++){
        cout << answer[i]<<endl;
    }
    return 0;
}
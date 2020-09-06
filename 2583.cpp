// 입력 잘 못 받아서 문제 개 많이 틀림.
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#define MAX 102
using namespace std;
void dfs(bool graph[][MAX],int *counting, int x, int y,int x_end ,int y_end){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    graph[x][y] = true;
    int new_x, new_y;
    *counting = *counting + 1;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <x_end){
            if(new_y>= 0 && new_y <y_end){
                if(graph[new_x][new_y] == false){
                    dfs(graph,counting ,new_x,new_y, x_end, y_end);
                }
            }
        }
    }
}
int main(){
    int M, N, K, a_x,a_y,b_x,b_y;
    cin >> M>>N >>K;
    vector<int> answer;
    bool graph[MAX][MAX];
    int check[MAX];
    for(int i = 0 ;i<N;i++){
        for(int j = 0; j<M;j++){
            graph[i][j] = false;
        }
    }
    for(int i= 0 ; i< K;i++){
        cin >> a_x >> a_y >> b_x >> b_y;
        for(int j = 0; j< b_x-a_x;j++){
            for(int k = 0; k< b_y -a_y;k++){
                graph[a_x+j][a_y+k] = true;
            }
        }
    }
    // for(int y=M-1; y>=0; y--){
    //     for(int x=0;x<N;x++){
    //         cout << graph[x][y] <<" ";
    //     }
    //     cout <<endl;
    // }
    int count = 0;
    int counting;
    for(int y=M-1; y>=0; y--){
        for(int x=0;x<N;x++){
            if(graph[x][y] == false){
                counting =0;
                dfs(graph, &counting,x,y,N,M);
                count++;
                answer.push_back(counting);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout << count <<endl;
    for(int i=0;i<count;i++){
        if(i != 0){
            cout <<" ";
        }
        cout <<answer[i];
    }
    return 0;
}
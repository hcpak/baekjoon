#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#define MAX 100
using namespace std;
char graph[MAX][MAX];
bool check[MAX][MAX];
void dfs(char c, int x, int y,int x_end ,int y_end){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    check[x][y] = true;
    int new_x, new_y;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <x_end){
            if(new_y>= 0 && new_y <y_end){
                if(graph[new_x][new_y] == c && check[new_x][new_y] ==false){
                    dfs(c,new_x,new_y, x_end, y_end);
                }
            }
        }
    }
}
void new_dfs(char c, int x, int y,int x_end ,int y_end){
    int x_pos[4] = {-1,0,1,0}, y_pos[4] = {0,1,0,-1};
    check[x][y] = true;
    int new_x, new_y;
    for(int i = 0; i<4;i++){
        new_x = x + x_pos[i];
        new_y = y + y_pos[i];
        if(new_x>= 0 && new_x <x_end){
            if(new_y>= 0 && new_y <y_end){
				if(c == 'R' || c =='G'){
					if((graph[new_x][new_y] == 'R' || graph[new_x][new_y] == 'G' )&& check[new_x][new_y] ==false){
						new_dfs(c,new_x,new_y, x_end, y_end);
					}
				}else if(graph[new_x][new_y] == c && check[new_x][new_y] ==false){
                    new_dfs(c,new_x,new_y, x_end, y_end);
                }
            }
        }
    }
}
int main(){
	int N;
	cin >> N;
	for(int i =0;i<N;i++){
		for(int j = 0;j<N;j++){
			cin >> graph[i][j];
			check[i][j] = false;
		}
	}
	int count=0;
	for(int x = 0; x< N; x++){
        for(int y = 0; y< N; y++){
            if(check[x][y] ==false){
                count++;
                dfs(graph[x][y],x,y,N,N);
            }
        }
    }
	for(int i =0;i<N;i++){
		for(int j = 0;j<N;j++){
			check[i][j] = false;
		}
	}
	int new_count = 0;
	for(int x = 0; x< N; x++){
        for(int y = 0; y< N; y++){
            if(check[x][y] ==false){
                new_count++;
                new_dfs(graph[x][y],x,y,N,N);
            }
        }
    }
	cout <<count <<" " << new_count;
	return 0;
}
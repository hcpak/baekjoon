#include <cstdio>
using namespace std;
int n;
int Map[15][15] ={}, temp_Map[15][15];
int answer =0;
int dx[8] = {-1,0,1},
    dy[8] = {1,1,1};
bool inbound_coordinate(int x, int y){
    if(x <0 || x>=n)
        return false;
    if(y < 0 || y>=n)
        return false;
    return true;
}

void check_queen_can_go(int x, int y){
    for(int i=0; i<3;i++){
        int temp_x = x, temp_y =y;
        while(inbound_coordinate(temp_x+dx[i],temp_y+dy[i])){
            temp_x = temp_x +dx[i];
            temp_y = temp_y +dy[i];
            if(!Map[temp_x][temp_y])
                Map[temp_x][temp_y] = true;
        }
    }
}
void dfs(int cnt){
    if(cnt == n){
        answer++;
    }else{
        for(int i =0; i<n;i++){
            if(!Map[i][cnt]){
                int temp_Map[15][15];
                for(int x = 0; x<n;x++){
                    for(int y =0; y<n;y++){
                        temp_Map[x][y] = Map[x][y];
                    }
                }
                check_queen_can_go(i,cnt);
                Map[i][cnt] = 2;
                dfs(cnt+1);
                Map[i][cnt] = false;
                for(int x = 0; x<n;x++){
                    for(int y =0; y<n;y++){
                        Map[x][y] = temp_Map[x][y];
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    printf("%d\n",answer);
}
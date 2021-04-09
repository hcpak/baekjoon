#include <cstdio>
using namespace std;
int m, n;
bool inbound(int x, int y){
    if( x<0 || x >= n){
        return false;
    }
    if( y<0 || y >= m){
        return false;
    }
    return true;
}
int main(){
    scanf("%d %d", &m, &n);
    bool visited[100][100] = {};
    int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    int answer =0;
    int cur_x =0, cur_y = 0;
    visited[0][0] = true;
    for(int i =1; i< m *n; i++){
        int dir = answer %4;
        int next_x = cur_x +  dx[dir], next_y = cur_y + dy[dir];
        if(inbound(next_x,next_y)){
            if(!visited[next_x][next_y]){
                cur_x = next_x;
                cur_y = next_y;
                visited[next_x][next_y] = true;
            }else{
                answer++;
                dir = answer % 4;
                cur_x = cur_x + dx[dir], cur_y =cur_y + dy[dir];
                visited[cur_x][cur_y] = true;
            }
        }else{
            answer++;
            dir = answer % 4;
            cur_x = cur_x + dx[dir], cur_y =cur_y + dy[dir];
            visited[cur_x][cur_y] = true;
        }
    }
    printf("%d",answer);
    return 0;
}
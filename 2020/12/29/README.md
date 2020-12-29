# 백트래킹 대표문제 N-Queen[백준 9663]
맨 처음에 이 문제를 풀었을 때 시간초과가 났었다.
```
int dx[8] = {-1,0,1,-1,1,-1,0,1},
    dy[8] = {-1,-1,-1,0,0,1,1,1};
    
void check_queen_can_go(int x, int y){
    for(int i=0; i<8;i++){
        int temp_x = x, temp_y =y;
        while(inbound_coordinate(temp_x+dx[i],temp_y+dy[i])){
            temp_x = temp_x +dx[i];
            temp_y = temp_y +dy[i];
            if(!Map[temp_x][temp_y])
                Map[temp_x][temp_y] = true;
        }
    }
}
```
그때 코드가 다음과 같았는데 8개 방향으로 queen의 경로를 확인했었다. 

하지만 생각해보니 다음과 같이 8개 방향으로 queen의 경로를 확인할 필요 없이 밑의 3개의 방향만 체크하면 됬었기에 다음과 같이 코드를 바꿨다.
```
int dx[3] = {-1,0,1},
    dy[3] = {1,1,1};
    
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
```
그래서 시간 초과가 나지 않고 문제를 해결할 수 있었다.


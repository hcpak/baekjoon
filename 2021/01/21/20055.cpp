#include <cstdio>
#include <deque>
using namespace std;
deque<int> robot;
int belt[201];
int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i =0; i< 2*N;i++){
        scanf("%d",&belt[i]);
    }
    int cnt =0, iter =0, answer= 0;
    // 4. 내구도가 0인 칸의 개수가 K개 이상이면 과정 종료
    while(cnt < K){
        // 1. 벨트가 한 칸 회전한다.
        answer++;
        if(iter -1 < 0){
            iter =2*N -1;
        }else{
            iter--;
        }
        // 2. 가장 먼저 벨트에 올라간 로봇부터 이동
        int down = iter+ N - 1 >= 2*N ? iter - N -1: iter+N-1;
        if(robot.size() >0){ //로봇이 존재할때,
            if(robot[0] == down ){ //내려가는 위치
                robot.pop_front();
            }
            for(int i=0; i< robot.size();i++){
                int robot_location = robot[i] + 1>= 2*N ? 0 : robot[i] +1;
                if (belt[robot_location]){
                    if( i ==0){
                        robot[i] = robot_location;
                        belt[robot_location]--;
                        if(belt[robot_location] ==0)
                            cnt++;
                    }else{
                        if(robot[i-1] != robot_location){
                            robot[i] = robot_location;
                            belt[robot_location]--;
                            if(belt[robot_location] ==0)
                                cnt++;
                        }
                    }
                    
                }
            }
            if(robot.size() >0 &&robot[0] == down ){ //내려가는 위치
                robot.pop_front();
            }
        }
        
        // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
        if(belt[iter]){
            robot.push_back(iter);
            belt[iter]--;
            if(belt[iter] == 0){
                cnt++;
            }
        }
    }
    printf("%d\n",answer);
    return 0;
}
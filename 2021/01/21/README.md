# 백준 구현 및 완전탐색
## 괄호 추가하기 16637
### 핵심 알고리즘: 괄호를 추가할 때랑 추가하지 않을 때 모두 구해야 하므로 다음과 같이 모두 탐색할 수 있도록 만들었다.
```
void dfs(int sum, int i){
    if(i ==number.size() -1){
        result = max(result, sum);
        return;
    }
    int next_sum = switch_operators(sum, number[i+1], operators[i]);
    dfs(next_sum, i+1); // 괄호 추가하지 않는 부분
    if(i+2 < number.size()){ // 괄호 추가하는 부분
        int bracket = switch_operators(number[i+1], number[i+2], operators[i+1]);
        next_sum = switch_operators(sum, bracket, operators[i]);
        dfs(next_sum, i+2);
    }
}
```

## 컨베이어 벨트 위의 로봇 20055
### 핵심 아이디어: 문제에서 원하는 순서대로 구현
```
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
```


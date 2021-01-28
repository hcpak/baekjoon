# 백준 DP
## 숫자카드 2591
### 핵심아이디어: 완전 탐색과 같이 풀었는데 답은 맞았다. dp로 푸는 방법을 익혀야 겠다.
```
void dfs(int i){
    if(i == len){
        answer++;
        return;
    }
    int first = input[i] -'0';
    if(first == 0){
        return;
    }
    dfs(i+1);
    if(i+1 <len){
        int second = input[i+1] -'0';
        if(first*10 + second <= 34){
            dfs(i+2);
        }
    }
}
```
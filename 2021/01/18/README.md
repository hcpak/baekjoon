# 백준 이분탐색
## k번째 수 1939
### 핵심 아이디어
### 이분 탐색을 통해 k번째 수를 구하는데, N x N번을 다 할 필요없이 N번 줄을 통해 N으로 나눠준 값을 counting하면 된다.
```
long long start = 0, end = N*N+1;
while(start+1 <end){
    long long mid = (start+end)/2;
    long long count =0;
    for(int i=1; i<=N;i++){
        if( mid/i >=N){
            count += N;
        }else{
            count += mid/i;
        }
    }
    if(count >= k){
        end = mid;
    }else{
        start = mid;
    }
}
```
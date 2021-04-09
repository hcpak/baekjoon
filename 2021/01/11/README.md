# 백준 알고리즘 구현
## 다음 순열 10972
이 문제 다시 고민하고 보니까 해결이 된다. 사실 다른 블로그는 vector나 set으로 푸는 지 확인하다가 눈 대중으로 풀이 방법을 깨닫게 된 거 같다. 
이 문제를 통해 set과 vector일때가 size가 100000이면 sort이 제대로 돌아가지 않는다는 것을 깨달을 수 있었다.
### 핵심 아이디어
### 1. 뒤에서부터 앞으로 가면서, 증가 함수가 되는 지 확인한다.
### 2. 증가함수가 안되는 그 지점의 값 n를 기록한다. 또한 모든 부분이 증가함수이면 -1를 출력한다.
```
for(int i= N-1; i>0; i--){
    if(arr[i-1] <arr[i]){
        swap = i-1;
        break;
    }
    if( i ==1){
        printf("-1\n");
        return 0;
    }
}
```
### 3. 뒤에서부터 앞으로 가면서, 해당 값이 n보다 클 때 swap하고 순회를 멈춘다. 그 다음 swap한 그 다음 위치부터 끝까지 증가함수로 sorting을 한다. 
```
for(int i = N-1; i>swap; i--){
    if(arr[swap] < arr[i]){
        int iter = arr[swap];
        arr[swap] = arr[i];
        arr[i] = iter;
        break;
    }
}
sort(arr.begin()+swap+1, arr.end());
```


## 부분 순열의 합 1182
### 핵심 아이디어 
### 1. 해당 인덱스에 있는 숫자를 더하는 경우, 해당 인덱스 있는 숫자 더하지 않는 경우를 탐색한다.
```
void dfs(int id, int sum){
    if( id  == N){
        if(sum == S)
            answer++;
    }else{
        dfs(id+1, sum +arr[id]);
        dfs(id+1, sum);
    }
}
```
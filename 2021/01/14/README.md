# 백준 알고리즘 구현
## 이전 순열 10973
색종이 붙이기를 너무 풀기 싫어서 다음 순열의 다른 버전인 이전 순열을 풀게 되었다. 탐색을 뒤에서부터가 아니라 앞에서부터 하면 될 줄 알았는데 그러면 반례가 많이 생겼다. 그래서 1번 틀렸다.
### 핵심 아이디어
### 1. 뒤에서부터 앞으로 가면서, 감소 순열가 되는 지 확인한다.
### 2. 증가함수가 안되는 그 지점의 값 n를 기록한다. 또한 모든 부분이 감소 순열이면 -1를 출력한다.
```
for(int i= N-1; i>0; i--){
        if(arr[i-1] > arr[i]){
            swap = i-1;
            break;
        }
        if( i == 1){
            printf("-1\n");
            return 0;
        }
    }
```
### 3. 뒤에서부터 앞으로 가면서, 해당 값이 n보다 작을때 때 swap하고 순회를 멈춘다. 그 다음 swap한 그 다음 위치부터 끝까지 감소함수로 sorting을 한다. 
```
for(int i = N-1; i> swap; i--){
        if(arr[swap] > arr[i]){
            int iter = arr[swap];
            arr[swap] = arr[i];
            arr[i] = iter;
            break;
        }
    }
    sort(arr.begin()+swap+1, arr.end(), greater<int>());
```

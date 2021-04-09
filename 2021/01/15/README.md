# 백준 알고리즘 구현
## 수 찾기 1920
### 핵심 아이디어
### 이분탐색
이 문제는 궁금한 게 위의 코드는 틀린데, 아래 코드는 맞다.
그 이유를 생각해봐야할 거 같다.
틀린 코드 
```
for(int i =0; i < M; i++){
    scanf("%d", &temp);
    int start = -1, end =N;
    while(start +1 < end){
        int mid= (start +end) /2;
        if(A[mid] <= temp){
            start = mid;
        }else{
            end = mid;
        }
    }
    if(A[start] == temp){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
```
맞는 코드
```
for(int i =0; i < M; i++){
    scanf("%d", &temp);
    int start = -1, end =N;
    while(start +1 < end){
        int mid= (start +end) /2;
        if(A[mid] < temp){
            start = mid;
        }else{
            end = mid;
        }
    }
    if(A[end] == temp){
        printf("1\n");
    }else{
        printf("0\n");
    }
}
```
## 나무 자르기 2805
### 핵심 아이디어
### 이분 탐색
이 문제는 
```
while(start+1 < end){
    int mid =(start+end)/2;
    long long left =0;
    for(int i= 0; i< N; i++){
        if(height[i] -mid >0){
            left += height[i] -mid;
        }
    }
    if(left >= M){
        start =mid;
    }else{
        end = mid;
    }
}
```
에서 left를 int로 해서 여러번 틀렸다. 값에 대해 조심해야겠다는 생각이 든다.

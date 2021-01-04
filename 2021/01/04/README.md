# 백준 이진탐색 10816 숫자카드 2
## 이진 탐색 풀이

### 핵심아이디어:
### 1. 인풋 값들을 정렬한다.
### 2. 이분탐색을 통해 값을 구한다. 하지만 여기서 중요한 점은 upper_bound와 lower_bound 두 값 모두 구해야한다는 점이다.
#### upper_bound는 찾고자 하는 값을 초과한 값이 처음 나오는 위치를 이분 탐색으로 찾는 과정
#### lower_bound는 찾고자 하는 값 이상이 처음 나오는 위치를 이분 탐색으로 찾는 과정이다.

간단한 문제인 줄 알았으나 생각보다 갖춰야할 점이 많았다. 평소에 잘 몰랐던 이진탐색을 다른 사람 도움 없이 구현해볼까하고 접근했었는데 여러가지로 배울 점이 많았다. 
```
int start = -1, end = n;
while(start+1 != end){
    int mid = (start +end) /2;
    if(target >arr[mid]){
        start = mid;
    }else{
        end = mid;
    }
}
```
여기서 start =0, end =n-1으로 설정하니, 0과 n-1 접근하지 않음을 알 수 있었다. 따라서 start,end 설정할 시 array index 범위에 벗어나는 가장 큰 start값과 가장 작은 end값을 설정해야한다는 것을 깨달았다.

또한 이 문제를 이진탐색으로 풀었는데 시간초과가 나왔었다. 시간 초과가 난 해당 코드는 다음과 같다.
```
for(int i =0; i<m;i++){
    scanf("%d", &temp);
    int start = -1, end= n;
    while(start+1 != end){
        int mid= (start +end) /2;
        if(temp > arr[mid]){
            start = mid;
        }else{
            end = mid;
        }
    }
    if(arr[end] == temp){
        int count =0;
        for(int j = end; j<n;j++){
            if(arr[j] == arr[end]){
                count++;
            }
        }
        printf("%d ",count);
    }else{
        printf("0 ");
    }
}
``` 

이진탐색으로 값을 찾긴 찾았는데 동일한 숫자의 개수를 구할 때, 다음과 같이 완전탐색으로 구했었다.
```
int count =0;
for(int j = end; j<n;j++){
    if(arr[j] == arr[end]){
        count++;
    }
}
```
이러면 만약 똑같은 수 n이 50만개가 인풋으로 들어오고, n를 찾는 인풋이 50만개가 들어오면 O(N^2)이므로 시간초과가 난다.
따라서 lower_bound와 upper_bound로 이진 탐색 O(logN)으로 찾아야 시간초과가 나지 않는다.

### 알고리즘의 실행속도는 O(NlogN)이다.

## 다른 풀이(Hash Map과 같은 풀이)
질문 검색 란을 찾아보다가, 들어오는 숫자마다 카운팅하면 오래 안걸리겠다고 생각해서 만들었는데 Hash Map과 같은 동작을 한다.
```
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 10000001
using namespace std;
int plus_count[MAX] ={};
int minus_count[MAX] ={};
int main(){
    int m, n;
    scanf("%d", &n);
    int temp;
    
    for(int i =0; i< n;i++){
        scanf("%d", &temp);
        if(temp >=0){
            plus_count[temp]++;
        }else{
            minus_count[-temp]++;
        }
    }
    scanf("%d", &m);
    for(int i =0; i<m;i++){
        scanf("%d", &temp);
        if(temp >= 0){
            printf("%d ",plus_count[temp]);
        }else{
            printf("%d ", minus_count[-temp]);
        }
    }
    printf("\n");
    return 0;
}
```

### 알고리즘의 속도는 O(N)이다.

# [2020/12/30] 백준 11051 dp문제

이 문제는 모듈러 계산으로 많이 틀렸다. 처음에 O(n) 코드로 짰는데 코드는 다음과 같다.
```
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int dp[501];
    dp[0]= 1;
    int half;
    if( n %2 != 0){
        half = n/2+1;
    }else{
        half = n/2;
    }
    for(int i=1; i<= half;i++){
        dp[i] = (dp[i-1] * (n - i + 1) / i)%10007; 
    }
    if(k <= half){
        printf("%d\n",dp[k]);
    }else{
        printf("%d\n", dp[n-k]);
    }
    return 0;
}
```
 모듈러 계산의 항등식은 덧셈 뺄셈 곱셈밖에 적용이 안된다. 따라서 내 계산에는 나눗셈이 있으므로, 모듈러 계산이 되지 않는다.
따라서 파스칼 삼각형으로 문제를 풀었다.

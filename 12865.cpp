// 내가 한 구상으로 2^100 시간 복잡도가 나왔다. 그래서 다른 블로그를 참고했다.
// 이전에 동전 1 풀면서 이런 형식을 느껴본 적 있었는데 전혀생각해보지 못했다.
// 근데도 3번 틀렸다. 그 이유를 다른 사람이 풀어본 풀이로 접근했다. 1번 물건을 여러번 사용할 수 있기 떄문이다.
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int dp[n+1][k+1],w[n+1],v[n+1];// dp 구상도 1차원 배열으로만 생각했다.
    for(int i=0;i<=n;i++){
        memset(dp[i],0,sizeof(int)*(k+1));
    }
    for(int i=1;i<=n;i++){
        scanf("%d %d",&w[i], &v[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j];
            if(j-w[i]>=0){
                //틀린 부분
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
                //dp[i][j] = max(dp[i][j],dp[i][j-w[i]]+v[i]);
                // 예시를 들면 1번 물건을 여러개 선택할 수 있었다.
                // 따라서 틀렸다.
            }
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}
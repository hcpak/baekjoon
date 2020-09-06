//2020/5/2번정도 틀렸다.
#include <cstdio>
#include <algorithm>
#include <string.h>
#define MAX 10001
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n, &k);
    int dp[k+1],coin[n];
    //초기화
    memset(dp,MAX,sizeof(int)*(k+1));
    dp[0] =0;
    for(int i=0;i<n;i++){
        scanf("%d",&coin[i]);
    }
    // 최소일때만 dp값이 바뀌도록 했다.
    for(int i =1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-coin[j]>=0){
                dp[i] = min(dp[i],dp[i-coin[j]]+1);
            }
        }
    }
    //이 부분을 빼먹어서 시간이 오래걸림
    if(dp[k] >= MAX){
        printf("-1");
    }
    else{
        printf("%d",dp[k]);
    }
    return 0;
}
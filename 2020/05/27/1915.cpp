// 이 문제 접근이 어려워서 https://suriisurii.tistory.com/13 풀이를 참고해서 풀어보았다.
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int temp, ans=0, dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        memset(dp[i],0,sizeof(dp[i]));
    }
    for(int i = 1; i<=n;i++){
        for(int j =1;j<=m;j++){
            scanf("%1d",&temp);
            if(temp == 1){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    printf("%d",ans*ans);
    return 0;
}
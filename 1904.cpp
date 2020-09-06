// 1트 성공
#include <cstdio>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1] +dp[i-2])%15746;
    }
    printf("%d",dp[n]);
    return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long n,x, dp[501][501] = {}, ans = 0;
    scanf("%lld", &n);
    for(long long i = 1; i<=n; i++ ){
        for(long long j=1; j<=i; j++){
            scanf("%lld",&x);
            dp[i][j] = max( dp[i-1][j], dp[i-1][j-1]) + x;
            if( i == n){
                ans = max(ans, dp[i][j]);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
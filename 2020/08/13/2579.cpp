#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long n, x;
    scanf("%lld",&n);
    long long dp[301][2] ={};
    for(long long i = 1; i <= n; i++){
        scanf("%lld", &x);
        if(i -1 >0 ){
            dp[i][1] = dp[i-1][0];
        }
        if( i - 2 >0){
            dp[i][0] = max(dp[i-2][1],dp[i-2][0]);
        }
        dp[i][0] += x;
        dp[i][1] += x;
    }
    printf("%lld",max(dp[n][0], dp[n][1]));
    return 0;
}
#include <cstdio>
#include <algorithm>
#define MAX 5000
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int dp[n];
    for(int i =0; i<=n; i++){
        dp[i] = MAX;
    }
    dp[3] = 1;
    dp[5] = 1;
    for(int i =6; i <= n;i++){
        dp[i] = min(dp[i], dp[i-3] +1);
        dp[i] = min(dp[i], dp[i-5] +1);
    }
    if(dp[n] == MAX){
        printf("-1");
    }else{
        printf("%d",dp[n]);
    }
    return 0;
}
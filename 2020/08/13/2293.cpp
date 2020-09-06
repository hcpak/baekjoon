#include <cstdio>
using namespace std;
int main(){
    int n, k, coin[101], dp[100001] = {};
    scanf("%d %d",&n, &k);
    for(int i =0; i < n; i++){
        scanf("%d", &coin[i]);
    }
    for(int i = 0; i<n; i++){
        dp[coin[i]] += 1;
        for(int j  = 1; j <= k; j++){
            if(j - coin[i] >= 0) dp[j] += dp[j-coin[i]];
        }
    }
    printf("%d",dp[k]);
    return 0;
}
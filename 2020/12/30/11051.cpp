#include <cstdio>
#define MOD 10007
using namespace std;
int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    long long dp[1001][1001] ={};
    dp[1][0] =1;
    dp[1][1] =1;
    for(int height = 1; height<= n;height++){
        for(int width =0; width <= height; width++){
            dp[height][width] = dp[height][width] %MOD;
            if(height != n){
                dp[height+1][width] += dp[height][width];
                dp[height+1][width+1] += dp[height][width];
            }
        }
    }
    printf("%lld\n",dp[n][k]);
    return 0;

}
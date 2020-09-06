#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    scanf("%lld", &n);
    long long input_arr[1001] ={}, dp[1001]={}, answer=0;    
    for(long long i = 1; i<=n;i++){
        scanf("%lld", &input_arr[i]);
        dp[i]= 1;
        for(long long j= 1; j<i ;j++){
            if(input_arr[j] < input_arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        answer = max(answer, dp[i]);
    }
    printf("%lld",answer);
    return 0;
}
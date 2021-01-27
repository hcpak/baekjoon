#include <cstdio>
#include <algorithm>
#define MAX 1500001
using namespace std;
int T[MAX], P[MAX];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n;i++){
        scanf("%d %d",&T[i], &P[i]);
    }
    int dp[MAX] ={},answer =0;
    for(int i = 0; i<n;i++){
        if(i != 0){
            dp[i] = max(dp[i], dp[i-1]);
        }
        if(i + T[i] <= n){
            dp[i + T[i]] = max(dp[i + T[i]],dp[i]+P[i]);
            answer =max(answer,dp[i+T[i]]);
        }
        printf("%d ",dp[i]);
    }
    printf("\n%d\n",answer);
    return 0;
}
#include <cstdio>
using namespace std;
int main(){
    int n, m, temp;
    scanf("%d %d",&n,&m);
    long dp[n+1];
    dp[0] =0;
    for(int i =1;i<=n;i++){
        scanf("%d", &temp);
        dp[i] = dp[i-1] + (long)temp;
    }
    int i,j;
    for(int k =0;k<m;k++){
        scanf("%d %d", &i, &j);
        printf("%ld",dp[j] -dp[i-1]);
        if(k != m-1)
            printf("\n");
    }
    return 0;
}
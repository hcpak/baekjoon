#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n,m,d= 3,x;
    scanf("%d %d",&n,&m);
    int arr[n+1][m+2];
    long long dp[n+1][m+2][d];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m+1; j++){
            for(int k=0; k<d; k++){
                dp[i][j][k] = -101;
            }
        }
    }
    for(int i =1; i<=n;i++){
        for(int j =1; j<=m;j++){
            scanf("%d",&x);
            arr[i][j] = x;
            for(int k = 0; k<=2;k++){
                dp[i][j][k] = arr[i][j];
            }
        }
    }
    // 첫번째 줄:
    for(int j = 2; j <= m; j++){
        dp[1][j][2] = dp[1][j-1][2] + arr[1][j] ;
    }
    for(int i = 2; i<=n-1;i++){
        for(int j = 1; j<=m;j++){
            dp[i][j][0] = dp[i-1][j][2] +arr[i][j];
            dp[i][j][1] = dp[i-1][j][2] +arr[i][j];
            if(j !=1)
                dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0] + arr[i][j]);
        }
        for(int j = m-1; j>=1;j--){
            dp[i][j][1] = max(dp[i][j][1], dp[i][j+1][1] + arr[i][j]);
        }
        for(int j = 1; j<=m;j++){
            dp[i][j][2] = max(dp[i][j][0], dp[i][j][1]);
        }
    }    
    if( n != 1){
        for(int j = 1; j <=m; j++){
            dp[n][j][2] = dp[n-1][j][2] + arr[n][j];
            if(j != 1)
                dp[n][j][2] = max(dp[n][j][2],dp[n][j-1][2] + arr[n][j]);
        }
    }
    printf("%lld",dp[n][m][2]);
    return 0;
}

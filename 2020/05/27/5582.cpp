#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int main( ){
    string a,b;
    cin >> a >> b;
    int a_size = a.size(), b_size =b.size(),dp[a_size+1][b_size+1];
    for(int i=0;i<=a_size;i++){
        memset(dp[i],0,sizeof(dp[i]));
    }
    int ans =0;
    for(int i=1;i<=a_size;i++){
        for(int j=1;j<=b_size;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
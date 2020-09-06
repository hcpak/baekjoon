// #include <iostream>
// #include <algorithm>
// #define NUM 1001
// using namespace std;
// int main (){
// 	int N;
//     cin >> N;
//     int arr[NUM]={},dp[NUM]={};
//     for(int i =1; i<=N;i++){
//         cin >> arr[i];
//     }
//     int result = 0;
//     for(int i = 1; i<=N;i++){
//         for(int j = 0; j<=N;j++){
//             if(arr[i]<arr[j])
//                 dp[i]= max(dp[i],dp[j]+1);
//         }
//         if(dp[i] == 0)
//                 dp[i] =1;
//         if(result < dp[i]){
//             result = dp[i];
//         }
//     }
//     cout << result;
// 	return 0;
// }

#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    int arr[N+1],dp[N+1];
    for(int i =1;i<=N;i++){
        scanf("%d",&arr[i]);
    }
    memset(dp,0,sizeof(dp));
    int ans = 0;
    for(int i = 1; i<=N;i++){
        for(int j=i+1; j<=N;j++){
            if(arr[i] >arr[j]){
                dp[j] = max(dp[j],dp[i] +1);
                ans = max(ans,dp[j]);
            }
        }
    }
    printf("%d",ans+1);
    return 0;
}

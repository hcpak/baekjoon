// 예전 내 코드를 분석해서 최종으로 짠 것
// dp를 2차원 배열에서 차원 배열으로 만들어 본 것
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    memset(arr,0,sizeof(arr));
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[1] = arr[1];
    int ans = arr[1];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(arr[i]<arr[j]){
                dp[j] = max(dp[i] +arr[j],dp[j]);
                ans = max(ans, dp[j]);
            }
        }
        dp[i+1] = max(arr[i+1],dp[i+1]);
    }
    printf("%d",ans);
    return 0;
}
// 적어도 2차원 배열이 필요한 줄 알았는데... 굳이 그럴 필요까진 없었네
// 엄청 틀렸다.
// #include <cstdio>
// #include <algorithm>
// #include <string.h>
// using namespace std;
// int main(){
//     int n;
//     scanf("%d",&n);
//     int arr[n+1];
//     memset(arr,0,sizeof(arr));
//     for(int i=1;i<=n;i++){
//         scanf("%d",&arr[i]);
//     }
//     int dp[n+1][n+1];
//     for(int i =0;i<=n;i++){
//         memset(dp[i],0,sizeof(dp[i]));
//     }
//     int ans =arr[1];
//     dp[1][1] = arr[1];
//     for(int i=1;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             if(arr[i]<arr[j]){
//                 dp[i][j] = max(dp[i][i] +arr[j],dp[i-1][j]);
//                 ans = max(ans, dp[i][j]);
//             }else{
//                 dp[i][j] =dp[i-1][j];;
//             }
//         }
//         dp[i+1][i+1] = max(arr[i+1],dp[i][i+1]);
//     }
//     printf("%d",ans);
//     return 0;
// }

// 예전 풀이가 더 깔끔했던 건 왜 그럴까...
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
//             if(arr[i]>arr[j])
//                 dp[i]= max(dp[i],dp[j]+arr[i]);
//         }
//         if(result < dp[i]){
//             result = dp[i];
//         }
//     }
//     cout << result;
// 	return 0;
// }

// #include <cstdio>
// #include <iostream>
// int main(){
//     int in;
//     scanf("%d",&in);
//     int *arr = new int [in+1];
//     arr[1] = 0;
//     for(int i =2; i<=in;i++){
//         arr[i] = arr[i-1] +1;
//         if( i%2 == 0 && arr[i] > arr[i/2] + 1){
//             arr[i] = arr[i/2] +1;
//         }
//         if(i%3 == 0 && arr[i] > arr[i/3] + 1 ){
//             arr[i] = arr[i/3] +1;
//         }
//     }
//     printf("%d",arr[in]);
//     delete [] arr;
//     return 0;
// }
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N;
    scanf("%d",&N);
    int dp[1000001] ={};
    int a, b, c;
    for(int i=2;i<=N;i++){
        dp[i] = dp[i-1] +1;
        if(i%2 ==0){
            dp[i] = min(dp[i],dp[i/2] +1);
        }
        if(i%3==0){
            dp[i] = min(dp[i],dp[i/3] +1);
        }
    }
    printf("%d",dp[N]);
    return 0;
}

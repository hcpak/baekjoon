#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    int arr[10000],dp[1000]={1},answer=0;
    for(int i =0;i<N;i++){
        scanf("%d", &arr[i]);
    }
    for(int i =0; i<N;i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j]<arr[i]){
                dp[i] =max(dp[i], dp[j]+1);
            }
        }
        answer = max(dp[i],answer);
    }
    printf("%d\n",answer);
    return 0;
}
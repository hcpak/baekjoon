#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int A[1001];
    int dp[1001];
    int answer =0;
    for(int i =0; i< n;i++){
        scanf("%d", &A[i]);
    }
    for(int i =0; i < n;i++){
        dp[i] =1;
        for(int j =0; j <i;j++){
            if(A[i] >A[j]){
                dp[i] = max(dp[i], dp[j]+1);
            } 
        }
        answer = max(answer, dp[i]);
    }
    printf("%d",answer);
    return 0;
}
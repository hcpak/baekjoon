#include <iostream>
#include <algorithm>
#define num 10001
using namespace std;
int main(){
	int n;
	cin >> n;
    long arr[num];
	for(int i = 1; i<=n;i++){
        cin >> arr[i];
    }
    // 연속해서 두잔을 마실 수 없다고 생각해 2차원으로 풀었는데, 사실 1차원으로 풀 수 있는 문제였다. 그래서 2차원으로 나눈 예제는 공통된 값을 갖는 경우가 있었고 식이 지저분하다.
    // 그리고 식이 틀려 남의 블로그에 들어가 안되는 예제를 보니 돌아가지 않았다.
    //long dp[num][2]={};
    // dp[1][0] = arr[1];
    // dp[1][1] = arr[1];
    // dp[2][0] = arr[2];
    // dp[2][1] = arr[1]+arr[2];
    // long maximum=0;
    // if(n == 1){
    //     maximum = arr[1];
    //     cout << maximum;
    //     return 0;
    // }
    // else if(n ==2){
    //     maximum = arr[1]+arr[2];
    //     cout << maximum;
    //     return 0;
    // }
    // for(int i = 3; i<=n;i++){
    //     dp[i][0] = max(max(dp[i-2][0],dp[i-2][1])+arr[i],dp[i-1][1]);
    //     dp[i][1] = max(dp[i-3][0]+arr[i-1],dp[i-1][0])+arr[i];;
    //     if(maximum < max(dp[i][0] ,dp[i][1])){
    //         maximum = max(dp[i][0] ,dp[i][1]);
    //     }
    // }
    // cout << maximum;
    int dp[num];
    dp[1] = arr[1];
    dp[2] = arr[2] +arr[1];
    for(int i = 3; i<=n;i++){
        dp[i] = max(dp[i-3]+arr[i-1] + arr[i], dp[i-2]+ arr[i]);
        dp[i] = max(dp[i],dp[i-1]);
    }
    cout << dp[n];
	return 0;
}
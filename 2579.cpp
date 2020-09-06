#include <iostream>
#include <algorithm>
#define num 301
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    long arr[num], dp[num];
    for(int i= 1; i<=n;i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    for(int i = 3; i<=n; i++){
        dp[i] = max(dp[i-3]+arr[i-1], dp[i-2])+arr[i];
        // 이걸 굳이 안넣어도 되는데 넣었다. 이게 큰 잘못이지.
        // if( i != n)
        //     dp[i] = max(dp[i],dp[i-1]);
    }
    cout << dp[n];
	return 0;
}
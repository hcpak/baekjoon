#include <iostream>
#define num 100001
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    cin >> n;
    long arr[num], dp[num];
    for(int i = 1; i<=n;i++){
        cin >> arr[i];
    }
    long result = -1001;
    dp[0] = 0;
    for(int i = 1; i<=n;i++){
        if(dp[i-1] >= 0)
            dp[i] = dp[i-1] +arr[i];
        else 
            dp[i] = arr[i];
        if(result < dp[i])
            result = dp[i];
    }
    cout << result;
	return 0;
}
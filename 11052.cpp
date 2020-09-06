#include <iostream>
#include <algorithm>
#define NUM 1001
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    long long price[NUM] = {}, dp[NUM] = {};
    for(int i =1; i<= N; i++){
        cin >> price[i];
    }
    for(int i =1 ;i<= N; i++){
        for(int j = 0 ; j <= i; j++){
            dp[i] = max(dp[i],dp[i-j]+price[j]);
        }
    }
    cout << dp[N];
    return 0;
}
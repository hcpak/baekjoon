#include <iostream>
#define mod 10007
using namespace std;
int main (){
	int n;
	cin >> n;
	int dp[1001][10] = {};
	for(int i = 0; i<10;i++){
		dp[1][i] =1;
	}
	for(int i = 2;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int k = j; k<10;k++){
				dp[i][j] = (dp[i][j] + dp[i-1][k])%mod;
			}
		}
	}
	int sum = 0;
	for(int i =0;i<10;i++){
		sum = (sum  + dp[n][i])%mod;
	}
	cout << sum;
	return 0;
}

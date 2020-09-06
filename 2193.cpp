// #include <iostream>
// using namespace std;
// int main (){
// 	long  n;
// 	cin >> n;
// 	long  dp[91][2] ={};
// 	dp[1][1] =1;
// 	for(int i=2; i<=n;i++){
// 		dp[i][0] += dp[i-1][0] + dp[i-1][1];
// 		dp[i][1] += dp[i-1][0];
// 	}
// 	long sum = dp[n][0] + dp[n][1];
// 	cout << sum;
// 	return 0;
// }
#include <cstdio>
int main(){
	long N;
	scanf("%ld", &N);
	long ** arr = new long * [N+1];
	for(int i = 0;i <=N;i++){
		arr[i] = new long[2];
	} 
	arr[1][0] = 0;
	arr[1][1] = 1;
	for(int i=2;i<=N;i++){
		arr[i][0] = arr[i-1][1] + arr[i-1][0];
		arr[i][1] = arr[i-1][0];
	}
	long ans = arr[N][0] + arr[N][1];
	printf("%ld",ans);
	for(int i = 0; i<=N;i++){
		delete [] arr[i];
	}
	delete [] arr;
	return 0;
}

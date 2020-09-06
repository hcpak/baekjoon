// 내가 풀었던 문제가 아니다. 블로그를 참고해서 풀었다.
// 2020/5/21 다시 내가 직접 한번 풀어보았다. 이제는 쉽게 느껴진다.
#include <cstdio>
#include <algorithm>
#include <string.h>
#define MAX 100001
using namespace std;
int main(){
	int t, n;
	scanf("%d", &t);
	// 테스트 케이스 받기	
	for(int i=0;i<t;i++){
		//배열 선언하고 초기화
		scanf("%d", &n);
		int sticker[2][n+1];
		int dp[2][n+1];
		for(int j=0;j<2;j++){
			memset(sticker[j],0,sizeof(int)*(n+1));
			memset(dp[j],0,sizeof(int)*(n+1));
		}
		// input받기
		for(int j=0;j<2;j++){
			for(int k =1;k<=n;k++){
				scanf("%d",&sticker[j][k]);
			}
		}
		//dp 1번째일때 선언
		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		// dp 과정
		for(int j =2;j<=n;j++){
			dp[0][j] = max(dp[1][j-2],dp[1][j-1]) + sticker[0][j];
			dp[1][j] = max(dp[0][j-2],dp[0][j-1]) + sticker[1][j];
		}
		printf("%d\n",max(dp[0][n],dp[1][n]));
	}
	return 0;
}
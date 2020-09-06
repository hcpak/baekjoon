// 경우의 수 나열 해보고 별 지랄 다했는데 결국 다른 사람 풀이보고 깨달음을 얻음. 최대한 전의 경우의 수를 이용해 구하는 것으로 핀트를 맞춰야 보통 2차원 배열이니 2가지
// 케이스 나눠서 해보는 것이 효율적인듯.
#include <iostream>
#include <algorithm>
#define MAX 201
#define MOD 1000000000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N,K;
    cin >> N >> K;
    long dp[MAX][MAX] = {};
    for(int i =0; i<=N;i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i<=K; i++){
        dp[0][i] = 1;
    }
    for(int i = 1; i<= N;i++){
        for(int j = 1 ; j<= K;j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    cout << dp[N][K];
    return 0;
}
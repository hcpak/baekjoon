//이 문제는 못풀고 남의 풀이를 보고 이해함.
#include <iostream>
using namespace std;
#define MAX 31
int main() {
    int N;
    int dp[MAX] = { 1,0,3 };
    cin >> N;
    if (N % 2 == 0)
        for (int i = 4; i <= N; i+=2){
            dp[i]=dp[i-2]*3;
            for(int j=4;i-j>=0;j+=2)
                dp[i]+=dp[i-j]*2;
        }
    cout << dp[N];
    return 0;
}

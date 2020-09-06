#include <iostream>
#include <algorithm>
#define NUM 101
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    int BIG = 0;
    long long dp[NUM] ={0,1,1,1,2,2};
    int n;
    for(int i= 0; i<T;i++){
        cin >> n;
        if( i == 0){
            for(int j = 6; j<=n;j++){
                dp[j] = dp[j-1] + dp[j-5];
            }
        }
        else{
            if(BIG < n){
                for(int j = BIG; j<= n; j++){
                    dp[j] = dp[j-1] + dp[j-5];
                }
            }
        }
        BIG = max(BIG,n);
        cout << dp[n]<<endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <stdlib.h>
#define MAX 5001
#define MOD 1000000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    string num;
    cin >> num;
    long long dp[MAX]= {1,1,};
    int size = num.size();
    int n;
    for(int i = 2; i<=size; i++){
        char ch[2] = {num[i-2],num[i-1]};
        n = atoi(ch);
        if(n == 30 || n == 40 || n == 50 || n == 60 || n == 70 || n == 80 || n == 90){
            dp[size] = 0;
        }
        else if(n == 10 || n == 20){
            dp[i] = dp[i-2] % MOD;
        }
        else if(n<27 && n >10 && n != 20){
            dp[i] = (dp[i-1] +dp[i-2])%MOD;
        }else{
            dp[i] = dp[i-1]%MOD;
        }
    }
    if(num[0] == '0'){
        dp[size] = 0;
    }
    cout << dp[size];
    return 0;
}

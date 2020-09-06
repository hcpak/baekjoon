#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int a_size = a.size(), b_size = b.size();
    int dp[a_size+1][b_size+1];
    string str_dp[a_size+1][b_size+1];
    for(int i =0;i<=a_size;i++){
        memset(dp,0,sizeof(dp));
    }
    for(int i =0 ; i< a_size;i++){
        for(int j =0; j< b_size;j++){
            if(a[i] == b[j]){
                dp[i+1][j+1] = dp[i][j] +1;
                str_dp[i+1][j+1].replace(0,str_dp[i+1][i+1].size(), str_dp[i][j]);
                str_dp[i+1][j+1].push_back(b[j]);
            }else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                if(dp[i+1][j] > dp[i][j+1]){
                    str_dp[i+1][j+1].replace(0,str_dp[i+1][i+1].size(), str_dp[i+1][j]);
                }else{
                    str_dp[i+1][j+1].replace(0,str_dp[i+1][i+1].size(), str_dp[i][j+1]);
                }
            }
        }
    }
    cout << dp[a_size][b_size] <<"\n";
    if(str_dp[a_size][b_size].size() != 0){
        cout << str_dp[a_size][b_size];
    }
    return 0;
}
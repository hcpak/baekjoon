// 오랫동안 고민해서 문제를 풀어봤다. 한번에 맞아서 다행이다.
// 이제 좀 dp에 관한 명확한 개념이 잘 서는 거 같다.
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string a,b;
    cin >> a >> b;
    int a_size = a.size(), b_size = b.size();
    int dp[a_size+1][b_size+1];
    for(int i =0;i<=a_size;i++){
        memset(dp,0,sizeof(dp));
    }
    for(int i =0 ; i< a_size;i++){
        for(int j =0; j< b_size;j++){
            if(a[i] == b[j]){
                dp[i+1][j+1] = dp[i][j] +1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    cout << dp[a_size][b_size];
    return 0;
}
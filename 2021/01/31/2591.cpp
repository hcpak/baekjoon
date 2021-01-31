#include <cstdio>
#include <cstring>
using namespace std;
char input[41];
int dp[41][3] = {};
int main(){
    scanf("%s", input);
    int len = strlen(input);
    int prev = (input[0] - '0') * 10;
    dp[1][1] = 1;
    for(int i=2; i<= len; i++){
        int v = input[i-1] - '0';
        if(v == 0){
            if(prev + v <= 34){
                dp[i][2] = dp[i-1][1];
            }
            continue;
        }

        if( prev + v <= 34){
            dp[i][1] = dp[i-1][2] + dp[i-1][1];
            dp[i][2] = dp[i-1][1];
        }else{
            dp[i][1] = dp[i-1][1] + dp[i-1][2];
        }
        printf("%d %d\n",dp[i][1], dp[i][2]);
        prev = v * 10;
    }
    printf("%d\n",dp[len][1] + dp[len][2]);
    return 0;
}
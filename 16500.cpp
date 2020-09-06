// 총 5번 틀림. 맨처음에 dp인가 하다가, 반례 보고 dp로 바꿈.
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;
int main(){
    string ans;
    cin >> ans;
    int n;
    cin >> n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int ans_len = ans.length();
    int dp[ans_len+1];
    memset(dp,0,sizeof(dp));
    dp[0] =1;
    for(int i =1;i<=ans_len;i++){
        for(int j =0;j<n;j++){
            int arr_len = arr[j].length();
            if( i - arr_len>=0 && dp[i-arr_len] ==1){
                if(ans.compare(i-arr_len, arr_len,arr[j])==0){
                    dp[i] =1;
                }
            }
        }
    }
    if(dp[ans_len] == 1){
        printf("1");
    }else{
        printf("0");
    }
}
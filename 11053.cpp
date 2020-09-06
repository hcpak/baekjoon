#include <iostream>
#include <algorithm>
#define NUM 1001
using namespace std;
int main (){
	int N;
    cin >> N;
    int arr[NUM]={},dp[NUM]={};
    for(int i =1; i<=N;i++){
        cin >> arr[i];
    }
    int result = 0;
    for(int i = 1; i<=N;i++){
        for(int j = 0; j<=N;j++){
            if(arr[i]>arr[j])
                dp[i]= max(dp[i],dp[j]+1);
        }
        if(result < dp[i]){
            result = dp[i];
        }
    }
    cout << result;
	return 0;
}

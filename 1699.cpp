//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 시간 초과로 인해 검색해서 풀었다. 결국에는 굳이 계산이 필요하지 않는 데도 불구하고 풀었더니 시간초과가 나왔다. 
// #include <iostream>
// #define NUM 100001
// #define MAX 100000
// using namespace std;
// int main(){
//     ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	int n;
//     cin >> n;
//     long long count;
//     long long square = 1;
//     long long dp[NUM] ={};
//     for(int i = 1; i<=n;i++){
//         count = MAX;
//         if(square*square == i){
//             dp[i] = 1;
//             square++;
//         }else{
//             for(int j = 1; j<=(i/2); j++){
//                 long long buf = dp[i-j] +dp[j];
//                 if(count > buf)
//                     count = buf;
//             }  
//             dp[i] = count;
//         }
//     }
//     cout << dp[n];
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#define NUM 100001
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    int dp[NUM] ={};
    for(int i = 1; i<=n;i++){
        dp[i]=i;
       for(int j = 1; j*j<=i;j++){//시간 초과를 안시켜준 결정적인 이유.
           dp[i]= min(dp[i],dp[i-j*j]+1);
       }
    }
    cout << dp[n];
}
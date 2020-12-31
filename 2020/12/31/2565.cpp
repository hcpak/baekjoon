#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
int main(){
    int n;
    scanf("%d", &n);
    vector <vector <int> > line(n);
    int dp[n];
    for(int i = 0; i< n; i++){
        line[i] =vector<int>(2);
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    sort(line.begin(), line.end(), comp);

    int LIS = 0; 
    for( int i= 0; i <n;i++){
        dp[i] =1;
        for (int j= 0; j < i; j++){
            if(dp[j] + 1 > dp[i] && line[i][1] > line[j][1]) dp[i] =dp[i] +1;
        }
        LIS = max(LIS, dp[i]);
    }
    printf("%d\n", n - LIS);
    return 0;
}
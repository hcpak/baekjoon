#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <limits.h>
#define NUM 100000
// #define MAX 1000000000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    long N , M;
    cin >> N >> M;
    vector<long> arr(N);
    for(long i =0;i<N;i++){
        cin >> arr[i];
    }    
    long result = LONG_MAX, sum = 0, right = 0, left = 0;
    while(1){
        if(sum >= M){
            sum -= arr[left++];
            if(result > right-left){
                result = right-left +1;
            }
        } 
        else if(right == N) break;
        else sum += arr[right++];

    }
    if(result == LONG_MAX){
        cout << 0;
        return 0;
    }
    cout << result;
    return 0;
}
// 솔직히 내 코드가 뭐가 문제인지 잘 모르겠다. 
// 다시 한번 봐야할 코드.
#include <iostream>
#include <algorithm>
#include <cstdio>
#define NUM 100000
// #define MAX 1000000000
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    long N;
    long M;
    cin >> N;
    cin >> M;
    long arr[NUM];
    for(int i =0;i<N;i++){
        cin >> arr[i];
    }    
    long start = 0, end = 1000000000000000000LL,wanted=0,result =1000000000000000000LL;
    while(start <=end){
        long mid = (start + end)/2;
        wanted =0;
        for(long i=0;i<N;i++){
            wanted += (mid/arr[i]);
        }
        if(M > wanted)
            start = mid +1;
        else{
            end = mid -1;
        }
    }
    cout <<end+1;
    return 0;
}
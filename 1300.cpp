#include <iostream>
using namespace std;
long solve(long n, long k){
    long result =0;
    for(long i =1; i<=n;i++){
        if(i*n <= k)
            result += n;
        else
            result += k/i;
    }
    return result;
}
int main(){
    long N,k;
    cin >> N >> k;
    long start = 0, end = N*N;
    while(end - start >1){
        long mid = (start+end)/2;
        long num = solve(N,mid);
        if(k<= num){
            end = mid;
        }else{
            start = mid;
        }
    }
    cout << end;
    return 0;
}
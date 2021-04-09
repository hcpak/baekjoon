#include <cstdio>
using namespace std;
int main(){
    long long N,k;
    scanf("%lld %lld", &N, &k);
    long long start = 0, end = N*N+1;
    while(start+1 <end){
        long long mid = (start+end)/2;
        long long count =0;
        for(int i=1; i<=N;i++){
            if( mid/i >=N){
                count += N;
            }else{
                count += mid/i;
            }
        }
        if(count >= k){
            end = mid;
        }else{
            start = mid;
        }
    }
    printf("%lld\n",end);
    return 0;
}
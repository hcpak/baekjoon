#include <cstdio>
using namespace std;
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int wire[n];
    for(int i=0;i<n;i++){
        scanf("%d", &wire[i]);
    }
    long long start = 0, end = (long long)__INT_MAX__ +1;
    while(start + 1 != end){
        long long mid = (start +end) /2;
        int count =0;
        for(int i=0; i<n;i++){
            count += wire[i]/mid;
        }
        if( count >= k){
            start = mid;
        }else{
            end = mid;
        }
    }
    printf("%lld\n",start);
    return 0;
}
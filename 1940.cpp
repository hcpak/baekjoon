#include <cstdio>
int main(){
    int N,M;
    scanf("%d",&N);
    scanf("%d",&M);
    long long *arr = new long long[N];
    for(int i=0;i<N;i++){
        scanf("%lld",&arr[i]);
    }
    int count =0;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(arr[i] != 0 && arr[j] != 0){
                if( arr[i] != arr[j]){
                    if(arr[i] +arr[j] == M){
                        arr[i] =0;
                        arr[j] =0;
                        count++;
                    }
                }
            }
        }
    }
    printf("%d",count);
    return 0;
}
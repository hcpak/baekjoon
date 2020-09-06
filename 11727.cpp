#include <cstdio>
int main(){
    int N;
    scanf("%d", &N);
    long *arr = new long [N+1];
    arr[1] = 1;
    arr[2] = 3;
    for(int i =3 ;i <=N;i++){
        arr[i] = (arr[i-1] + 2*arr[i-2])%10007;
    }
    printf("%ld",arr[N]);
	delete [] arr;
    return 0;
}
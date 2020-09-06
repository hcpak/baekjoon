#include <cstdio>
using namespace std;
#define MAX 41
int fibonacci(int n, int * count);
int main(){
    int t,n;
    scanf("%d",&t);
    int fib_0[MAX] = {1,0}, fib_1[MAX]={0,1};
    for(int i=2;i<MAX;i++){
        fib_0[i] = fib_0[i-1] + fib_0[i-2];
        fib_1[i] = fib_1[i-1] + fib_1[i-2];
    }
    for(int i =0; i<t;i++){
        scanf("%d",&n);
        printf("%d %d\n",fib_0[n],fib_1[n]);
    }
    return 0;
}

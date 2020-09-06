#include <cstdio>
using namespace std;
int main(){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    long long temp = A * B * C;
    int ans[10] ={0,};
    while(temp != 0){
        ans[temp %10] += 1;
        temp /= 10;
    }
    for(int i=0;i<=9;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
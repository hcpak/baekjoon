#include <cstdio>
using namespace std;
int main(){
    int N,num,answer=0;
    scanf("%d", &N);
    for(int i =0;i<N;i++){
        scanf("%d", &num);
        bool flag = true;
        if(num <2)
            flag = false;
        for(int i = 2; i*i <= num;i++){
            if(num % i ==0 )  flag = false;
        }
        if(flag){
            answer++;
        }
    }
    printf("%d",answer);
    return 0;
}
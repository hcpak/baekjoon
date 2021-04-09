#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main(){
    char A[10001], B[10001],answer[10002]={};
    scanf("%s %s",A,B);
    int a_strlen = strlen(A), b_strlen = strlen(B),up=0;
    stack<int> s;
    while(a_strlen !=0 || b_strlen !=0){
        int a_num=0, b_num=0;
        if(a_strlen >0){
            a_strlen--;
            a_num = A[a_strlen] - '0';
        }
        if(b_strlen >0){
            b_strlen--;
            b_num = B[b_strlen] - '0';
        }
        int num = a_num + b_num + up;
        if(num >=10){
            up =1;
            s.push(num-10);
        }else{
            up =0;
            s.push(num);
        }
    }
    if(up == 1){
        s.push(up);
    }
    while(!s.empty()){
        printf("%d",s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}
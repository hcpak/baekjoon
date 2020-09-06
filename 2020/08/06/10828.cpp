#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main(){
    int n, x;
    char str[10];
    stack<int> s;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        if(strcmp(str, "push") == 0){
            scanf("%d\n", &x);
            s.push(x);
        }else if(strcmp(str, "top") == 0){
            if(!s.empty()){
                printf("%d\n",s.top());
            }else{
                printf("-1\n");
            }
        }else if(strcmp(str, "size") ==0){
            printf("%lu\n", s.size());
        }else if(strcmp(str, "pop") ==0){
            if(!s.empty()){
                printf("%d\n", s.top());
                s.pop();
            }else{
                printf("-1\n");
            }
        }else if(strcmp(str, "empty") ==0){
            if(!s.empty()){
                printf("0\n");
            }else{
                printf("1\n");
            }
        }
    }
    return 0;
}
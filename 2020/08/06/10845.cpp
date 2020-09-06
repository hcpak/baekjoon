#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main(){
    int n, x;
    char str[10];
    queue<int> q;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        if(strcmp(str, "push") == 0){
            scanf("%d\n", &x);
            q.push(x);
        }else if(strcmp(str, "front") == 0){
            if(!q.empty()){
                printf("%d\n",q.front());
            }else{
                printf("-1\n");
            }
        }else if(strcmp(str, "size") ==0){
            printf("%lu\n", q.size());
        }else if(strcmp(str, "pop") ==0){
            if(!q.empty()){
                printf("%d\n", q.front());
                q.pop();
            }else{
                printf("-1\n");
            }
        }else if(strcmp(str, "empty") ==0){
            if(!q.empty()){
                printf("0\n");
            }else{
                printf("1\n");
            }
        }else if(strcmp(str, "back") ==0){
            if(!q.empty()){
                printf("%d\n",q.back());
            }else{
                printf("-1\n");
            }
        }
    }
    return 0;
}
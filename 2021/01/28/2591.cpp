#include <cstdio>
#include <cstring>
using namespace std;
char input[40];
int answer =0;
int len;
void dfs(int i){
    if(i == len){
        answer++;
        return;
    }
    int first = input[i] -'0';
    if(first == 0){
        return;
    }
    dfs(i+1);
    if(i+1 <len){
        int second = input[i+1] -'0';
        if(first*10 + second <= 34){
            dfs(i+2);
        }
    }
}
int main(){
    scanf("%s",input);
    len = strlen(input);
    dfs(0);
    printf("%d\n",answer);
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> e0d0e2d0e4c6be496f1c5e2a385471ac260219d0

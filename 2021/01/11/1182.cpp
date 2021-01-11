#include <cstdio>
using namespace std;
int N, S, answer =0;
int arr[10000];
void dfs(int id, int sum){
    if( id  == N){
        if(sum == S)
            answer++;
    }else{
        dfs(id+1, sum +arr[id]);
        dfs(id+1, sum);
    }
}
int main(){
    scanf("%d %d", &N, &S);
    for(int i=0; i<N;i++){
        scanf("%d", &arr[i]);
    }
    dfs(0,0);
    if(S ==0){
        answer--;
    }
    printf("%d\n",answer);
    return 0;
}
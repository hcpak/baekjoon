#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
bool visited[9] = {false};
int N;
void dfs(int number){
    if(number == N){
        for(int i = 0; i < N; i++){
            printf("%d ",v[i]);
        }
        printf("\n");
    }else{
        for(int i = 1; i <= N;i++){
            if(!visited[i]){
                visited[i] = true;
                v.push_back(i);
                dfs(number+1);
                visited[i] = false;
                v.pop_back();
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    dfs(0);
    return 0;
}

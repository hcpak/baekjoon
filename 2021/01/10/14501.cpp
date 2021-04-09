#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> T,P;
int n, answer =0;
void dfs(int count, int sum){
    if(count == n){
        answer =max(answer,sum);
    }else if(count <n){
        for(int i =count; i<n;i++){
            if(i + T[i] > n){
                answer =max(answer,sum);
            }else{
                dfs(i + T[i], sum + P[i]);
            }
        }
    }
}
int main(){
    int t,p;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &t, &p);
        T.push_back(t);
        P.push_back(p);
    }
    dfs(0,0);
    printf("%d\n",answer);
    return 0;
}
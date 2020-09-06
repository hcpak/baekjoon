#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int dfs_result;
void dfs(vector<int> tree[], bool *visited,  int current, int parent){
    visited[current]= true;
    for(int i =0; i< tree[current].size();i++){
        int next = tree[current][i];
        if(visited[next] ==false){
            dfs(tree, visited, next, current);
        }else if(visited[next] && next != parent){
            dfs_result = 0;
        }
    }
}
int main(){
    int n, m,a,b, num=0;
    while(1){
        num++;
        int sum =0;
        scanf("%d %d", &n, &m);
        if(n == 0 && m ==0){
            break;
        }
        bool visited[n+1];
        vector<int> tree[n+1];
        for(int i =1; i<=n;i++){
            visited[i] = false;
        }
        for(int i = 0; i<m; i++){
            scanf("%d %d",&a, &b);
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        for(int i=1; i<=n;i++){
            if(!visited[i]){
                dfs_result = 1;
                dfs(tree, visited, i, -1);
                sum += dfs_result;
            }
        }
        if(sum ==0){
            printf("Case %d: No trees.\n",num);
        }else if(sum == 1){
            printf("Case %d: There is one tree.\n",num);
        }else{
            printf("Case %d: A forest of %d trees.\n",num,sum);
        }
    }
    return 0;
}
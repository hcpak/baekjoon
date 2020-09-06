#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
void dfs(vector<int> graph[], int start, int n);
void bfs(vector<int> graph[], int start, int n);
int main(){
    int n,m,v,a,b;
    scanf("%d %d %d",&n,&m,&v);
    vector<int> graph[n+1];
    for(int i =0;i<m;i++){
        scanf("%d %d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i =1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(graph,v,n);
    bfs(graph,v,n);
    return 0;
}
void dfs(vector<int> graph[], int start ,int n){
    stack<int> s;
    bool check[n+1];
    for(int i=0;i<n+1;i++){
        check[i] = false;
    }
    s.push(start);
    check[start] = true;
    printf("%d",start);
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i=0;i<graph[current_node].size();i++){
            int next_node = graph[current_node][i];
            if(check[next_node] == false){
                printf(" %d",next_node);
                check[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }
    printf("\n");
}
void bfs(vector<int> graph[], int start, int n){
    queue<int> q;
    bool check[n+1];
    for(int i=0;i<n+1;i++){
        check[i] = false;
    }
    q.push(start);
    check[start] = true;
    printf("%d",start);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i< graph[tmp].size();i++){
            if(check[graph[tmp][i]] == false){
                printf(" %d",graph[tmp][i]);
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}
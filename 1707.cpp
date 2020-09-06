#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
void bfs(int start, vector<int> graph[], bool check[],int color[]){
    queue<int> q;
    q.push(start);
    check[start] = true;
    color[start] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0;i<graph[tmp].size();i++){
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                color[graph[tmp][i]] = 1-color[tmp];
                check[graph[tmp][i]] = true;
            }
        }
    }
}
bool bipartite(vector<int> graph[], int color[],int v){
    for(int i = 1; i<=v;i++){
        for(int j =0; j < graph[i].size();j++){
            int next = graph[i][j];
            if(color[i] == color[next])
                return false;
        }
    }
    return true;
}
int main(){
    int k, v, e, a,b;
    cin >> k;
    vector<int> graph[20001];
    bool visited[20001];
    int color[20001];
    for(int i =1;i<=k;i++){
        cin >> v >> e;
        for(int j=1;j<=v;j++){
            graph[j].clear();
            visited[j] = false;
            color[j] = -1;
        }
        for(int j = 1;j<=e;j++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int j = 1; j<=v;j++){
            if(visited[j] == false)
                bfs(j,graph,visited,color);
        }
        for(int j=1;j<=v;j++){
            visited[j] = false;
        }
        bool flag = bipartite(graph,color,v);
        if(i != 1){
            cout <<"\n";
        }
        if(flag){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }
    return 0;
}
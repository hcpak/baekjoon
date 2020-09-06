#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void dfs(int start, vector<int> graph[], bool check[]){
    check[start]= true;
    int size = graph[start].size();
    for(int i=0;i < size;i++){
        int next = graph[start][i];
        if(check[next]==false){
            dfs(next,graph,check);
        }
    }
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> graph[N+1];
    bool check[N+1];
    fill(check, check+N+1,false);
    int a,b;
    for(int i = 1; i<=M; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i =1; i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    int connected_component = 0;
    for(int start = 1; start<=N; start++){ 
        if(check[start] == false){
            dfs(start, graph,check);
            connected_component++;
        }
    }
    cout << connected_component;
    return 0;
}
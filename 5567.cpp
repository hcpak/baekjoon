#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void dfs(int start, vector<int> graph[], bool check[],int count, set<int> *visited){
    if(start != 1){
        (*visited).insert(start);
    }
    if(count ==2){
        return;
    }
    check[start] = true;
    count++;
    int size = graph[start].size();
    for(int i=0;i < size;i++){
        int next = graph[start][i];
        if(check[next]==false){
            dfs(next, graph, check, count,visited);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> graph[n+1];
    bool check[n+1];
    fill(check, check+n+1,false);
    int a,b;
    for(int i = 0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i =1; i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    int start =1,count =0,answer = 0;
    set<int> visited;
    dfs(start,graph,check,count,&visited);
    set<int>::iterator iter;
    for(iter = visited.begin(); iter != visited.end();iter++){
        answer++;
    }
    cout << answer;
    return 0;
}
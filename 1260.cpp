#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#define MAX 1001
using namespace std;
void dfs(int start, vector<int> graph[], bool check[]){
    stack<int> s;
    s.push(start);
    check[start] = true;
    cout << start ;
    bool flag = false;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i=0;i<graph[current_node].size();i++){
            int next_node = graph[current_node][i];
            if(check[next_node] == false){
                cout <<" "<<next_node;
                check[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }
}
void bfs(int start, vector<int> graph[], bool check[]){
    queue<int> q;
    q.push(start);
    check[start] = true;
    bool flag = false;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(flag){
            cout << " ";
        }else{
            flag =true;
        }
        cout <<tmp;
        for(int i = 0; i< graph[tmp].size();i++){
            if(check[graph[tmp][i]] == false){
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
    }
}
int main(){
    int N, M, V;
    cin >> N >> M >> V;
    int A,B;
    vector<int> graph[MAX];
    bool check[MAX];
    fill(check, check+N+1,false);
    for(int i=0;i<M;i++){
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    for(int i=1;i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(V, graph,check);
    fill(check, check+N+1,false);
    cout <<endl;
    bfs(V, graph,check);
    return 0;
}
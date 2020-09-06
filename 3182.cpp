#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
void dfs(int start, int* count, vector<int> graph[], bool check[]){
    if(count != 0){
        check[start] = true;
    }

    // cout <<"start: "<<start <<" check: " << check[start]<<endl;
    *count = *count + 1;
    int size = graph[start].size();
    for(int i=0;i < size;i++){
        int next = graph[start][i];
        if(check[next]==false){
            dfs(next, count, graph,check);
        }
    }
}
int main(){
    int N,answer =1;
    cin >> N;
    vector<int> graph[N+1];
    bool check[N+1];
    int count[N+1];
    fill(count, count+N+1,0);
    fill(check, check+N+1,false);
    int input;
    for(int i = 1;i<N+1;i++){
        cin >> input;
        graph[i].push_back(input);
    }
    for(int i =1; i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    for(int start = 1; start<=N; start++){ 
        dfs(start,&count[start], graph,check);
        fill(check, check+N+1,false);
    }
    int max_count =0;
    for(int i = 1; i<= N; i++){
        // cout <<"count :" << count[i] <<endl;
        if(count[i] > max_count){
            max_count = count[i];
            answer = i;
        }
    }
    cout << answer;
    return 0;
}
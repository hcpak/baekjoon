#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void dfs(int start, int end, int count, bool* find, vector<int> graph[], bool check[]){
    // cout <<"find: "<<*find <<" start: " <<start <<" end: " <<end<<" count: " << count <<endl;
    if(*find == true){
        return;
    }
    if(start == end && count >0){
        *find = true;
        return;
    }
    if(count != 0){
        check[start] = true;
    }
    count++;
    int size = graph[start].size();
    for(int i=0;i < size;i++){
        int next = graph[start][i];
        if(check[next]==false){
            dfs(next,end, count, find, graph,check);
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<int> graph[N+1];
    bool check[N+1];
    fill(check, check+N+1,false);
    int input;
    for(int i = 1;i<N+1;i++){
        for(int j =1 ; j<N+1;j++){
            cin >> input;
            if(input==1){
                graph[i].push_back(j);
            }
        }
    }
    for(int i =1; i<=N;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    int count = 0;
    bool find = false;
    for(int start = 1; start<=N; start++){ 
        for(int end = 1; end <= N; end++){
            fill(check, check+N+1,false);
            find = false;
            dfs(start,end, 0, &find, graph,check);
            if(find == false){
                if(end == N)
                    cout << "0";
                else
                    cout << "0 ";
            }else{
                if(end == N){
                    cout << "1";
                }
                else
                    cout << "1 ";
            }
        }
        if(start != N)
            cout << endl;
    }
    return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
int dfs(vector<pair<int ,int>> graph[], bool check[], int start, int weight);
int main(){
    int n, parent, child, weight;
    scanf("%d", &n);
    vector<pair<int,int>> tree[n+1];
    for(int i =1 ; i < n; i++){
        scanf(" %d %d %d", &parent, &child, &weight);
        tree[parent].push_back(make_pair(child,weight));
        tree[child].push_back(make_pair(parent, weight));
    }
    priority_queue< int, vector<int>, less<> > di[n+1];
    int max_di =0;
    priority_queue< int, vector<int>, less<> > max_q; 
    for(int i = 1; i <= n; i++){
        if(tree[i].size() >= 2){
            for(unsigned int j = 0; j < tree[i].size(); j++){
                bool check[1000001] = {};
                check[i]= true;
                int value = dfs(tree, check, tree[i][j].first, tree[i][j].second);
                di[i].push(value);
            }
            int max_half_di = di[i].top();
            max_q.push(max_half_di);
            di[i].pop();
            int second_max_half_di = di[i].top();
            max_q.push(max_half_di+second_max_half_di);
        }
    }
    max_q.pop();
    printf("%d", max_q.top());
    return 0;
}

int dfs(vector<pair<int ,int>> graph[], bool check[], int start, int weight){
    check[start] = true;
    int max_weight = weight;
    for(unsigned int i =0; i< graph[start].size();i++){
        int next = graph[start][i].first;
        int next_weight = weight + graph[start][i].second;
        if(check[next]== false){
            max_weight = max(max_weight, dfs(graph, check, next, next_weight));
        }
    }
    return max_weight;
}
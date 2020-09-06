//질문에 있는 한 점에서 가장 먼 곳을 간다는 것을 착안해서 풀었다.
//맨 처음에 너무 어려워서 알고리즘 분류에서 bfs를 봤는데, 내가 생각한 방법으로는 bfs가 절대 안되서
//dfs로 풀었다. 그런데 정답... bfs로 푸는 다른 방법도 알아야할 거 같다.
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
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
    vector<int> di[n+1];
    bool check[n+1];
    int max_di =0;
    for(int i = 1; i <= n; i++){
        if(tree[i].size() >= 2){
            for(unsigned int j = 0; j < tree[i].size(); j++){
                for(int i=1; i<=n;i++)check[i] =false;
                check[i]= true;
                int value = dfs(tree, check, tree[i][j].first, tree[i][j].second);
                di[i].push_back(value);
            }
            sort(di[i].begin(), di[i].end(), greater<int>());
            max_di = max(max_di, di[i][0] + di[i][1]);
        }
    }
    printf("%d", max_di);
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
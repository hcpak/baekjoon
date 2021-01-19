#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define NUM_MAX 1000000001
#define NODE_MAX 100001
using namespace std;
int N,M,s,e;
vector<pair<int,int> >graph[NODE_MAX];
bool visited[NODE_MAX];
bool bfs(int cost){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == e){
            return true;
        }
        for(int i=0; i <graph[cur].size(); i++){
            int next = graph[cur][i].first;
            int nextCost = graph[cur][i].second;
            if(!visited[next] && cost <= nextCost){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}
int main(){
    scanf("%d %d", &N, &M);
    int a,b,c;
    for(int i=0; i< M;i++){
        scanf("%d %d %d",&a,&b,&c);
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&s, &e);
    int start = 0, end = NUM_MAX;
    while(start +1 <end){
        int mid = (start+end)/2;
        memset(visited, 0, sizeof(visited));
        if(bfs(mid)){
            start = mid;
        }else{
            end = mid;
        }
    }
    printf("%d\n",start);
    return 0;
}

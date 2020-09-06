// network flow 코드 구현이 생각보다 힘들다. 내가 한번 짜봐야할 듯.
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#define MAX 802
using namespace std;
int c[MAX][MAX];
int flowPassed[MAX][MAX];
vector<int> g[MAX];
int parList[MAX];
int currentPathC[MAX];
bool visited[MAX];
int n,m;
int bfs(int sNode, int eNode){
    memset(parList, -1, sizeof(parList));
    memset(currentPathC, 0 , sizeof(currentPathC));
    queue<int> q;
    q.push(sNode);
    currentPathC[sNode] = 999;
    while(!q.empty()){
        int currNode = q.front();
        q.pop();
        for(int i =0; i<g[currNode].size();i++){
            int to = g[currNode][i];
            if(parList[to] == -1){
                if(c[currNode][to] - flowPassed[currNode][to] > 0){
                    parList[to] = currNode;
                    currentPathC[to] = min(currentPathC[currNode], c[currNode][to] - flowPassed[currNode][to]);
                    if(to == eNode){
                        return currentPathC[eNode];
                    }
                    q.push(to);
                }
            }
        }
    }
    return 0;
}
int edmondsKarp(int sNode, int eNode){
    int maxflow = 0;
    while(true){
        int flow = bfs(sNode, eNode);
        if(flow == 0){
            break;
        }
        maxflow += flow;
        int currNode = eNode;
        while(currNode != sNode){
            int prevNode = parList[currNode];
            // cout << prevNode << " ";
            flowPassed[prevNode][currNode] += flow;
            flowPassed[currNode][prevNode] -= flow;
            currNode = prevNode;
        }
        // cout << endl;
    }
    return maxflow;
}
int main(){
    cin >> n >> m;
    for(int i =1; i <= n; i++){
        c[2*i-1][2*i] =1;
        c[2*i][2*i-1] =1;
        g[2*i-1].push_back(2*i);
        g[2*i].push_back(2*i-1);
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >>a >> b;
        c[2*b-1][2*a] = 1;
        c[2*a-1][2*b] = 1;
        g[2*a-1].push_back(2*b);
        // g[2*b].push_back(2*a-1);
        g[2*b-1].push_back(2*a);  
        g[2*a].push_back(2*b-1);
    }
    cout << edmondsKarp(1,4);
    return 0;
}
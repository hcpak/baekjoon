#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#define MAX 402
using namespace std;
int c[MAX][MAX];
int flowPassed[MAX][MAX];
vector<int> g[MAX];
int parList[MAX];
int currentPathC[MAX];
int bfs(int sNode, int eNode){
    memset(parList, -1, sizeof(parList));
    memset(currentPathC, 0 , sizeof(currentPathC));
    queue<int> q;
    q.push(sNode);
    parList[sNode] = -1;
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
            flowPassed[prevNode][currNode] += flow;
            flowPassed[currNode][prevNode] -= flow;
            currNode = prevNode;
        }
    }
    return maxflow;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k;
        cin >>k;
        c[0][i] = 1;
        g[0].push_back(i);
        g[i].push_back(0);
        for(int j=1;j<=k;j++){
            int to;
            cin >> to;
            to += 200;
            c[i][to] = 1;
            // c[to][i] = 1;
            g[i].push_back(to);
            g[to].push_back(i);
        }
    }
    for(int i = 1; i <= m;i++){
        int tmp = 200+i;
        int sink = 401;
        c[tmp][sink] = 1;
        g[tmp].push_back(sink);
        g[sink].push_back(tmp);
    }
    int maxFlow = edmondsKarp(0,401);
    cout << maxFlow;
    return 0;
}
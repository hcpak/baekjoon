#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int bfs(int start,int end){
    queue<pair<int, int> > q;
    bool visited[MAX] = {false};
    q.push(make_pair(start, 0));
    visited[start] = true;
    while(!q.empty()){
        int n = q.front().first;
        int s = q.front().second;
        if(n == end){
            return s;
        }
        q.pop();
        if(visited[2*n] == false &&2*n >=0 &&2*n < MAX){
            visited[2*n] = true;
            q.push(make_pair(2*n,s+1));
        }
        if(visited[n+1] ==false && n+1 >=0 && n+1 < MAX){
            visited[n+1] = true;
            q.push(make_pair(n+1,s+1));
        }
        if(visited[n-1] == false && n-1 >= 0 &&n-1 < MAX){
            visited[n-1] =true;
            q.push(make_pair(n-1,s+1));
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    cout <<bfs(n,k);
    return 0;
}
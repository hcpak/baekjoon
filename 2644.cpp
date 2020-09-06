#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void bfs(int start,int end, int* count,bool* flag, vector<int> graph[], bool check[]){
	queue<int> q;
	q.push(start);
	check[start] = true;
	while(!q.empty()){
        int size = q.size();
        *count = *count+1;
        while(size--){
            int tmp = q.front();
            q.pop();
            for(int i=0; i<graph[tmp].size(); i++){

                // 방문하지 않았다면
                if(check[graph[tmp][i]] == false){
                    // 큐에 넣어주고 방문했음을 표시한다.
                    if(graph[tmp][i] == end){
                        *flag =true;
                        return;
                    }
                    q.push(graph[tmp][i]);
                    check[graph[tmp][i]] = true;
                }
            }
        }
	}

}
int main(){
    int n,a,b,m,x,y;
    cin >> n;
    cin >> a >> b;
    cin >> m;
    vector<int> family[n+1];
    bool check[n+1];
    fill(check,check+n+1,false);
    for(int i =0; i< m;i++){
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }
    int count =0;
    bool flag = false;
    bfs(a,b,&count, &flag,family,check);
    if(flag == false){
        cout << -1;
        return 0;
    }
    cout<<count;
    return 0;
}
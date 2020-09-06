#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void dfs(int start,vector<int> graph[], bool check[], int* count){
    stack<int> s;
    s.push(start);
    check[start]= true;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i =0;i<graph[current_node].size();i++){
            int next_node = graph[current_node][i];
            if(check[next_node] ==false){
                *count = *count +1;
                check[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                break;
            }
        }
    }
}
int main(){
    int n,m,x,a,b;
    cin >> n >> m >> x;
    vector<int> d_g[n+1],u_g[n+1];
    for(int i = 0 ; i<m;i++){
        cin >> a >> b;
        d_g[a].push_back(b);
        u_g[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
		sort(d_g[i].begin(), d_g[i].end());
        sort(u_g[i].begin(), u_g[i].end());
	}
    bool check[n+1];
    int d_c =0,u_c=0;
    fill(check,check+n+1,false);
    dfs(x,d_g,check,&d_c);
    fill(check,check+n+1,false);
    dfs(x,u_g,check,&u_c);
    cout << 1+u_c <<" " << n-d_c;
    return 0;
}
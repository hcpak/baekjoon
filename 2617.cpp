#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
int dfs(int start, vector<int> v[],bool check[]){
    stack<int> s;
    s.push(start);
    memset(check,false,100);
    check[start] = true;
    int count =0;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i=0; i< v[current_node].size();i++){
            int next_node = v[current_node][i];
            if(check[next_node]== false){
                check[next_node] = true;
                s.push(current_node);
                s.push(next_node);
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector <int> um[100],dm[100];
    bool check[100];
    int n, m;
    cin >> n >> m;
    int a,b,max,min, mid = (n+1)/2;
    for(int i = 0 ; i < m;i++){
        cin >> a >> b;
        um[a].push_back(b);
        dm[b].push_back(a);
    }
    int ans =0;
    for(int i=1;i<=n;i++){
        min = n- dfs(i, um,check);
        max = 1+ dfs(i, dm, check);
        // cout << i <<"번째 max: " << max << " min: " << min << endl;
        if(min < mid || max > mid){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
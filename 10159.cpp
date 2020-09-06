#include <iostream>
#include  <vector>
#include <stack>
#include <string.h>
using namespace std;
const int MAX = 101;
vector<int> dv[MAX], uv[MAX];
bool check[MAX];
int dfs(vector<int> v[], int start){
    stack<int> s;
    s.push(start);
    check[start] = true;
    int count = 0;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        for(int i = 0 ; i<v[current_node].size();i++){
            int next_node = v[current_node][i];
            if(!check[next_node]){
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
    int n,m, a,b;
    cin >> n >> m;
    for(int i = 0 ; i < m;i++){
        cin >> a >> b;
        dv[a].push_back(b);
        uv[b].push_back(a);
    }
    for(int i =1;i <=n;i++){
        if(i!= 1){
            cout << "\n";
        }
        int dn = dfs(dv,i), un = dfs(uv,i);
        // cout << i << "번째: dn: " <<dn << " un: " << un;
        cout << n- 1 -dn - un;
        memset(check,false,sizeof(check));
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#define MAX 100001
using namespace std;
int student[MAX];
bool check[MAX]= {false,};
int dfs(int start){
    stack<int> s;
    check[start] = true;
    s.push(start);
    vector<int> v;
    v.push_back(start);
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        int next_node = student[current_node];
        if(!check[next_node]){
            check[next_node] = true;
            s.push(next_node);
            v.push_back(next_node);
        }else{
            // 이 for문을 매번 비교했으니 시간초과 나는 수 밖에...
            // else에다가 비교해서 시간초과를 면함. 히히
            for(int i=0;i<v.size();i++){
                if(v[i] == next_node){
                    return i;
                }
            }
        }
    }
    return v.size();
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n,ans;
    cin >> t;
    for(int i=0;i<t ;i++){
        if(i != 0)
            cout <<"\n";
        cin >> n;
        ans = 0;
        for(int j =1;j<=n;j++){
            cin >> student[j];
            check[j] = false;
        }
        for(int j =1; j<=n;j++){
            if(!check[j]){
                int num =dfs(j);
                // cout << "num: " << num << "\n";
                // cout << j << "번째: " << num <<"\n"; 
                ans += num;
            }
        }
        cout << ans;
    }
    return 0;
}
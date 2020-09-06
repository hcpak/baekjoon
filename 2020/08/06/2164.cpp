#include <cstdio>
#include <queue>
using namespace std;
int main(){
    queue<int> q;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        q.push(i);
    }
    while(1){
        if(q.size() == 1){
            break;
        }
        q.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }
    printf("%d",q.front());
    return 0;
}
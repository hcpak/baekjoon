#include <queue>
#include <stack>
#include <cstdio>
using namespace std;
int main(){
    priority_queue <int> q;
    int n,x;
    scanf("%d",&n);
    for(int i =0; i< n;i++){
        scanf("%d", &x);
        if(x == 0){
            if(!q.empty()){
                printf("%d\n",q.top());
                q.pop();
            }else{
                printf("0\n");
            }
        }else{
            q.push(x);
        }
    }
    return 0;
}
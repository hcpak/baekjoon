#include <cstdio>
#include <stack>
using namespace std;
int main(){
    long long n,x;
    scanf("%llu",&n);
    stack<pair<long long, long long>> s;
    for (long long i =1; i<=n; i++){
        scanf("%llu",&x);
        if(s.empty()){
            printf("0\n");
        }else{
            while(!s.empty()){
                if(s.top().first < x)
                    s.pop();
                else{
                    break;
                }
            }
            if(!s.empty()){
                printf("%llu\n",s.top().second);
            }else{
                printf("0\n");
            }
        }
        s.push(make_pair(x, i));
    }
    return 0;
}
#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int n;
    char str[51];
    scanf("%d",&n);
    for(int i =0; i < n; i++){
        stack<int> s;
        bool flag = true;
        scanf("%s", str);
        for(int i =0; i<strlen(str); i++){
            if(str[i] == '('){
                s.push(0);
            }else{
                if(!s.empty()){
                    s.pop();
                }else{
                    flag= false;
                    break;
                }
            }
        }
        if(s.size()){
            flag = false;
        }
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
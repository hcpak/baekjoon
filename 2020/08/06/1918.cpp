// 컴파설 내용 나올때마다 떨리는 이유는 뭘까? 어쨌든 이 문제도 내가 풀려고 했지만
// 블로그에 있는 단서 하나보고 다시 풀었더니 맞았다.
// 우선순위를 둬야하나 이 생각 많이 했는데 그렇게 안해도 되더라.
// 문제를 볼떄 어떤 자료형으로 풀어야 하는지 고민 많이 해야겠더라.
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main(){
    char str[101];
    scanf("%s", str);
    stack<char> ex_s;
    for(int i = 0; i<strlen(str); i++){
        switch(str[i]){
            case '+': case '-':
                while(!ex_s.empty() && ex_s.top() != '('){
                    printf("%c", ex_s.top());
                    ex_s.pop();
                }
                ex_s.push(str[i]);
                break;
            case '*': case '/':
                while(!ex_s.empty() && (ex_s.top() != '(' && ex_s.top() != '+' && ex_s.top() != '-')){
                    printf("%c", ex_s.top());
                    ex_s.pop();
                }
                ex_s.push(str[i]);
                break;
            case '(':
                ex_s.push(str[i]);
                break;
            case ')':
                while(!ex_s.empty() && ex_s.top() != '('){
                    printf("%c", ex_s.top());
                    ex_s.pop();
                }
                ex_s.pop();
                break;
            default:
                printf("%c",str[i]);
                break;
        }
    }
    while(!ex_s.empty()){
        printf("%c", ex_s.top());
        ex_s.pop();
    }
    return 0;
}
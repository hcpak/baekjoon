#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> number, operators;
int result = -pow(2,31);
int switch_operators(int op1, int op2, int oper){
    switch(oper){
        case 0:
            return op1 + op2;
        case 1:
            return op1 - op2;
        case 2:
            return op1 * op2;
    }
}
void dfs(int sum, int i){
    if(i ==number.size() -1){
        result = max(result, sum);
        return;
    }
    int next_sum = switch_operators(sum, number[i+1], operators[i]);
    dfs(next_sum, i+1);
    if(i+2 < number.size()){
        int bracket = switch_operators(number[i+1], number[i+2], operators[i+1]);
        next_sum = switch_operators(sum, bracket, operators[i]);
        dfs(next_sum, i+2);
    }
}
int main(){
    int N;
    scanf("%d", &N);
    char ch;
    for(int i=0; i<N;i++){
        scanf(" %c", &ch);
        if(i % 2 ==0){
            number.push_back(ch -'0');
        }else{
            switch (ch)
            {
            case '+':
                operators.push_back(0);
                break;
            case '-':
                operators.push_back(1);
                break;
            case '*':
                operators.push_back(2);
                break;
            }
        }
    }
    dfs(number[0],0);
    printf("%d\n",result);
    return 0;
}
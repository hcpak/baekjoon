#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
    int N,num =0, number;
    int * stack;
    string a;
    cin >> N;
    stack = new int[N];
    for(int i = 0;i < N;i++){
        cin >> a;
        
        if(a.compare("push") == 0){
            cin >> number;
            stack[num++] = number;
        }
        else{
            if(a.compare("pop") == 0){
                if(num !=0){
                    int i = stack[--num];
                    stack[num] = 0;
                    cout << i;
                }else{
                    printf("-1");
                }
            }else if(a.compare("size") == 0){
                cout << num;
            }else if(a.compare("empty") ==0){
                if(num == 0){
                    printf("1");
                }else{
                    printf("0");
                }
            }else if(a.compare("top") ==0){
                if(stack[num-1] ==0){
                    printf("-1");
                }else{
                    cout << stack[num-1];
                }
            }
            printf("\n");
        }
    }
    return 0;
}
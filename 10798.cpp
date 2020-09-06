#include <iostream>
#include <string>
#define NUM 5
using namespace std;
int main(){
    string st[NUM];
    int size[NUM];
    for(int i = 0; i< NUM;i++){
        cin >> st[i];
        size[i] =st[i].length();
    }
    for(int i = 0; i< 15;i++){
        for(int j =0; j<5;j++){
            if(size[j]>i){
                cout << st[j][i];
            }
        }
    }
    return 0;
}
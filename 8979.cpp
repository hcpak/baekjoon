#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
#define SLIVER  1000000
#define GOLD    1000000000000
int main(){
    int N, K;
    long long c[MAX];
    cin >> N >> K;
    int id,g,s,b;
    for(int i = 0; i< N;i++){
        cin>>id >> g >> s >> b;
        c[id] = g*GOLD + s * SLIVER + b;
    }
    int count =1;
    for(int i=1;i<=N;i++){
        if(c[K] < c[i]){
            count++;
        }
    }
    cout <<count;
    return 0;
}
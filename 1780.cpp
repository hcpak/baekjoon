#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    int cell[N+1][N+1];
    for(int i =1; i<=N;i++){
        for(int j =1; j<=N;j++){
            cin >> cell[i][j];
        }
    }
    
    return 0;
}
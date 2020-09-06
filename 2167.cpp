#include <iostream>
#define MAX 301
using namespace std;
int arr[MAX][MAX] ={};
int main(){
    int N, M;
    cin >> N >>M;
    for(int i = 1; i<=N;i++){
        for(int j =1; j<=M;j++){
            cin >> arr[i][j];
        }
    }
    int K;
    cin >> K;
    int i,j,x,y;
    int ans = 0;
    for(int a = 0; a<K;a++){
        ans =0;
        cin >> i >> j >> x >> y;
        for(int b =i; b<=x;b++){
            for(int c = j; c<=y;c++){
                ans += arr[b][c];
            }
        }
        cout << ans<<endl;
    }
    return 0;
}
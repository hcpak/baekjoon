#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5001
int main(){
    int N;
    cin >> N;
    int arr[MAX];
    for(int i = 1;i<=MAX;i++){
        arr[i] = MAX;
    }
    arr[1] = -1;
    arr[2] = -1;
    arr[3] = 1;
    arr[4] = -1;
    arr[5] = 1;
    for(int i = 6; i<= N; i++){
        for(int j = 1; j<i;j++){
            if(arr[i-j] != -1 && arr[j] != -1){
                if(arr[i] > arr[i-j]+arr[j]){
                    arr[i] = arr[i-j] + arr[j];
                }
            }
        }
        if(arr[i] == MAX)
            arr[i] = -1;
    }
    cout << arr[N];
    return 0;
}
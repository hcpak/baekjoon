#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int main(){
    int N, temp;
    scanf("%d", &N);
    vector<int> arr;
    for(int i=0; i<N;i++){
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    if(N==1){
        printf("-1\n");
        return 0;
    }
    int swap = 1;
    for(int i= N-1; i>0; i--){
        if(arr[i-1] > arr[i]){
            swap = i-1;
            break;
        }
        if( i == 1){
            printf("-1\n");
            return 0;
        }
    }
    for(int i = N-1; i> swap; i--){
        if(arr[swap] > arr[i]){
            int iter = arr[swap];
            arr[swap] = arr[i];
            arr[i] = iter;
            break;
        }
    }
    sort(arr.begin()+swap+1, arr.end(), greater<int>());
    for(int i=0; i<N;i++){
        printf("%d",arr[i]);
        if(i != N-1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
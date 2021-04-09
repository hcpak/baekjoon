#include <cstdio>
#include <algorithm>
#define MAX_NUM 1000001
using namespace std;
int arr[MAX_NUM];
int main(void){
    int n;
    scanf("%d",&n);
    
    int temp, len =0;
    for(int i =0; i<n;i++){
        scanf("%d", &temp);
        if(len == 0){
            arr[len++] = temp;
        }
        else{
            if(arr[len-1] < temp) arr[len++] = temp;
            else{
                arr[lower_bound(arr,arr+len,temp) - arr] = temp;
            }
<<<<<<< HEAD
=======

>>>>>>> e0d0e2d0e4c6be496f1c5e2a385471ac260219d0
        }
    }
    printf("%d\n",len);
    return 0;
}
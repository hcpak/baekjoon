#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int height[1000001];
    for(int i =0; i< N;i++){
        scanf("%d",&height[i]);
    }
    int start = 0, end = 1000000000;
    while(start+1 < end){
        int mid =(start+end)/2;
        long long left =0;
        for(int i= 0; i< N; i++){
            if(height[i] -mid >0){
                left += height[i] -mid;
            }
        }
        if(left >= M){
            start =mid;
        }else{
            end = mid;
        }
    }
    printf("%d\n",start);
    return 0;
}
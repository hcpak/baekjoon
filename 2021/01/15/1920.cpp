#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, M;
    int A[100001];
    scanf("%d", &N);
    for(int i =0 ; i< N; i++){
        scanf("%d", &A[i]);
    }
    sort(A, A +N );
    scanf("%d", &M);
    int temp;
    for(int i =0; i < M; i++){
        scanf("%d", &temp);
        int start = -1, end =N;
        while(start +1 < end){
            int mid= (start +end) /2;
            if(A[mid] < temp){
                start = mid;
            }else{
                end = mid;
            }
        }
        if(A[end] == temp){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }

    return 0;
}
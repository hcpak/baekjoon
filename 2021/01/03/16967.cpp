#include <cstdio>
using namespace std;
int main(){
    int h,w,x,y;
    scanf("%d %d %d %d",&h,&w,&x,&y);
    int A[h][w], temp;
    for(int i =0; i<h+x;i++){
        for(int j =0; j<w+y;j++){
            scanf("%d", &temp);
            if(i<x &&  0<=j && j <w){
                A[i][j] = temp;
            }else if(j <y && 0<= i && i <h){
                A[i][j] = temp;
            }else if( x<=i && i<h && y<=j && j <w){
                A[i][j] = temp - A[i-x][j-y];
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j =0; j<w;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
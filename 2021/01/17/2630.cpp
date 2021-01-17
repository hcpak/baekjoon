#include <cstdio>
using namespace std;
int white_num=0, blue_num=0;
int Map[128][128];
void dfs(int y, int x, int n){
    bool white_flag = true, blue_flag = true;
    for(int h = y; h<y+n; h++){
        for(int w = x; w<x+n; w++){
            if(Map[h][w] == false){// white
                blue_flag = false;
            }else{
                white_flag = false;
            }
        }
    }
    if(!blue_flag && !white_flag){
        dfs(y,x,n/2);
        dfs(y,x+n/2,n/2);
        dfs(y+n/2,x,n/2);
        dfs(y+n/2,x+n/2,n/2);
    }else{
        if(blue_flag){
            blue_num++;
        }else{
            white_num++;
        }
    }
}
int main(){
    int N;
    scanf("%d", &N);
    for(int h = 0; h < N; h++){
        for(int w = 0; w < N; w++){
            scanf("%d", &Map[h][w]);
        }
    }
    dfs(0,0,N);
    printf("%d\n%d\n",white_num,blue_num);
    return 0;
}
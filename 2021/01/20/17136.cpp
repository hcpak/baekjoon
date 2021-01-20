#include <cstdio>
#include <algorithm>
#define MAX 10
using namespace std;
int Map[MAX][MAX];
int paper_cnt[6] = {0,5,5,5,5,5};
int result = 26, cnt;
void dfs(int h, int w){
    if( w == MAX){
        dfs(h +1, 0);
        return;
    }
    if( h == MAX){
        result = min(result, cnt);
        return;
    }

    if(Map[h][w] ==0){
        dfs(h,w+1);
        return;
    }

    for(int size =5; size>=1; size--){
        if(paper_cnt[size] ==0 || h + size > MAX || w + size > MAX){
            continue;
        }

        bool flag = true;
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                if(Map[h +j][w+k] ==0){
                    flag = false;
                    break;
                }
            }
            if( flag == false){
                break;
            }
        }
        if(flag == false){
            continue;
        }

        for(int j =0; j <size; j++){
            for(int k =0; k <size; k++){
                Map[h +j][w+ k] =0;
            }
        }

        paper_cnt[size]--;
        cnt++;

        dfs(h, w + size);

        for(int j = 0 ; j < size; j++){
            for(int k=0; k < size; k++){
                Map[h+j][w+k] =1;
            }
        }
        paper_cnt[size]++;
        cnt--;
    }
}
int main(){
    for(int height=0; height <MAX; height++){
        for(int width= 0; width <MAX; width++){
            scanf("%d",&Map[height][width]);
        }
    }
    dfs(0,0);
    if(result == 26){
        printf("-1\n");
    }else{
        printf("%d\n",result);
    }
    return 0;
}
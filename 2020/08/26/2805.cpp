#include <cstdio>
using namespace std;
int main(){
    int n,m, tree[1000000],max_height=1000000000,min_height =0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<n;i++){
        scanf("%d", tree+i);
    }
    while(min_height+1 < max_height){
        int mid_height = (max_height + min_height)/2;
        long long need_height =0;
        for(int i = 0; i<n; i++){
            int cutted_height = tree[i] - mid_height;
            if(cutted_height > 0)
                need_height += cutted_height;
        }
        if(need_height >= m){
            min_height = mid_height;
        }else{
            max_height = mid_height;
        }
    }
    printf("%d\n",min_height);
    return 0;
}
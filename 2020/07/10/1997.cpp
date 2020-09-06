#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int n,m,ans = 0;
    scanf("%d %d",&n, &m);
    int mi = ceil(sqrt(n)), ma = ceil(sqrt(m)), ans_min = m;
    for(int i =mi; i<=ma;i++){
        int temp = pow(i,2);
        if( n<=temp && temp <= m){
            ans += temp;
            ans_min = min(ans_min,temp);
        }
    }
    if(ans != 0)
        printf("%d\n%d",ans,ans_min);
    else
        printf("-1");
    return 0;
}
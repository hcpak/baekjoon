#include <cstdio>
using namespace std;
int main(){
    int n, m, a[10000];
    scanf("%d %d",&n, &m);
    for(int i =0 ; i <n;i++){
        scanf("%d", a +i);
    }
    int s=0,e=0, sum=a[0], result =0;
    while(s<n){
        if( sum <= m){
            if(sum == m){
                result++;
            }
            if(e < n-1)
                sum += a[++e];
            else{
                break;
            }
        }else if(sum >m){
            if( s < n-1)
                sum -= a[s++];
            else
            {
                break;
            }
            
        }
    }
    printf("%d",result);
    return 0;
}
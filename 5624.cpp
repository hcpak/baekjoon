#include <cstdio>
using namespace std;
int arr[5001] ={0,};
bool mc[2000001] ={false};
bool c[2000001] = {false};
int main(){
    int n;
    scanf("%d", &n);
    for(int i =1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j =1;j<i;j++){
            int tmp = arr[i] - arr[j];
            if(tmp>=0){
                if(c[tmp]){
                    cnt++;
                    break;
                }
            }else{
                if(mc[-tmp]){
                    cnt++;
                    break;
                }
            }
        }
        for(int j =1; j<=i;j++){
            int next = arr[i] + arr[j];
            if(next>=0){
                c[next] = true;
            }else{
                mc[-next] =true;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
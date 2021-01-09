#include <cstdio>
using namespace std;
int main(){
    int n, m;
    int arr[100];
    scanf("%d %d", &n, &m);
    for(int i =0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    int sum =0,answer=0;
    for(int first= 0; first<n;first++){
        sum += arr[first];
        for(int second=first+1; second<n; second++){
            sum += arr[second];
            for(int third = second+1; third <n; third++){
                sum += arr[third];
                if( sum <= m && m- sum < m- answer ){
                    answer = sum;
                }
                sum -= arr[third];
            }
            sum -= arr[second];
        }
        sum -= arr[first];
    }
    printf("%d\n",answer);
    return 0;
}
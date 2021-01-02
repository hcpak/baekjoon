#include <cstdio>
using namespace std;
int main(){
    int n;
    long long answer=0;
    int arr[100000];
    scanf("%d", &n);
    long long sum =0;
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    for(int i=0; i<n;i++){
        sum -= arr[i];
        answer += arr[i] * sum;
    }
    printf("%lld", answer);
    return 0;
}
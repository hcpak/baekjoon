#include <cstdio>
using namespace std;
int main(){
    int n, sum = 1;
    scanf("%d", &n);
    for(int i = 2; i<=n; i++){
        sum += i;
    }
    printf("%d",sum);
    return 0;
}
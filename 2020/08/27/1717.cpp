//도대체 왜  p[i] 초기화를 -1로 했을 때 메모리 초과 나오고, n으로 했을때 맞았다고 나오는 지 잘 모르곘다.
#include <cstdio>
using namespace std;
int p[1000001];
int find(int n ){
    printf("n: %d p[n]: %d \n",n,p[n]);
    if(p[n] <0) return n;
    p[n] = find(p[n]);
    printf("changed p[n]: %d\n",p[n]);
    return p[n];
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b ) return;
    p[b] = a;
}
int main(){
    int n, m, c, a,b;
    scanf("%d %d", &n, &m);
    for(int i =0;i <=n; i++){
        p[i] = -1;
    }
    for(int i =0; i<m;i++){
        scanf("%d %d %d",&c, &a, &b);
        if(c == 1){
            if(find(a) == find(b)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }else{
            merge(a,b);
        }
    }
    return 0;
}
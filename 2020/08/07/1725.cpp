// 결국 내가 풀지 못했다. 하지만 거의 근접했다. 계속 퍼센트가 보이기 전에 틀리고, 8시간 이상 고민했는데 답이 안나와서 검색해서 내 스타일에 맞게 코딩했다.
//s.top().second에 저장할 내용이 뭘로 해야할지 계속 고민했는데, left라는 변수로 저렇게 하면 되더라.
//다시 한번 풀어볼만한 문제인 거 같다. 아마 코딩테스트가 이정도 문제가 계속 나올 거 같다. 
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    int n, x, left;
    long long result =0;
    scanf("%d", &n);
    stack<pair<int, int> > s;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        int left = i;
        while(!s.empty() && s.top().first > x){
            long long width = i - s.top().second, height = s.top().first;
            long long temp = width * height;
            left = s.top().second;
            result = max(result, temp);
            s.pop();
        }
        printf("left: %d x: %d\n",left, x);
        s.push(make_pair(x, left));
    }
    while(!s.empty()){
        printf("first: %d second: %d\n", s.top().first, s.top().second);
        long long width = n - s.top().second +1, height = s.top().first;
        long long temp = width * height;
        result = max(result, temp);
        s.pop();
    }
    printf("%lld\n",result);
    return 0;
}
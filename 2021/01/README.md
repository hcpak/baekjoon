# 백준 알고리즘 구현
## 퇴사 14501

쉬운 dfs 문제였다. 핵심 알고리즘이라고 할 것도 없다.

## 다음 순열 10972
이 문제 제출했을 때 런타임 에러(IntegerOverflow)가 나왔는데 해당 코드는 vector나 set 같은 stl 자료구조에 10000개 정도 넣어서 이런 문제가 발생한다고 짐작한다. 이 문제를 다른 방법으로 접근해야겠다는 생각이 들었다.
```
#include <cstdio>
#include <vector>
using namespace std;
vector<int> s;
int factorial[10001] ={1,};
int main(){
    int N;
    scanf("%d",&N);
    for(int i =1; i<=N;i++){
        s.push_back(i);
        factorial[i] =  i*factorial[i-1];
    }
    int temp,id =1;
    for(int i=1; i<=N;i++){
        scanf("%d", &temp);
        int count =0;
        for(vector<int>::iterator iter = s.begin(); iter!= s.end();iter++){
            if(*iter <temp){
                count++;
            }else if(*iter == temp){
                s.erase(iter);
                break;
            }
        }
        id += factorial[N-i] *count;
    }
    s.clear();
    for(int i =1; i<=N;i++){
        s.push_back(i);
    }
    if(id == factorial[N]){
        printf("-1\n");
    }else{
        for(int i=1; i<=N;i++){
            int count = id/factorial[N-i];
            int j=0;
            for(vector<int>::iterator iter = s.begin(); iter!= s.end();iter++){
                if(j == count){
                    printf("%d ", *iter);
                    s.erase(iter);
                    break;
                }
                j++;
            }
            id %= factorial[N-i];
        }
        printf("\n");
    }
    
    return 0;
}
```


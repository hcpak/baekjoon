# 백준 2565 전깃줄
## 그리디 푼 풀이 방법(틀린 내 풀이)
1. line의 교차 개수를 구한다(조합 방식으로 구한다).
2. 교차 개수가 모두 0이면 while 루프를 빠져나간다.
3. 교차 개수가 모두 0이 아니면 최대 교차 개수인 줄을 삭제한다.


### 틀린 내 코드
```
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    int n,answer=0;
    scanf("%d", &n);
    vector<pair<int,int> > line;
    int a,b;
    for(int i= 0; i < n;i++){
        scanf("%d %d", &a, &b);
        line.push_back(make_pair(a,b));
    }
    bool no_intersection_flag;
    do{
        //전깃줄 교차 개수 세기
        int intersecton[501] ={};
        for(int i =0; i< n;i++){
            int a_i = line[i].first, b_i =line[i].second;
            for(int j = i+1; j< n; j++ ){
                int a_j = line[j].first, b_j = line[j].second;
                //라인이 겹칠 때 plus
                if(a_i < a_j && b_i > b_j){
                    intersecton[i] +=1;
                    intersecton[j] +=1;
                }
                if(a_i > a_j && b_i < b_j){
                    intersecton[i] +=1;
                    intersecton[j] +=1;
                }
            }
        }
        no_intersection_flag =true;
        int max = 0, max_id =-1;
        for(int i=0; i<line.size();i++){
            if(max < intersecton[i]){
                max = intersecton[i];
                max_id = i;
            }
            if(no_intersection_flag && intersecton[i] !=0){
                no_intersection_flag =false;
            }
        }
        
        if(no_intersection_flag){
            break;
        }
        //가장 많은 전깃줄 교차한 전깃줄 빼기 
        vector<pair<int, int> >::iterator iter = line.begin();
        line.erase(iter + max_id);
        answer++; 
    }while(!no_intersection_flag);
    printf("%d\n",answer);
    return 0;
}
```


## LIS  알고리즘
LIS는 최장 증가 수열을 의미한다. 따라서 A를 작은 데에서 큰 대로 순서대로 정렬시키고, B에서 순서가 정렬된 최장 증가 수열을 찾고, 그것을 처음 받은 전깃줄 개수에서 빼주면 답이 된다.
```
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
    return a[0] < b[0];
}
int main(){
    int n;
    scanf("%d", &n);
    vector <vector <int> > line(n);
    int dp[n];
    for(int i = 0; i< n; i++){
        line[i] =vector<int>(2);
        scanf("%d %d", &line[i][0], &line[i][1]);
    }
    sort(line.begin(), line.end(), comp);

    int LIS = 0; 
    for( int i= 0; i <n;i++){
        dp[i] =1;
        for (int j= 0; j < i; j++){
            if(dp[j] + 1 > dp[i] && line[i][1] > line[j][1]) dp[i] =dp[i] +1;
        }
        LIS = max(LIS, dp[i]);
    }
    printf("%d\n", n - LIS);
    return 0;
}
```
이 코드는 https://sihyungyou.github.io/baekjoon-2565/ 에서 코드를 참고하여 풀었다.
이제 이 코드를 내 것으로 숙지시켜야 한다.

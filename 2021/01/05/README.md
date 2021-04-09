# 백준 이분탐색 
## 랜선 자르기 1654
### 핵심 아이디어 이분탐색으로 최대 랜선 길이를 구한다.
```
long long start = 0, end = (long long)__INT_MAX__ +1;
while(start + 1 != end){
    long long mid = (start +end) /2;
    int count =0;
    for(int i=0; i<n;i++){
        count += wire[i]/mid;
    }
    if( count >= k){
        start = mid;
    }else{
        end = mid;
    }
}
printf("%lld\n",start);
```
전형적인 이분탐색 문제, 3019 테트리스 때문에 자꾸 백준이 풀기 싫어진다. 그래서 일단은 테트리스 문제를 풀기 싫고, 한 문제를 풀어야겠고 그래서 이 문제를 풀게 되었다.
이런 전형적인 쉬운 문제는 이제 풀지 말고 실버 1 이상 문제를 풀어야겠다는 생각이 든다. 오늘 밤에 더 풀던가 해야겠다.

# 백준 구현
## 달팽이 1952
브론즈 문제임에도 불구하고, 시간이 굉장히 오래걸렸다. dfs로 풀었다. 더 간단한 풀이법이 있었을까 싶다.
### 핵심 아이디어: dfs, 방향 바뀔때 % 4로 나뉘게 하는 것!

## 순서쌍의 곱의 합 13900
이 문제를 맨 처음보고 그냥 for문 2개 쓰면 되겠네 싶었다. 다만 시간초과 날거 같았던 점이 n이 100000이었다. 10^5의 시간 복잡도 N^2이면 시간 초과날 것이 뻔했지만, 혹여 실버 5문제인데 nlogn이겠어?했다.
하지만 역시 더 빠른 시간복잡도를 필요로 했고, 결합법칙을 생각하면 O(n)으로 할 수 있었다.

### 핵심 아이디어: 결합 법칙, 수학
https://wkdtjsgur100.github.io/algo-13900/ 블로그를 참고하여 O(n)으로 풀 수 있는 방법을 확인했다. 
앞으로 시간복잡도를 먼저 계산하고 접근해야겠다는 생각이 들었다.
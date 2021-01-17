# 백준 알고리즘 분할정복, 이분탐색
## 색종이 만들기 2630
### 핵심 아이디어
### 4부분 검색 후 색깔을 나눌 수 없으면 다시 4부분 검색
```
void dfs(int y, int x, int n){
    bool white_flag = true, blue_flag = true;
    for(int h = y; h<y+n; h++){
        for(int w = x; w<x+n; w++){
            if(Map[h][w] == false){// white
                blue_flag = false;
            }else{
                white_flag = false;
            }
        }
    }
    if(!blue_flag && !white_flag){
        dfs(y,x,n/2);
        dfs(y,x+n/2,n/2);
        dfs(y+n/2,x,n/2);
        dfs(y+n/2,x+n/2,n/2);
    }else{
        if(blue_flag){
            blue_num++;
        }else{
            white_num++;
        }
    }
}
```
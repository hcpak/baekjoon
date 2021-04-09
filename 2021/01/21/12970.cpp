#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> str;
int N,K;
int main(){
    scanf("%d %d", &N, &K);
    dfs(0);
    if(find_flag){
        for(int i=0; i<str.size();i++){
            printf("%c",str[i]);
        }
        printf("\n");
    }else{
        printf("-1\n");
    }
    return 0;
}
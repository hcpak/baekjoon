// #include <cstdio>
// #include <vector>
// using namespace std;
// int n, s;
// int number[21] ={};
// bool visited[21] ={false};
// int answer =0;
// vector<int> stack;
// void dfs(int num){
//     if(stack.size() != 0){
//         int sum = 0;
//         for(int i = 0; i< stack.size();i++){
//             sum += stack[i];
//         }
//         if(sum == s){
//             answer++;
//         }
//     }
//     if(stack.size() != n){
//         for(int i = num+1 ; i< n;i++){
//             if(!visited[i]){
//                 visited[i] =true;
//                 stack.push_back(number[i]);
//                 dfs(i);
//                 visited[i] =false;
//                 stack.pop_back();
//             }
//         }
//     }
// }

// int main(){
//     scanf("%d %d",&n, &s);
//     for(int i = 0; i < n; i++){
//         scanf("%d", &number[i]);
//     }
//     dfs(-1);
//     printf("%d\n",answer);
//     return 0;
// }
#include <cstdio>
using namespace std;

int n, s, sum, cnt;
int arr[20];

void dfs(int i, int sum){
    if (i== n) return;
    if (sum+arr[i] == s) cnt++;

    dfs(i+1, sum);
    dfs(i+1, sum +arr[i]);
}

int main(){
    scanf("%d %d", &n, &s);
    for(int i =0; i< n; i++) scanf("%d", &arr[i]);
    cnt = 0;
    dfs(0, 0);

    printf("%d\n", cnt);
    return 0;
}
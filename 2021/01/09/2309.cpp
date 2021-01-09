#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> hobbit;
vector<int> seven_hobbit;
vector<int> answer;
bool flag = false;
void dfs(int id, int count){
    if(count == 7){
        int sum =0;
        for(int i=0; i<7;i++){
            sum += seven_hobbit[i];
        }
        if(!flag &&sum == 100){
            for(int i =0; i<7;i++){
                answer.push_back(seven_hobbit[i]);
            }
            flag =true;
            return;
        }
    }else{
        for(int i =id+1; i<9;i++){
            seven_hobbit.push_back(hobbit[i]);
            dfs(i, count+1);
            if(flag){
                return;
            }
            seven_hobbit.pop_back();
        }
    }
}
int main(){
    int temp;
    for(int i=0;i <9;i++){
        scanf("%d", &temp);
        hobbit.push_back(temp);
    }
    dfs(-1,0);
    sort(answer.begin(), answer.end());
    for(int i=0; i< 7;i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}
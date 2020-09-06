// 재귀함수 짜는 게 쉽지가 않았음.
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void bfs(vector<int> v[], int count, int goal,int gap,int end, bool* flag){
    int num = v[count].size();
    // cout <<"count: " << count<< " goal 값은?: " << goal <<" gap의 값은?: " << gap <<endl;
    if(*flag == true){
        return;
    }
    for(int i = 0; i < num;i++){
        // cout << "v[" << count << "][" <<i <<"]: " << v[count][i] <<endl;
        if(count == 1 && v[count][i] > goal){
            gap = v[count][i] - goal;
            // cout <<"i의 값은: " << i<<" count: " << count<<" gap의 값은?: " << gap <<endl;
        }
        if(count == end && v[count][i] >goal && v[count][i] - goal == gap){
            *flag = true;
            return;
        }
        if(v[count][i] >goal && v[count][i] - goal == gap){
            bfs(v, count+1, v[count][i], gap, end, flag);
        }
    }
}
int main(){
    string str,buf_str,input_str;
    int N,count =0;
    cin >> N;
    cin >> str;
    int NUM = str.length();
    int buf_NUM;
    bool flag = false;
    vector<int> v[NUM];
    for(int i =0;i<N;i++){
        for(int i = 0 ;i < NUM;i++){
            v[i].clear();
        }
        cin >> input_str;
        buf_str = input_str;
        buf_NUM = buf_str.length();
        for(int i = 0;i < buf_NUM; i++){
            for(int j = 0 ; j < NUM; j++){
                if(buf_str[i] ==str[j]){
                    v[j].push_back(i);
                }
            }
        }
        // for(int i=0;i<NUM;i++){
        //     for(int j = 0;j <v[i].size();j++){
        //         cout << v[i][j] <<" ";
        //     }
        //     cout <<endl;
        // }
        // cout << flag<< " ";
        for(int i = 0; i < v[0].size();i++){
            bfs(v, 1,v[0][i],-1, NUM-1, &flag);
        }
        // cout << flag<< endl;
        if(flag){
            // cout << "i: " << i<< " count: " << count << endl;
            count++;
            flag = false;
        }
    }
    cout << count;
    return 0;
}
/*
1
bar
abracadabra

1
bar
bear
*/
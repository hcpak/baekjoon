#include <iostream>
#include <string.h>
using namespace std;
#define MAX 5001
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N,M;
    int people[10001][4];
    int police[101][2];
    int count = -1;
    while(1){
        cin >> N >> M;
        if(N == 0 && M == 0)
            break;
        if(count != -1)
            cout <<endl;
        for(int i = 1; i<= N; i++){
            cin >> people[i][0] >> people[i][1] >> people[i][2] >> people[i][3];
        }
        for(int i = 1; i <= M; i++){
            cin >> police[i][0] >> police[i][1];
            count = 0;
            for(int j = 1; j<= N; j++){
                int people_start = people[j][2],people_end = people[j][2]+people[j][3];
                int police_start = police[i][0],police_end = police[i][0] + police[i][1];
                if( police_start<=people_start && people_start < police_end){
                    count++;
                }
                else if( people_start<=police_start && police_end <= people_end){
                    count++;
                }else if(police_start< people_end && people_end <= police_end){
                    count++;
                }
            }
            cout << count;
            if(i != M)
                cout <<endl;
        }
    }
    return 0;
}
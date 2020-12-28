#include <cstdio>
#include <cstring>
#define MAX_CHAR_NUM 80
using namespace std;
int main(){
    int T;
    char Tcase[MAX_CHAR_NUM];
    scanf("%d", &T);
    for(int i =0; i< T;i++){
        scanf("%s",Tcase);
        int total_point =0, current_point =1;
        for(int j = 0; j< strlen(Tcase);j++){
            if(Tcase[j] == 'O'){
                total_point += current_point;
                current_point++;
            }else{
                current_point = 1;
            }
        }
        printf("%d\n",total_point);
    }
    return 0;
}
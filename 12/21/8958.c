#include <stdio.h>
#include <string.h>
#define MAX_NUM_CHAR 80
int main(){
    int T;
    scanf("%d",&T);
    char str[MAX_NUM_CHAR];
    for(int i= 0; i < T; i++){
        scanf("%s",str);
        int total_point = 0, current_point =1;
        for(int j =0; j < strlen(str); j++){
            if(str[j] == 'O'){
                total_point += current_point;
                current_point++;
            }else{
                current_point =1;
            }
        }
        printf("%d\n", total_point);
    }
    return 0;
}
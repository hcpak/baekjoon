#include <cstdio>
#include <cmath>
using namespace std;
int Gear[4][8] ={};
int gear_location[4] ={};
int gear_left_side(int gear_location){
    if(gear_location -2 <0){
        return (gear_location +8 -2);
    }else{
        return gear_location -2;
    }
}
int gear_right_side(int gear_location){
    if(gear_location +2 >7){
        return (gear_location + 2 - 8);
    }else{
        return gear_location + 2;
    }
}
void rotate(int g_id, int direction){
    if(direction == 1){
        gear_location[g_id] = gear_location[g_id] -1 <0 ? 7 : gear_location[g_id] -1;
    }else if(direction == -1){
        gear_location[g_id] = gear_location[g_id] +1 >7 ? 0 : gear_location[g_id] +1;
    }   
}
int main(){
    for(int i =0; i<4;i++){
        for(int j =0; j<8;j++){
            scanf("%1d", &Gear[i][j]);
        }
    }
    int k;
    scanf("%d", &k);
    int gear_id, direction;
    
    for(int i=0; i< k; i++){
        scanf("%d %d", &gear_id, &direction);
        gear_id--;
        int gear_direction[4] ={};
        gear_direction[gear_id] = direction;
        for(int g_id = gear_id; g_id >0; g_id--){
            int right_gear_location = gear_left_side(gear_location[g_id]);
            int left_gear_location = gear_right_side(gear_location[g_id-1]);
            if(Gear[g_id-1][left_gear_location] == Gear[g_id][right_gear_location]){
                break;
            }else{
                gear_direction[g_id-1] = -gear_direction[g_id];
            }
        }
        for(int g_id = gear_id; g_id < 3; g_id++){
            int left_gear_location = gear_right_side(gear_location[g_id]);
            int right_gear_location = gear_left_side(gear_location[g_id+1]);
            if(Gear[g_id][left_gear_location] == Gear[g_id+1][right_gear_location]){
                break;
            }else{
                gear_direction[g_id+1] = -gear_direction[g_id];
            }
        }
        for(int g_id=0; g_id <4; g_id++){
            rotate(g_id,gear_direction[g_id]);
        }
    }
    int answer =0;
    for(int i =0; i<4;i++){
        if(Gear[i][gear_location[i]] == 1){
            answer += pow(2, i);
        }
    }
    printf("%d",answer);
    return 0;
}
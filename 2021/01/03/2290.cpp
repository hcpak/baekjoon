#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int s;
    char str[11];
    bool check[7][11] = {};
    scanf("%d %s", &s, str);
    int n = strlen(str);
    for(int i =0; i< n;i++){
        int cur = str[i] - '0';
        switch(cur){
            case 0: case 2: case 3: case 5: 
            case 6: case 7: case 8: case 9:
                check[0][i] = true;
                if( cur == 2 || cur == 3 || cur == 7)
                    check[1][i] = false;
                else
                    check[1][i] = true;
                
                if( cur == 5 || cur == 6)
                    check[2][i] = false;
                else
                    check[2][i] = true;
                if( cur == 7 || cur ==0)
                    check[3][i] = false;
                else
                    check[3][i] = true;
                if(cur == 2 || cur == 6 || cur ==8 || cur == 0)
                    check[4][i] = true;
                else
                    check[4][i] = false;
                if(cur == 2)
                    check[5][i] = false;
                else
                    check[5][i] = true;
                if(cur == 7)
                    check[6][i] = false;
                else
                    check[6][i] = true;
                break;
            case 1:
                check[0][i] = false;
                check[1][i] = false;
                check[2][i] = true;
                check[3][i] = false;
                check[4][i] = false;
                check[5][i] = true;
                check[6][i] = false;
                break;
            case 4:
                check[0][i] = false;
                check[1][i] = true;
                check[2][i] = true;
                check[3][i] = true;
                check[4][i] = false;
                check[5][i] = true;
                check[6][i] = false;
                break;
        }
    }
    for(int height =0; height < 2*s +3; height++){
        for(int width =0; width < (s+3)*n; width++){
            int cur_width = width % (s+2+1);
            int cur_id = width / (s+3);
            // printf("width: %d\n",width);
            // printf("s: %d cur_width: %d cur_id: %d\n",s,cur_width,cur_id);
            if(height == 0){
                if(1<=cur_width && cur_width <=s){
                    if(check[0][cur_id])
                        printf("-");
                    else
                        printf(" ");
                }
                else{
                    printf(" ");
                }
            }else if( 0<height && height<= s){
                if(cur_width == 0){
                    if(check[1][cur_id])
                        printf("|");
                    else
                        printf(" ");
                }else if(cur_width == s+1){
                    if(check[2][cur_id])
                        printf("|");
                    else
                    {
                        printf(" ");
                    }
                }else{
                    printf(" ");
                }
            }else if( height == s+1){
                if(1<=cur_width && cur_width <=s){
                    if(check[3][cur_id])
                        printf("-");
                    else
                        printf(" ");
                }
                else{
                    printf(" ");
                }
            }else if(  s+1 <height && height <= 2*s+1 ){
                if(cur_width == 0){
                    if(check[4][cur_id])
                        printf("|");
                    else
                        printf(" ");
                }else if(cur_width == s+1){
                    if(check[5][cur_id])
                        printf("|");
                    else
                    {
                        printf(" ");
                    }
                }else{
                    printf(" ");
                }
            }else{
                if( 1<=cur_width && cur_width <=s){
                    if(check[6][cur_id])
                        printf("-");
                    else
                        printf(" ");
                }
                else{
                    printf(" ");
                }
            }
            
        }
        printf("\n");
    }


    return 0;
}
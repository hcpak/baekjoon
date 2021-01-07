#include <cstdio>
using namespace std;
int field[100]={};
int main(){
    int c,p;
    scanf("%d %d", &c, &p);
    for(int i=0; i < c;i++){
        scanf("%d", &field[i]);
    }
    int answer =0;
    for(int i=0; i< c;i++){
        switch(p){
            case 1:
                answer++; 
                if(i+3<c &&field[i]==field[i+1] && field[i+1]==field[i+2] && field[i+2]==field[i+3]) answer++; 
                break;
            case 2:
                if(i+1<c && field[i]==field[i+1]) answer++; 
                break;
            case 3:
                if(i+1<c && field[i]==field[i+1] && field[i+1]+1==field[i+2]) answer++; 
                if(i+1<c && field[i]==field[i+1]+1) answer++;  
                break;
            case 4:
                if(i+2<c && field[i]==field[i+1]+1 && field[i+1]==field[i+2]) answer++;
                if(i+1<c && field[i]+1==field[i+1]) answer++; 
                break;
            case 5:
                if(i+2<c && field[i]==field[i+1] && field[i+1]==field[i+2])  answer++;  
                if(i+2<c && field[i]==field[i+2] && field[i+1]==field[i]-1)  answer++;  
                if(i+1<c && field[i]+1==field[i+1])  answer++;  
                if(i+1<c && field[i]==field[i+1]+1)  answer++;  
                break;
            case 6:
                if(i+2<c && field[i]==field[i+1] && field[i+1]==field[i+2])      answer++;  
                if(i+2<c && field[i]+1==field[i+1] && field[i+1]==field[i+2])    answer++; 
                if(i+1<c && field[i]==field[i+1])    answer++; 
                if(i+1<c && field[i]==field[i+1]+2)  answer++; 
                break;
            case 7:
                if(i+2<c && field[i]==field[i+1] && field[i+1]==field[i+2])  answer++; 
                if(i+2<c && field[i]==field[i+1] && field[i+1]==field[i+2]+1) answer++; 
                if(i+1<c && field[i]==field[i+1])    answer++;
                if(i+1<c && field[i]+2==field[i+1])  answer++;
                break;
        }
    }
    printf("%d",answer);
    return 0;
}
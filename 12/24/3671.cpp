#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX_NUMBER 10000000
using namespace std;
bool prime_number[MAX_NUMBER] = {true,true};
vector<int> number;
set<int> num_permutation;
int main(){
    char str[7];
    int c;
    
    scanf("%d",&c);
    for( int i =2 ; i*i < MAX_NUMBER; i++){
        if(!prime_number[i]){
            for(int j = i *i ; j < MAX_NUMBER; j += i){
                if(!prime_number[j]) prime_number[j] =true;
            }
        }
    }
    for(int i=0; i<c; i++){
        int answer =0;
        scanf("%s",str);
        for(int j = 0; j < strlen(str);j++){
            number.push_back(str[j]-'0');
        }
        sort(number.begin(),number.end());
        do{
            int tmp = 0;
            for(int j = 0; j < strlen(str);j++){
                tmp = 10 *tmp + number[j];
                num_permutation.insert(tmp);
            }
        }while(next_permutation(number.begin(), number.end()));
        for(set<int>::iterator iter = num_permutation.begin(); iter != num_permutation.end(); iter++ ){
            if(!prime_number[*iter]) answer++;
        }
        printf("%d\n",answer);
        number.clear();
        num_permutation.clear();
    }
    return 0;
}
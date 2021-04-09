#include <cstdio>


// #include <cstdio>
// #include <vector>
// using namespace std;
// vector<int> s;
// int factorial[10001] ={1,};
// int main(){
//     int N;
//     scanf("%d",&N);
//     for(int i =1; i<=N;i++){
//         s.push_back(i);
//         factorial[i] =  i*factorial[i-1];
//     }
//     int temp,id =1;
//     for(int i=1; i<=N;i++){
//         scanf("%d", &temp);
//         int count =0;
//         for(vector<int>::iterator iter = s.begin(); iter!= s.end();iter++){
//             if(*iter <temp){
//                 count++;
//             }else if(*iter == temp){
//                 s.erase(iter);
//                 break;
//             }
//         }
//         id += factorial[N-i] *count;
//     }
//     s.clear();
//     for(int i =1; i<=N;i++){
//         s.push_back(i);
//     }
//     if(id == factorial[N]){
//         printf("-1\n");
//     }else{
//         for(int i=1; i<=N;i++){
//             int count = id/factorial[N-i];
//             int j=0;
//             for(vector<int>::iterator iter = s.begin(); iter!= s.end();iter++){
//                 if(j == count){
//                     printf("%d ", *iter);
//                     s.erase(iter);
//                     break;
//                 }
//                 j++;
//             }
//             id %= factorial[N-i];
//         }
//         printf("\n");
//     }
    
//     return 0;
// }
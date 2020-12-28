#include <cstdio>
#include <vector>
using namespace std;
long long N, version, k;
vector<long long> v;
vector<long long> find_v;
bool visited[21] = {};
long long factorial[21]={1,};

int main(){
    scanf("%lld %lld", &N, &version);
    for(long long i = 1; i < 21; i++)
        factorial[i] = factorial[i-1] *i;
    if(version ==1){
        scanf("%lld", &k);
        long long temp = k -1;
        for(long long i =0; i < N;i++){
            long long share = temp / factorial[N-i-1];
            temp %= factorial[N-i-1];
            long long count = 0;
            for(long long j = 1; j <= N; j++){
                if(!visited[j]){
                    if(count == share){
                        visited[j]= true;
                        v.push_back(j);
                        break;
                    }
                    count++;
                }
            }
        }
        for(long long i = 0; i< N;i++){
            printf("%lld ",v[i]);
        }
        printf("\n");
    }else{
        long long answer =0;
        for(long long i = 0; i<N;i++){
            long long tmp;
            scanf("%lld", &tmp);
            long long cnt = 0;
            for(long long j = 1; j <= N; j++){
                if(!visited[j]){
                    if(j == tmp){
                        visited[j] = true;
                        answer += cnt * factorial[N - i -1];
                        break;
                    }
                    cnt++;
                }

            }
        }
        printf("%lld\n",answer+1);
    }
    return 0;
}

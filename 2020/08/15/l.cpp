#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int main(){
    int n, x,p;
    vector<pair<int,int> > v;
    queue<tuple<int, int, int> > q;
    scanf("%d",&n);
    for(int i = 0; i< n;i++){
        long long prize=0;
        scanf("%d %d",&x,&p);
        v.push_back(make_pair(x,p));
        q.push(make_tuple(0,i,1));
    }
    bool flag = false;
    while(!q.empty()){
        int prize = get<0>(q.front()), NoParticpate = get<1>(q.front()), count = get<2>(q.front());
        if(count == n){
            flag =true;
            break;
        }
        q.pop();
        if(NoParticpate != count){
            if(prize < v[count].first){
                q.push(make_tuple(prize+v[count].second, NoParticpate, count+1));
            }
        }else{
            q.push(make_tuple (prize, NoParticpate, count+1));
        }
    }
    if(flag){
        printf("Kkeo-eok");
    }else{
        printf("Zzz");
    }
}
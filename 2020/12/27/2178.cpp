#include <cstdio>
#include <tuple>
#include <queue>
using namespace std;
int N, M;
int Map[101][101] ={};
int next_x[4]={-1,1,0,0}, next_y[4] = {0,0,1,-1};
bool check_range(int x, int y){
    if( x > N ||  x == 0  )
        return false;
    if( y > M || y == 0)
        return false;
    return true;
}
int bfs(int x, int y){
    bool visited[101][101] = {};
    queue< tuple <int, int, int> > q;
    q.push(make_tuple(x,y,1));
    visited[x][y]= true;
    while(!q.empty()){
        int temp_x = get<0>(q.front()), temp_y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();
        for(int i=0; i<4;i++){
            int x_next = temp_x + next_x[i], y_next = temp_y + next_y[i];
            if(check_range(x_next,y_next)){
                if(x_next == N && y_next == M){
                    return cnt+1;
                }
                if(Map[x_next][y_next] &&!visited[x_next][y_next]){
                    visited[x_next][y_next]= true;
                    q.push(make_tuple(x_next,y_next, cnt+1));
                }
            }
        }
    }
    return 0;
}


int main(){
    scanf("%d %d", &N, &M);
    int temp;
    for(int i =1 ; i <= N;i++){
        for(int j =1; j <= M; j++){
            scanf("%1d", &Map[i][j]);
        }
    }
    int answer = bfs(1,1);
    printf("%d\n",answer);
    return 0;
}
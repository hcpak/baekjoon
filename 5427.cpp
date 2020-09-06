#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;
static char graph[MAX][MAX];
static bool visited[MAX][MAX];
queue<pair<int, int> > fire_q;
queue<pair< pair<int, int>, int> > q;
int main(){
    int t,w,h;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> w >> h;
        if( i != 0){
            cout <<"\n";
        }
        while(!fire_q.empty())fire_q.pop();
        while(!q.empty()) q.pop();
        bool flag = false;
        
        for(int j=0;j<h;j++){
            for(int k =0;k<w;k++){
                cin >> graph[j][k];
                visited[j][k] =false;
                if(graph[j][k] == '*'){
                    fire_q.push(make_pair(j,k));
                }
                if(graph[j][k] == '@'){
                    q.push(make_pair(make_pair(j,k),0));
                }
            }
        }
        while(!q.empty()){
            int fire_size = fire_q.size();
            while(fire_size--){
                int f_x = fire_q.front().second, f_y = fire_q.front().first;
                fire_q.pop();
                int fx[4] = {f_x-1,f_x+1,f_x,f_x};
                int fy[4] = {f_y,f_y,f_y-1,f_y+1};
                for(int j = 0;j<4;j++){
                    if(fx[j]>=0 && fx[j]<w && fy[j]>=0&& fy[j]<h){
                        if(graph[fy[j]][fx[j]] != '#' && graph[fy[j]][fx[j]] != '*' ){
                            graph[fy[j]][fx[j]] = '*';
                            fire_q.push(make_pair(fy[j],fx[j]));
                        }
                    }
                }
            }
            int size = q.size();
            while(size--){
                int x = q.front().first.second, y = q.front().first.first;
                int c = q.front().second;
                q.pop();
                if(x == 0 || x == w-1 || y == 0 || y == h-1){
                    cout << c+1;
                    flag = true;
                    break;
                }
                int x_pos[4] = {x-1,x+1,x,x},y_pos[4] = {y,y,y-1,y+1};
                for(int j =0;j<4;j++){
                    if(x_pos[j]>=0 && x_pos[j]<w && y_pos[j]>=0 && y_pos[j]<h){
                        if(graph[y_pos[j]][x_pos[j]] == '.' && visited[y_pos[j]][x_pos[j]] == false){
                            visited[y_pos[j]][x_pos[j]] = true;
                            q.push(make_pair(make_pair(y_pos[j],x_pos[j]),c+1));
                        }
                    }
                }
            }
            if(flag)
                break;
        }
        if(!flag)
            cout << "IMPOSSIBLE";
    }
    return 0;
}
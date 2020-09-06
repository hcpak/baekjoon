#include<iostream>
#include<queue>
 
using namespace std;
 
queue<pair<int, int> > q;
int map[1001][1001] = { 0 };
bool visit[1001][1001] = { 0 };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
 
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push(make_pair(i, j));
                visit[i][j] = true;
            }
            else if (map[i][j] == -1)visit[i][j] = true;
        }
    }
 
    int ans = -1;
 
    while (!q.empty())
    {
        int size = q.size();
        ans++;
        while (size--)
        {
            pair<int, int> now = q.front(); q.pop();
            for (int k = 0; k < 4; k++)
            {
                int qx = now.second + dx[k];
                int qy = now.first + dy[k];
                if (qx >= 0 && qx < m && qy >= 0 && qy < n)
                {
                    if (!visit[qy][qx] && !map[qy][qx])
                    {
                        visit[qy][qx] = 1;
                        q.push(make_pair(qy, qx));
                    }
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visit[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}

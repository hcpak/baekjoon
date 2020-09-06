#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
void bfs(int start, vector<int> graph[], bool check[], int* count){
	queue<int> q;

	q.push(start);
	check[start] = true;
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		// printf("%d ",tmp);
        *count = *count +1;
		for(int i=0; i<graph[tmp].size(); i++){

			// 방문하지 않았다면
			if(check[graph[tmp][i]] == false){
				// 큐에 넣어주고 방문했음을 표시한다.
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}

}

int main (){

	int N, M;
	cin >> N >> M;
	vector<int> graph[N+1];
    int c[N+1];
	bool check [N+1];
	fill(check, check+N+1, false);

	for(int i=0; i<M; i++){
		int u,v;
		cin >> u >> v;
		graph[v].push_back(u);
	}

	// Sorting은 왜 한거지?
	// 나중에 하나의 정점에서 다음을 탐색할 때 node 값에 순차적으로 접근해야하기 때문
	for(int i=1; i<=N; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	//bfs
    int count =0;
    for(int i =1;i<=N;i++){
        fill(check, check+N+1, false);
        bfs(i, graph, check,&count);
        c[i] = count;
        // cout <<count <<endl;
        count =0;
    }
    int max=0;
    vector<int> ans;
    for(int i=1;i<=N;i++){
        if(max < c[i]){
            ans.clear();
            max = c[i];
            ans.push_back(i);
        }else if( max == c[i]){
            ans.push_back(i);
        }
    }
    for(int i =0;i<ans.size();i++){
        if(i != 0)
            cout << " ";
        cout << ans[i];
    }
	return 0;
}

#include <cstdio>
#include <vector>
using namespace std;
long long factorial(long long n);
long long * check_Tree(vector<int> graph[], bool visited[], int start, int count);
int main(){
    int n, u, v;
    long long D_Tree_Num = 0, G_Tree_Num =0;
    scanf("%d",&n);
    vector<int> graph[n+1];
    bool check[n+1];
    for(int i =1 ; i<n;i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool visited[n+1];
    for(int i =1 ; i<=n;i++){
        for(int j =i; j<=n; j++) visited[j] = false;
        long long * Tree = check_Tree(graph, visited, i, 1);
        D_Tree_Num += Tree[0] + Tree[1];
        G_Tree_Num += Tree[2];
        delete [] Tree;
    }
    if(D_Tree_Num > 3* G_Tree_Num){
        printf("D");
    }else if(D_Tree_Num == 3 * G_Tree_Num){
        printf("DUDUDUNGA");
    }else{
        printf("G");
    }
    return 0;
}

long long factorial(long long n){
    long long result = 1;
    for (long long i = 1; i<=n; i++){
        result *= i;
    }
    return result;
}

long long * check_Tree(vector<int> graph[], bool visited[], int start, int count){
    long long * Tree_Num = new long long[3];
    Tree_Num[0] =0; // D_Tree
    Tree_Num[1] =0; // D_Tree
    Tree_Num[2] =0; // G_Tree
    visited[start] = true;
    if(count == 4){
        Tree_Num[0]= 1;
        return Tree_Num;
    }
    int Connect_Node = graph[start].size(), child_num =0;
    for(int i = 0; i < Connect_Node; i++){
        int next_node = graph[start][i];
        if(!visited[next_node]){
            child_num++;
            long long * check_D_Tree_num = check_Tree(graph, visited, next_node, count+1);
            Tree_Num[0] += check_D_Tree_num[0];
            Tree_Num[1] += check_D_Tree_num[1];
            Tree_Num[2] += check_D_Tree_num[2];
        }
    }
    if(count ==1 && child_num <2){
        Tree_Num[1] =0;
    }
    if(count == 1 && child_num >= 3){
        Tree_Num[2] += factorial(child_num) / 6 / factorial(child_num-3);
    }
    if(count == 2){ 
        if(child_num >= 1){
            Tree_Num[1] += child_num;
        }
        if(child_num >=2)
            Tree_Num[2] += factorial(child_num) / 2 / factorial(child_num-2);
    }
    return Tree_Num;
}
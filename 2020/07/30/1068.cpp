#include <cstdio>
#include <vector>
using namespace std;
int target;
int visited(vector<int> tree[], int current){
    int sum =0;
    if(current == target){
        return 0;
    }
    if(tree[current].size() ==0){
        return 1;
    }else{
        for(int i = 0; i < tree[current].size(); i++){
            int child = tree[current][i];
            if(child == target){
                if(tree[current].size() -1== 0){
                    return 1;
                }
            }else{
                sum += visited(tree, child);
            }
        }
    }
    return sum;
}
int main(){
    int n, node, root;
    scanf("%d", &n);
    vector<int> tree[n];
    for(int i = 0; i< n;i++){
        scanf("%d", &node);
        if(node == -1){
            root = i;
        }else{
            tree[node].push_back(i);
        }
    }
    scanf("%d", &target);
    printf("%d",visited(tree, root));
    return 0;
}
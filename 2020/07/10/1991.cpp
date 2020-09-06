#include <cstdio>
#include <vector>
using namespace std;
void preorder(vector<int> tree[], int start){
    int leftchild = tree[start][0], rightchild = tree[start][1];
    printf("%c",'A'+start);
    if(leftchild >=0){
        preorder(tree, leftchild);
    }
    if(rightchild >=0){
        preorder(tree,rightchild);
    }
}
void inorder(vector<int> tree[], int start){
    int leftchild = tree[start][0], rightchild = tree[start][1];
    if(leftchild >=0){
        inorder(tree, leftchild);
    }
    printf("%c",'A'+start);
    if(rightchild >=0){
        inorder(tree,rightchild);
    }
}
void postorder(vector<int> tree[], int start){
    int leftchild = tree[start][0], rightchild = tree[start][1];
    if(leftchild >=0){
        postorder(tree, leftchild);
    }
    if(rightchild >=0){
        postorder(tree,rightchild);
    }
    printf("%c",'A'+start);
}
int main(){
    int n;
    scanf("%d",&n);
    char pch, lch, rch;
    vector<int> tree[n];
    int parent[n];
    parent[0] = -1;
    for(int i=0;i<n;i++){
        scanf(" %c %c %c", &pch, &lch, &rch);
        int parent = pch - 'A', lchild = lch - 'A', rchild = rch - 'A';
        tree[parent].push_back(lchild);
        tree[parent].push_back(rchild);
    }
    preorder(tree,0);
    printf("\n");
    inorder(tree,0);
    printf("\n");
    postorder(tree,0);
    return 0;
}
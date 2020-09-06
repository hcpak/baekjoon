#include <cstdio>
#include <vector>
using namespace std;
void preorder(vector<int> tree[], int current){
    int lch= tree[current][0], rch = tree[current][1];
    printf("%c",'A'+current);
    if(lch != -19){
        preorder(tree, lch);
    }
    if(rch != -19){
        preorder(tree, rch);
    }
}

void inorder(vector<int> tree[], int current){
    int lch= tree[current][0], rch = tree[current][1];
    if(lch != -19){
        inorder(tree, lch);
    }
    printf("%c",'A'+current);
    if(rch != -19){
        inorder(tree, rch);
    }
}

void postorder(vector<int> tree[], int current){
    int lch= tree[current][0], rch = tree[current][1];
    if(lch != -19){
        postorder(tree, lch);
    }
    if(rch != -19){
        postorder(tree, rch);
    }
    printf("%c",'A'+current);
}
int main(){
    int n;
    scanf("%d", &n);
    vector<int> tree[n];
    char a, b, c;
    int parent, lch, rch;
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &a, &b, &c);
        parent = a - 'A';
        lch = b - 'A';
        rch = c - 'A';
        tree[parent].push_back(lch);
        tree[parent].push_back(rch);
    }
    preorder(tree, 0);
    printf("\n");
    inorder(tree, 0);
    printf("\n");
    postorder(tree, 0);
    return 0;
}
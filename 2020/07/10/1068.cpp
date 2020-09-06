#include<cstdio>
#include<set>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int tree[n], parent,del;
    bool leaf[n];
    for(int i= 0;i<n;i++){
        scanf("%d",&parent);
        tree[i] = parent;
        leaf[i] = true;
    }
    scanf("%d",&del);
    tree[del] = -2;
    set<int> list;
    list.insert(del);
    while(!list.empty()){
        int temp = *list.begin();
        list.erase(temp);
        for(int i = 0; i< n;i++){
            if(tree[i] == temp){
                list.insert(i);
                tree[i] = -2;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(tree[i] == -2){
            leaf[i] = false;
        }else if( tree[i] == -1){

        }else{
            leaf[tree[i]] = false;
        }
    }
    int count =0;
    for(int i=0;i<n;i++){
        if(leaf[i] == true){
            count++;
        }
    }
    printf("%d",count);
    return 0;
}
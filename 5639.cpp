#include <iostream>
#include <cstdio>
#define null 0
using namespace std;
template <typename T>
class Tree;
template <typename T>
class TreeNode{
    friend class Tree<T>;
private: 
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data =0, TreeNode* left = null, TreeNode* right =null){
        this->data =data;
        this->left = left;
        this->right = right;
    }
    friend ostream& operator << (ostream& os, const TreeNode<T>& node){
        os << "[data]" << node.data << endl;
        if(node.left != null){
            os << "[left] " << node.left->data << endl;
        }
        if ( node.right != null){
            os << "[right] " << node.right->data <<endl;
        }
        return os;
    }
};
template <typename T>
class Tree{
    private:
        TreeNode<T>* root;
    public:
        Tree(T data =0){
            root = new TreeNode<T> (data);
        }
        TreeNode<T>* getRoot(){
            return root;
        }
        void postorder(TreeNode<T>* currnet){
            if(currnet!= null){
                postorder(currnet->left);
                postorder(currnet->right);
                visit(currnet);
            }
        }
        void visit(TreeNode<T>* current){
            cout << current->data << "\n";
        }
        TreeNode<T>* search(TreeNode<T>* current, T data){
            if(current == null) return null;
            if(data == current->data){
                return current;
            }else if( data < current->data){
                search(current-> left, data);
            }else{
                search(current->right, data);
            }
            return null;
        }
        void insertNode(TreeNode<T>* node){
            if(search(root, node->data) == null){
                TreeNode<T>* parent = null;
                TreeNode<T>* current = root;
                while(current != null){
                    parent = current;
                    if(node->data < parent->data){
                        current = current->left;
                    }else{
                        current = current->right;
                    }
                }
                if(node->data < parent->data){
                    parent->left = node;
                }else{
                    parent->right = node;
                }
                // cout << "Inserted " << node->data <<endl;
            }
        }
        
};

int main(){
    int input;
    scanf("%d",&input);
    Tree<int> tree(input);
    while(scanf("%d",&input) != EOF){
        tree.insertNode(new TreeNode<int>(input));
    }
    // tree.postorder(tree.getRoot());
    return 0;
}
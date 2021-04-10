// #include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
    TreeNode* root;
    public:
        BST(){
            root = nullptr;
        }

        void insert(int x){
            if(!root){
                root = new TreeNode(x);
            }
            else{
                TreeNode* temp = root;
                while(true){
                    if(temp && x>temp->data){
                        if(!temp->right){
                            temp->right = new TreeNode(x);
                            break;
                        }
                        temp = temp->right;
                    }
                    if(temp && x<temp->data){
                        if(!temp->left){
                            temp->left = new TreeNode(x);
                            break;
                        }
                        temp = temp->left;
                    }
                }
            }
        }

        void display(){  // BFS
            queue<TreeNode*> bfs;
            bfs.push(root);

            while(!bfs.empty()){
                int size = bfs.size();

                for(int i=0; i<size; ++i){
                    TreeNode* front = bfs.front();
                    bfs.pop();
                    if(front->left) bfs.push(front->left);
                    if(front->right) bfs.push(front->right);
                    cout<<front->data<<" ";
                }
            }
        }
};

int main(){
    BST bst;
    int n;
    cout<<"Enter the no. of nodes\n";
    cin>>n;

    for(int i=0; i<n; ++i){
        int nodeVal;
        cout<<"Enter node value: ";
        cin>>nodeVal;
        bst.insert(nodeVal);
    }

    bst.display();
    return 0;
}
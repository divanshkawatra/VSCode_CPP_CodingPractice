#include<iostream>

using namespace std;

struct TreeNode{
    int val; //int data
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
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
                
            }
        }


};

int main(){

}
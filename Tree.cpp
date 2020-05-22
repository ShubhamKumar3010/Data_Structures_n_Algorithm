#include "TreeNode.h"
#include <iostream>

void printRoot(TreeNode<int> *pNode);

using namespace std;
int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    TreeNode<int>* node3 = new TreeNode<int>(4);
    TreeNode<int>* node4 = new TreeNode<int>(5);
    TreeNode<int>* node5 = new TreeNode<int>(6);
    TreeNode<int>* node6 = new TreeNode<int>(7);

    root->children.push_back(node1);
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    root->children.push_back(node5);
    root->children.push_back(node6);
    printRoot(root);
}

void printRoot(TreeNode<int> *root) {
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printRoot(root->children[i]);
    }
}

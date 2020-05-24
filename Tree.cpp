#include "TreeNode.h"
#include <iostream>
#include <queue>
void printRoot(TreeNode<int> *pNode);
void printLevelWise(TreeNode<int>* root);
TreeNode<int>* takeInput();
TreeNode<int>* takeInputBetter();
int countNodes(TreeNode<int>* root);
int sumOfNodes(TreeNode<int>* root);
TreeNode<int>* maxDataNode(TreeNode<int>* root);
int height(TreeNode<int*> root);
using namespace std;
int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);
    printLevelWise(root);
    cout<<countNodes(root)<<endl;
    cout<<sumOfNodes(root);
    cout<<maxDataNode(root);
}
int height(TreeNode<int>* root){
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        int childHeight = height(root->children[i]);
        if(childHeight>ans){
            ans=childHeight;
        }
    }
    return ans;
}
TreeNode<int>* maxDataNode(TreeNode<int>* root){
    if(root==NULL){
        return root;
    }
    TreeNode<int> *max = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* temp = maxDataNode(root->children[i]);
        if(temp->data>max->data){
            max = temp;
        }
    }
    return max;
}
int sumOfNodes(TreeNode<int>* root){
    int sum=root->data;
     for(int i=0;i<root->children.size();i++){
         sum+=sumOfNodes(root->children[i]);
     }
     return sum;
}
int countNodes(TreeNode<int>* root){
   int count=1;
   for(int i=0;i<root->children.size();i++){
       count+=countNodes(root->children[i]);
   }
}
void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<":";
        for(int i=0;i<front->children.size();i++){
            if(i<(front->children.size())-1)
            {
                cout<<front->children[i]->data<<",";
            }
            else{
                cout<<front->children[i]->data;
                pendingNodes.push(front->children[i]);
            }
        }
        cout<<endl;
    }
}
TreeNode<int>* takeInputBetter(){
    int rootData;
    cout<<"Enter root Data:"<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cout<<"Enter no. of children of "<<front->data<<":";
        cin >> numChild;
        for(int i=0; i < numChild; i++){
            int childData;
            cout<<"Enter"<<i<<"th child of"<<front->data<<":";
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data:";
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter no. of Children:";
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printRoot(TreeNode<int> *root) {
    if(root==NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printRoot(root->children[i]);
    }
}

#include <iostream>
#include "Node.h"
using namespace std;
Node *takeInput2(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        //Maintaining tail pointer reduces the complexity as we do not need to traverse whole LL.
        else{
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

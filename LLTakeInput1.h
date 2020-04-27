#include <iostream>
#include "Node.h"
using namespace std;
Node *takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    while(data!=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
        }
        else{
            Node *temp=head;
            //It is done as we are not maintaining tail pointer for entering teh next value.
            //Complexly we are traversing whole LL to insert a data.
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
}

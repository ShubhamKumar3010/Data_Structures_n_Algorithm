#include <iostream>
#include "LLTakeInput2.h"

void findIthValue(Node *pNode, int i);
int length(Node *head);
void insertNode(Node *head,int position,int data);
Node* deleteNode(Node *head, int position);
int recursiveLength(Node *head);
Node* insertNodeRecursive(Node *head,int position,int data);
Node* deleteNodeRecursive(Node *head,int position);
using namespace std;
void  print(Node *n){
    Node *temp=n;
    while (temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
int main() {
    Node n1(10);
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;
    n4.next=&n5;
    print(&n1);
    //It will take input in Order of n^2 as there is nested while loop.
        //Node* head=takeInput();
        //print(head);
        // It will take input in Order of n as there is no nested while loop.
    Node* head2=takeInput2();
    print(head2);
    Node* head=insertNodeRecursive(head2,3,10);
    print(head);
    deleteNodeRecursive(head,2);
    print(head);
}
Node* deleteNodeRecursive(Node *head,int position){
    Node* temp=head;
    if(head==NULL){
        return temp;
    }
    if(position==0){
        Node* temp1=temp->next;
        delete temp;
        return temp1;
    }
    Node *attach =deleteNodeRecursive(head->next,position-1);
    head->next = attach;
    return head;
}
Node* insertNodeRecursive(Node *head,int position,int data){
    Node *temp=head;
    if(head==NULL){
        return temp;
    }
    if(position==0){
        Node *newNode = new Node(data);
        newNode->next = temp;
        temp=newNode;
        return temp;
    }
    Node *attach =insertNodeRecursive(head->next,position-1,data);
    head->next=attach;
    return head;
}
Node* deleteNode(Node *head, int position) {
    Node* temp=head;
    int count=0;
    if(position==0){
        Node* temp1=head->next;
        delete head;
        return temp1;
    }
    while (temp!=NULL && count<position){
        count++;
        temp=temp->next;
    }
    while(temp!=NULL && temp->next!=NULL){
        Node* a=temp->next;
        Node* b=a->next;
        temp->next=b;
        delete a;
        return head;
    }
    return head;
}

void insertNode(Node *head,int position,int data){
    Node* newNode= new Node(data);
    if(position==0){
        newNode->next=head;
        head=newNode;
    }
        Node* temp=head;
        int count=0;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL) {
            Node *a = temp->next;
            temp->next = newNode;
            newNode->next = a;
        }
}
void findIthValue(Node *pNode, int i) {
    Node *temp=pNode;
    int count=0;
    while(temp!=NULL){
        if(count==i-1){
            cout<<temp->data<<endl;
            return;
        }
        else{
            temp=temp->next;
            count++;
        }
    }
}
int length(Node *head){
    Node *temp=head;
    int t=0;
    while(temp!=NULL){
        t++;
        temp=temp->next;
    }
    return t;
}
int recursiveLength(Node *head){
   if(head->next==NULL){
       return 1;
   }
   Node *temp=head->next;
   return recursiveLength(temp)+1;
}
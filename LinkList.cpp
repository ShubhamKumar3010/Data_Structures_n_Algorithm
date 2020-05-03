 #include <iostream>
#include "LLTakeInput2.h"
void findIthValue(Node *pNode, int i);
int length(Node *head);
void insertNode(Node *head,int position,int data);
Node* deleteNode(Node *head, int position);
int recursiveLength(Node *head);
Node* insertNodeRecursive(Node *head,int position,int data);
Node* deleteNodeRecursive(Node *head,int position);
int indexOfSearchedElement(Node *head,int n);
Node* appendLL(Node* head,int position);
Node* eliminateDuplicate(Node* head);
void printReverseLL(Node* head);
void printReverseLlRecursive(Node* head);
bool checkPalindromeLL(Node* head);
Node* midPointOfLL(Node* head);
Node* mergeTwoSortedLL(Node* head1,Node* head2);
Node* mergeSort(Node* head);
bool has_cycle(Node* head);
Node* reveresLL(Node* head);
Node* reverseLL_Recursive(Node* head);
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
    n4.next=&n1;
//    print(&n1);
        //It will take input in Order of n^2 as there is nested while loop.
        //Node* head=takeInput()
        //It will take input in Order of n as there is no nested while loop.
        Node* head = takeInput2();
        Node* head1 = reverseLL_Recursive(head);
        print(head1);
}
 Node* reverseLL_Recursive(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=reverseLL_Recursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}
 Node* reveresLL(Node* head){
    if(head==NULL){
        return head;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
 bool has_cycle(Node* head) {
     if(head==NULL || head->next==NULL){
         return 0;
     }
     Node* slow = head;
     Node* fast = head->next;
     while(fast!=NULL && fast->next!=NULL && slow!=NULL){
         slow=slow->next;
         fast=fast->next->next;
         if(slow==fast){
             return 1;
         }
     }
     return 0;

 }
 Node* mergeSort(Node* head){
    //merge sort is the concept which works on divide and conquer
    Node* temp=head;
    if(temp->next==NULL){
        return temp;
    }
    //We divide the LL with concept of midpoint Finder as slow pointer will be midpoint.
    Node* slow=temp;
    Node* fast=temp->next;
    while(fast!=NULL){
        if(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        else{
            fast=fast->next;
        }
    }
    Node* right=mergeSort(slow->next);
    slow->next=NULL;
    Node* left=mergeSort(temp);
    Node* result=mergeTwoSortedLL(left,right);
    return result;
}
 Node* mergeTwoSortedLL(Node* head1,Node* head2){
    Node* newH=NULL;
    Node* newT=NULL;
    if(head1->data<head2->data){
        newH=head1;
        newT=head1;
        head1=head1->next;
    }
    else{
        newH=head2;
        newT=head2;
        head2=head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            newT->next=head1;
            newT=newT->next;
            head1=head1->next;
        }
        else{
            newT->next=head2;
            newT=newT->next;
            head2=head2->next;
        }
    }
    if(head2!=NULL){
        newT->next=head2;
    }else{
        newT->next=head1;
    }
    return newH;
}
 Node* midPointOfLL(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        if(fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        else{
            fast=fast->next;
        }
    }
    return slow;
}
 bool checkPalindromeLL(Node* head){
    Node* temp=head;
    int size=recursiveLength(temp);
    int *arr = new int[size];
    int i=0;
    while (temp!=NULL){
        arr[i++]=temp->data;
        temp=temp->next;
    }
    for(int j=0;j<size;j++){
        if(arr[j]!=arr[size-1-j]){
            delete []arr;
            return false;
        }
    }
    delete []arr;
    return true;
}
 void printReverseLlRecursive(Node* head){
    if(head==NULL){
        return;
    }
    printReverseLlRecursive(head->next);
    cout<<head->data<<" ";
}
 void printReverseLL(Node* head){
    Node* temp=head;
    int size=recursiveLength(temp);
    int *arr = new int[size];
    int i=0;
    while(temp!=NULL){
        arr[i++]=temp->data;
        temp=temp->next;
    }
    for(int j=size-1;j>-1;j--){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    delete arr;
}
Node* eliminateDuplicate(Node* head){
    Node* forward=head->next;
    Node* backward=head;
    while(forward!=NULL){
        if(backward->data == forward->data){
            backward->next=forward->next;
            forward=forward->next;
        }
        else{
            forward=forward->next;
            backward=backward->next;
        }
    }
    return head;
}
Node* appendLL(Node* head,int position){
    Node* temp=head;
    Node* newHead=head;
    Node* connect=head;
    Node* tail=head;
    int length=recursiveLength(head);
    int count=0;
    while(count<position-1 && count<length){
        newHead=newHead->next;
        count++;
    }
    while(connect->next!=NULL){
        connect=connect->next;
    }
    while(tail->next!=newHead){
        tail=tail->next;
    }
    tail->next=NULL;
    connect->next=temp;
    head=newHead;
    return head;
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
int indexOfSearchedElement(Node *head,int n){
    Node* temp = head;
    int count=0;
    while(temp!=NULL){
        if(temp->data==n){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
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
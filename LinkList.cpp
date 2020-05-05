#include <iostream>
#include "LLTakeInput2.h"
class Pair {
public:
     Node *head;
     Node *tail;
 };
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
Node* reveresLL(Node* head); //This works on O(n)
Node* reverseLL_Recursive(Node* head);
Pair reverse2LL(Node* head);
int indexOfSearchedElementRecursive(Node *head,int n);
Node* arrangeLL_OddToEvenValues(Node* head);
void skipMDeleteN(Node* head, int m, int n); //i.e m is the step after which n node is to be deleted.
Node* swap2Node(Node* head,int i,int j);
Node* kReverse(Node* head,int k);
int findMergeNode(Node* head1,Node* head2);
//We can use the concept of Doubly Link List also its has advantages over singly list as it contains address of
//previous as well as next nodes.
//Moreover it has advantages over Singly LinkList but one disadvantage is its memory consumption int takes 4 bytes
//and Pointer is of 8 bytes total consumption in SinglyLL is 12 Bytes but as doublyLL has 2 pointers as next and previous it takes 20 bytes.
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
        Node* head1=kReverse(head, 3);
        print(head1);
}
int findMergeNode(Node* head1,Node* head2){
    Node* temp=head2;
    int a;
    while(head1!= NULL){
        while(head2!= NULL){
            if(head1==head2){
                a=head1->data;
                return a;
            }
            else{
                head2=head2->next;
            }
        }
        head2=temp;
        head1=head1->next;
    }
    return a;
}
Node* kReverse(Node* head,int k){
    Node* current=head;
    Node* prev=NULL;
    Node* next=NULL;
    int count=0;
    while(current!=NULL && count<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL){
        head->next=kReverse(next,k);
    }
    return prev;
}
Node* swap2Node(Node* head,int i,int j){
    Node* temp=head;
    int count=0;
    while(count!=min(i,j)){
        count++;
        temp=temp->next;
    }
    Node* firstNode=temp;
    while(count!=max(i,j)){
        count++;
        temp=temp->next;
    }
    Node* secondNode=temp;
    swap(firstNode->data,secondNode->data);
    return head;
}
void skipMDeleteN(Node* head, int m, int n) {
    Node *curr = head, *t;
    int count;
    while (curr) {
        // Skip M nodes
        for (count = 1; count < m && curr != NULL; count++) {
            curr = curr->next;
        }
        // If we reached end of list, then return
        if (curr == NULL) {
            return;
        }
        // Start from next node and delete N nodes
        t = curr->next;
        for (count = 1; count <= n && t != NULL; count++) {
            Node *temp = t;
            t = t->next;
            free(temp);
        }
        // Link the previous list with remaining nodes
        curr->next = t;
        // Set current pointer for next iteration
        curr = t;
    }
}
 Node* arrangeLL_OddToEvenValues(Node* head){
    if(head==NULL && head->next==NULL){
        return head;
    }
    Node* oddH = NULL;
    Node* oddT = NULL;
    Node* evenH = NULL;
    Node* evenT = NULL;
    while (head!=NULL){
        if(head->data%2==0){
            //It data is even.
            if(evenH==NULL){
                evenH=head;
                evenT=head;
            }
            else{
                evenT->next=head;
                evenT=head;
            }
        }
        else{
            //If data is odd.
            if(oddH==NULL){
                oddH=head;
                oddT=head;
            }
            else{
                oddT->next=head;
                oddT=head;
            }
        }
        head=head->next;
    }
    if(evenH==NULL){
        oddT->next=NULL;
        return oddH;
    }
    else if(oddH==NULL){
        evenT->next=NULL;
        return evenH;
    }else{
        oddT->next=evenH;
        evenT->next=NULL;
        return oddH;
    }
}
 int indexOfSearchedElementRecursive(Node *head,int n){
    if(head==NULL){
        return -1;
    }
    if(head->data==n){
        return 0;
    }
    int ans=indexOfSearchedElement(head->next,n);
    if(ans!=0) {
        return ans + 1;
    }
    else{
        return ans;
    }
}
 Pair reverse2LL(Node* head){
    //Whenever we need to return multiple parameters through a function we need to create a class and return object of that class.
    if(head==NULL && head->next==NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns=reverse2LL(head->next);
    smallAns.tail->next = head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=smallAns.tail;
    return ans;
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
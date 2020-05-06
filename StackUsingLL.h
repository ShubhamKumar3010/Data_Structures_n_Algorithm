#include <iostream>
template<typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this->data=data;
        next=NULL;
    };
};
template<typename T>
class StackUsingLL {
    Node<T>* head;
    int size; //No. of element in stack.
public:
    StackUsingLL(){
        head=NULL;
        size=0;
    }
    void print(){
        if(size==0){
            cout<<"Nothing To print"<<endl;
        } else {
            while(head!=NULL){
                cout<<head->data<<" ";
                head=head->next;
            }
        }
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void push(T element){
            Node<T> *newN = new Node<T>(element);
            newN->next = head;
            head = newN;
        size++;
    }
    T pop(){
        if(size==0){
            return 0;
        }
        T ans=head->data;
        Node<T>* temp =head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        size--;
    return ans;
    }
    T top(){
        if(size==0){
            return 0;
        }
        return head->data;
    }
};

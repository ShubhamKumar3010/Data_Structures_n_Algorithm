#include <iostream>
using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex,capacity;
public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex=0;
        capacity=totalSize;
    }
    StackUsingArray(){
        data = new int[4];
        nextIndex=0;
        capacity=4;
    }
    void print(){
        if(nextIndex==0){
            cout<<"Nothing To print"<<endl;
        } else {
            for (int i = 0; i < nextIndex; i++) {
                cout << "At index " << i << ":" << data[i] << endl;
            }
        }
    }
    //Dynamic Stack
    void pushDynamic(int element){
        if(nextIndex==capacity){
            int *newData = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            capacity*2;
            delete [] data;
            data = newData;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    void push(int element){
        if(nextIndex==capacity){
            cout<<"Stack is FULL"<<endl;
        }
        else{
            data[nextIndex]=element;
            nextIndex++;
        }
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        if(nextIndex==0){
            return true;
        }
        else{
            return false;
        }
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT16_MIN;
        }
        else{
            nextIndex--;
            return data[nextIndex];
        }
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT16_MIN;
        }
        else{
            return data[nextIndex-1];
        }
    }
};


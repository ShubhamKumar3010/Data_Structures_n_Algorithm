#include <iostream>
using namespace std;
template<typename T>
class StackUsingTemplate {
    T *data;
    int nextIndex;
    int capacity;
public:
    StackUsingTemplate(){
        data = new T[4];
        nextIndex=0;
        capacity=4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex==0;
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
    void push(T element){
        if(nextIndex==capacity){
            T *newData = new T[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newData;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return INT16_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top(){
        if(isEmpty()){
            cout<<"Stack is Empty."<<endl;
            return INT16_MIN;
        }
        return data[nextIndex-1];
    }
};

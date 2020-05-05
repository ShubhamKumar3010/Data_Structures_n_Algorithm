#include <iostream>
#include "StackUsingArray.h"
using namespace std;
int main(){
    StackUsingArray s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pushDynamic(6);
    s.print();
    cout<<"Pop Out Element:"<<s.pop()<<endl;
    cout<<"Top Element:"<<s.top()<<endl;
    cout<<"Stack empty or Not:"<<s.isEmpty()<<endl;
    cout<<"Stack size:"<<s.size()<<endl;
    s.print();

}
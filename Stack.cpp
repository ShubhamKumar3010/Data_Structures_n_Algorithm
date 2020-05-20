#include <iostream>
#include <stack>
#include <cstring>
#include "StackUsingArray.h"
#include "StackUsingTemplate.h"
#include "StackUsingLL.h"
using namespace std;
bool checkBalanced(char *exp);
void reverseStack(stack<int> &input,stack<int> &extra);
bool checkRedundantBracket(char *input);
int main(){
    //Implementation of Stack Using Array
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
    //Implementation of Stack Using Template
    StackUsingTemplate<double> s1;
    s1.push(3.3);
    s1.push(3.4);
    s1.push(3.5);
    s1.push(3.6);
    s1.print();
    //Implementation of Stack Using LinkList
    StackUsingLL<int> s2;
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    cout<<"Pop Out Element:"<<s2.pop()<<endl;
    cout<<"Top Element:"<<s2.top()<<endl;
    cout<<"Stack empty or Not:"<<s2.isEmpty()<<endl;
    cout<<"Stack size:"<<s2.getSize()<<endl;
    s2.print();
    //Using Inbuilt Stack
    stack<int> s3;
    s3.push(1);
    s3.push(2);
    s3.push(3);
    s3.push(4);
    s3.push(5);
    s3.pop();
    cout<<"Top Element:"<<s3.top()<<endl;
    cout<<"Stack empty or Not:"<<s3.empty()<<endl;
    cout<<"Stack size:"<<s3.size()<<endl;

    //Check Balanced Parenthesis.
    char *a="{a+[b+(c+d)]+(e+f)}";
    cout<<"Equation is balanced or not:"<<checkBalanced(a)<<endl;
    stack<int> s4;
    reverseStack(s3,s4);
    cout<<s3.top();
}
bool checkRedundantBracket(char *input){
}
void reverseStack(stack<int> &input,stack<int> &extra){
    if(input.empty()){
        return;
    }
    int temp = input.top();
    input.pop();
    reverseStack(input,extra);
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    input.push(temp);
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
    return;
}
bool checkBalanced(char *exp){
    stack<char> s;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='{' || exp[i]=='(' || exp[i]=='['){
            s.push(exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==')' || exp[i]==']'){
            if(s.empty()){
                return false;
            }
            else if((exp[i]=='}' && s.top()=='{')||
                    (exp[i]==']' && s.top()=='[')||
                    (exp[i]==')' && s.top()=='(')){
                     s.pop();
            } else{
                return false;
            }
        }
    }
    return s.empty();
}
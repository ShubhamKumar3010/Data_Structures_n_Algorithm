#include <iostream>
#include "pair.h"
#include "pair1.h"
#include "pair2.h"
using namespace std;
int main(){
    Pair<int> p1;
    p1.setX(1);
    p1.setY(2);
    Pair<double> p2;
    p2.setX(2.1);
    p2.setY(3.14);
    cout<<"Pair p1(pair.h) Int type X and Y:"<<p1.getX()<<" "<<p1.getY()<<endl;
    cout<<"Pair p2(pair.h) Double type X and Y:"<<p2.getX()<<" "<<p2.getY()<<endl;
    pair1<int,double> p3;
    p3.setX(2);
    p3.setY(3.3);
    cout<<"Pair p3(pair1.h) Int type X:"<<p3.getX()<<endl;
    cout<<"Pair p3(pair1.h) Double type Y:"<<p3.getY()<<endl;
    pair2<int,double,char> p4;
    p4.setX(2);
    p4.setY(3.33);
    //p4.setZ(S);
    cout<<"Pair p4(pair2.h) Int type X:"<<p4.getX()<<endl;
    cout<<"Pair p4(pair2.h) Double type Y:"<<p4.getY()<<endl;
    cout<<"Pair p4(pair2.h) Character type Z:"<<p4.getZ()<<endl;
}
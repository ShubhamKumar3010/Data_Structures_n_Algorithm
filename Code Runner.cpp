#include <iostream>
#include <vector>
using namespace std;
int findComplement(int num);
int main(){
    findComplement(20);
}
int findComplement(int num) {
    vector<int> binaryNum;
    while (num > 0) {
        binaryNum.push_back(num % 2);
        num = num / 2;
    }
    for (int i = 0; i < binaryNum.size(); i++) {
        if (binaryNum[i] == 0) {
            binaryNum[i] = 1;
        } else {
            binaryNum[i] = 0;
        }
    }
    int n=1;
    int sum=0;
    for(int j=binaryNum.size()-1;j>-1;j--){
        if(binaryNum[j]==1){
            sum=sum+n;
        }
        n*=2;
    }
    cout<<sum;
}

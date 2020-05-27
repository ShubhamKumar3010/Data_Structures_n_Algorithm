#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findComplement(int num);
vector<int> twoSum(vector<int>& nums,int target);
bool kLengthApart(vector<int>& nums, int k);
int isPrefixOfWord(string sentence,string searchWord);
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);
vector<string> buildArray(vector<int>& target, int n);
int main(){
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<string> out = buildArray(v,4);
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<endl;
    }
    return 0;
}
//Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.
//Build the target array using the following operations:
//Push: Read a new element from the beginning list, and push it in the array.
//Pop: delete the last element of the array.
//If the target array is already built, stop reading more elements.
//You are guaranteed that the target array is strictly increasing, only containing numbers between 1 to n inclusive.
//Return the operations to build the target array.
//You are guaranteed that the answer is unique.
//Input: target = [1,3], n = 3
//Output: ["Push","Push","Pop","Push"]
//Input: target = [1,2,3], n = 3
//Output: ["Push","Push","Push"]
vector<string> buildArray(vector<int>& target, int n) {
    int j=0;
    vector<int> outInt;
    vector<string> outStr;
    for(int i=1;i<=n;i++){
        if(target[j]==i){
            outInt.push_back(i);
            outStr.push_back("Push");
            j++;
        }else{
            outStr.push_back("Push");
            outStr.push_back("Pop");
        }
        if(outInt.size() == target.size()){
            for(int i=0;i<outInt.size();i++){
                if(outInt[i]==target[i]){
                    continue;
                }else{
                    break;
                }
            }return outStr;
        }
    }
}
//Given two integer arrays startTime and endTime and given an integer queryTime.
//
//The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].
//
//Return the number of students doing their homework at time queryTime. More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.
//Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
//Output: 1
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int i=0;
    int count=0;
    while(i!=startTime.size()) {
        if(startTime[i]==queryTime){
            count++;
        }else {
            for (int j = startTime[i]; j <= endTime[i]; j++) {
                if (queryTime == j) {
                    count++;
                }
            }
        }
        i++;
    }
    return count;
}
//Given a sentence that consists of some words separated by a single space, and a searchWord.
//You have to check if searchWord is a prefix of any word in sentence.
//Return the index of the word in sentence where searchWord is a prefix of this word (1-indexed).
//Input: sentence = "i love eating burger", searchWord = "burg"
//Output: 4
int isPrefixOfWord(string sentence, string searchWord) {
    int i=0;
    int flag=0;
    int count=0;
    while(i<sentence.length()){
        if(sentence[i]==searchWord[0]){
            for(int k=0;k<searchWord.size();k++){
                if(sentence[i]==searchWord[k]){
                    i++;
                    count++;
                }
            }
            if(count==searchWord.size()){
                return flag+1;
            }else{
                count=0;
            }
        }else{
            while (sentence[i]!=' '){
                if(i==sentence.length()){
                    return -1;
                }
                i++;
            }
            flag++;
            i++;
        }
    }
    return -1;
}
// To check the length bw two 1's are equal and greater than k if so return true else return false.
//Input: [0,1,0,1] & k=1 Output: True
bool kLengthApart(vector<int>& nums, int k) {
    vector<int> v;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            v.push_back(i);
        }
    }
    for(int i=0;i<v.size();i++){
        if((v[i+1]-v[i]-1)>=k){
            if(i+1==v.size()-1){
                break;
            }
            continue;
        }else{
            return false;
        }
    }
    return true;
}
//to find the index of two numbers sum which equals target.
vector<int> twoSum(vector<int>& nums,int target){
    vector<int> output;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                output.push_back(i);
                output.push_back(j);
                break;
            }
        }
    }
    return output;
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
    return 0;
}

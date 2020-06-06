#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int findComplement(int num);
vector<int> twoSum(vector<int>& nums,int target);
bool kLengthApart(vector<int>& nums, int k);
int isPrefixOfWord(string sentence,string searchWord);
int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime);
vector<string> buildArray(vector<int>& target, int n);
int searchInsert(vector<int>& nums, int target);
string destCity(vector<vector<string>>& paths);
int lastStoneWeight(vector<int>& stones);
int findLucky(vector<int>& arr);
int maxPower(string s);
string addBinary(string a, string b);
int addDigits(int num);
string addStrings(string num1, string num2);
vector<int> addToArrayForm(vector<int>& A, int K);
int findContentChildren(vector<int>& g, vector<int>& s);
int arrangeCoins(int n);
int main(){
  vector<int> g {1,2,3};
  vector<int> s {3};
  int a = findContentChildren(g,s);
}
//Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj.
// If sj >= gi, we can assign the cookie j to the child i, and the child i will be content.
// Your goal is to maximize the number of your content children and output the maximum number.
//Input: [1,2,3], [1,1]
//Output: 1
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[j]>=g[i] && s[j]>0){
                    count++;
                    s[j]=-1;
                    break;
                }
            }
        }
        return count;
    }
//You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
//Given n, find the total number of full staircase rows that can be formed.
//n is a non-negative integer and fits within the range of a 32-bit signed integer.
int arrangeCoins(int n) {
    if(n==1){
        return 1;
    }
    int i=0;
    int count=1;
    while(n>0){
        n = n - count;
        if(n>0){
            i++;
            count++;
        }else if(n==0){
            return i+1;
        }else{
            return i;
        }
    }
    return 0;
}
//For a non-negative integer X, the array-form of X is an array of its digits in left to right order.  For example, if X = 1231, then the array form is [1,2,3,1].
//Given the array-form A of a non-negative integer X, return the array-form of the integer X+K.
//Input: A = [1,2,0,0], K = 34
//Output: [1,2,3,4]
//Explanation: 1200 + 34 = 1234
vector<int> addToArrayForm(vector<int>& A, int K) {
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum=sum*10+A[i];
    }
    int v = sum + K;
    vector<int> out;
    while(v>0){
        int r = v%10;
        out.push_back(r);
        v=v/10;
    }
    reverse(out.begin(),out.end());
    return out;
}
//Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
//Example:
//Input: 38
//Output: 2
//Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
//Since 2 has only one digit, return it.
int addDigits(int num) {
    if(num<10 && num>=0){
        return num;
    }

}
string addBinary(string a, string b) {
    string result="";
    int s=0;
    int i = a.size()-1,j = b.size()-1;
    while (i>=0 || j>=0 || s == 1){
        s+=((i >= 0) ? a[i] - '0' : 0);
        s+=((j >= 0) ? b[j] - '0' : 0);

        result = char (s%2+'0') + result ;

        s/=2;
        i--;
        j--;
    }
    return result;
}
//Given a string s, the power of the string is the maximum length of a non-empty substring that contains only one unique character.
//Return the power of the string.
//Input: s = "leetcode"
//Output: 2
int maxPower(string s) {
        int count,max=1;
        for(int i=0;i<s.length();i++){
            count = 1;
            while(s[i] == s[i+1] && i<s.length()){
                count++;
                i++;
            }
            max = std::max(max,count);
        }
        return max;
}
int lastStoneWeight(vector<int>& stones) {
    if(stones.size()==0){
        return 0;
    }
    int x,y;
    while(stones.size()>0){
        if(stones.size()==0){
            return 0;
        }
        sort(stones.begin(),stones.end());
        x = stones.back();
        stones.pop_back();
        y = stones.back();
        stones.pop_back();
        if(x!=y){
            x = x - y;
            stones.push_back(x);
        }
    }
    return stones[0];
}
//Given an array of integers arr, a lucky integer is an integer which has a frequency in the array equal to its value.
//Return a lucky integer in the array. If there are multiple lucky integers return the largest of them. If there is no lucky integer return -1.
int findLucky(vector<int>& arr) {
    vector<int> out;
    for(int i=0;i<arr.size();i++){
        int count=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(arr[i]==count){
            out.push_back(arr[i]);
        }
    }
    int max;
    if(out.size()>0){
         max=out[0];
        for(int i=0;i<out.size();i++){
            if(max<out[i]){
                max=out[i];
            }
        }
    }else{
        return -1;
    }
    return max;
}

//You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi.
// Return the destination city, that is, the city without any path outgoing to another city.
//It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
string destCity(vector<vector<string>>& paths) {
    vector<string> v;
    v.push_back(paths[0][1]);
    v.push_back(paths[1][1]);
    v.push_back(paths[2][1]);
        int i=0;
        while(i<3){
            int count=0;
            for(int j=0;j<paths.size();j++){
                if(v[i]!=paths[j][0]) {
                    count++;
                }
            }
            if(count==paths.size()){
                return v[i];
            }
            i++;
        }
}
//Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//You may assume no duplicates in the array.
//Input: [1,3,5,6], 5
//Output: 2
int searchInsert(vector<int>& nums, int target) {
    int low=0,high=nums.size()-1;
//  As in question it is for sorted array so the best thing comes here is binary Search;
    while(low<=high){
        int mid=(low+high+1)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
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

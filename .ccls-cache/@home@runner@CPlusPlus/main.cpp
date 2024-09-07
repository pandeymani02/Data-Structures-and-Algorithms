#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{  
  public:
    void insertArray(vector<int>&arr,int temp){
      if(arr.size()==0 || arr[arr.size()-1]<=temp){
        arr.push_back(temp);
        return;
      }
      int val=arr[arr.size()-1];
      arr.pop_back();
      insertArray(arr,temp);
      arr.push_back(val);
    }
    void sortArray(vector<int>& arr){
      if(arr.size()==0||arr.size()==1)
        return;

      int temp=arr[arr.size()-1];
      arr.pop_back();
      sortArray(arr);

      insertArray(arr,temp);
    }
    void printArray(vector<int>arr){
      for(auto it:arr){
        cout<<it<<":>";
      }
      cout<<endl;
    }
};
int main() {
  Solution obj;
  vector<int>arr={2,5,1,0,3,4};
  obj.sortArray(arr);
  obj.printArray(arr);
}
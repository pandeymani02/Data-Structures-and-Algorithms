#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    void f(string curr, int maxLen, bool flag, vector<string>&ans){
        if(curr.length() == maxLen){
            ans.push_back(curr);
            return;//
        }
        f(curr + '0', maxLen, 1, ans);
        if(flag){
            f(curr + '1', maxLen, 0, ans);
        }
    }
public:
    vector<string> generateBinaryStrings(int num){
        vector<string>ans;
        bool flag = 1;
        string s = "";
        f(s, num, flag, ans);
        return ans;
    }
};
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }

        cout<<endl;
    }
}
#include <stack>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse the stack
    void Reverse(stack<int> &St) {
        if (St.empty() || St.size() == 1)
            return;

        // Step 1: Pop the top element
        int top = St.top();
        St.pop();

        // Step 2: Recursively reverse the remaining stack
        Reverse(St);

        // Step 3: Insert the popped element at the bottom
        insertAtBottom(St, top);
    }

private:
    // Helper function to insert an element at the bottom of the stack
    void insertAtBottom(stack<int> &St, int element) {
        if (St.empty()) {
            St.push(element);
            return;
        }

        // Step 1: Pop the top element
        int top = St.top();
        St.pop();

        // Step 2: Recursively insert the element at the bottom
        insertAtBottom(St, element);

        // Step 3: Push the popped element back on the stack
        St.push(top);
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
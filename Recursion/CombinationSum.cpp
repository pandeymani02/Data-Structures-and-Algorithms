#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
  void solve(vector<vector<int>> &ans, int ind, vector<int> &candidates,
             int target, int sum, vector<int> &build) {
    if (sum == target) {
      ans.push_back(build); // Add current combination to the result
      return;
    }
    if (ind >= candidates.size() || sum > target)
      return; // Stop if index is out of bounds or sum exceeds target

    // Include the current candidate
    build.push_back(candidates[ind]);
    solve(ans, ind, candidates, target, sum + candidates[ind],
          build); // Recursive call with the same index (ind)

    // Backtrack
    build.pop_back(); // Use pop_back to remove the last added element

    // Exclude the current candidate and move to the next one
    solve(ans, ind + 1, candidates, target, sum,
          build); // Recursive call with the next index
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> build;
    solve(ans, 0, candidates, target, 0, build); // Start from index 0 and sum 0
    return ans;
  }
};


// int main() {
//     // Create an instance of the Solution class
//     Solution sol;

//     // Input the size of the candidates array
//     int n;
//     cout << "Enter the number of candidates: ";
//     cin >> n;

//     // Input the candidate numbers
//     vector<int> candidates(n);
//     cout << "Enter the candidate numbers: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> candidates[i];
//     }

//     // Input the target value
//     int target;
//     cout << "Enter the target value: ";
//     cin >> target;

//     // Call the combinationSum function and store the result
//     vector<vector<int>> result = sol.combinationSum(candidates, target);

//     // Print the result
//     cout << "Combinations that sum to target " << target << " are: " << endl;
//     for (const auto& combination : result) {
//         cout << "[ ";
//         for (int num : combination) {
//             cout << num << " ";
//         }
//         cout << "]" << endl;
//     }

//     return 0;
// }

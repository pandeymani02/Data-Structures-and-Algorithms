#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void solve(vector<vector<int>> &ans, vector<int> &nums, int ind,
             vector<int> &build) {
    // Base case: if the current index reaches the end of the nums array, add
    // the current subset to the answer
    if (ind >= nums.size()) {
      ans.push_back(build);
      return; // Return to stop further recursion
    }

    // Case 1: Include the current element
    build.push_back(nums[ind]);
    solve(ans, nums, ind + 1, build);

    // Case 2: Exclude the current element
    build.pop_back();
    solve(ans, nums, ind + 1, build);
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> build;
    solve(ans, nums, 0, build);
    return ans;
  }
};

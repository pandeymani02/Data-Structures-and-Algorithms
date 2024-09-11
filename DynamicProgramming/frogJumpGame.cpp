#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &height, int n, vector<int> &dp) {
  if (n == 0)
    return 0; // Base case: no energy needed at the first stone

  if (dp[n] != -1)
    return dp[n]; // Return cached result if already calculated

  // Jump from one step back
  int oneStep = solve(height, n - 1, dp) + abs(height[n] - height[n - 1]);

  // Jump from two steps back (only if n > 1)
  int twoStep = INT_MAX;
  if (n > 1) {
    twoStep = solve(height, n - 2, dp) + abs(height[n] - height[n - 2]);
  }

  // Store the minimum energy required to reach stone n
  dp[n] = min(oneStep, twoStep);

  return dp[n];
}

int minimumEnergy(vector<int> &height, int n) {
  vector<int> dp(n, -1);           // Initialize DP table with -1
  return solve(height, n - 1, dp); // Start from the last stone (n-1)
}

int main() {
  // Example input
  vector<int> height = {10, 20, 30, 10}; // Heights of the stones
  int n = height.size();                 // Number of stones

  // Call the function and print the result
  int result = minimumEnergy(height, n);
  cout << "Minimum energy required: " << result << endl;

  return 0;
}

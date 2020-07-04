class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 0), parent(nums.size(), 0), res;
    // max: size of largest subset
    // max_index: index of the begin of the largest subset
    int max = 0, max_index = 0;
    // dp calculate
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (int j = i; j < nums.size(); ++j) {
        if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          // parent[]: Position of the last divisible number
          parent[i] = j;
          if (max < dp[i]) {
            max = dp[i];
            max_index = i;
          }
        }
      }
    }
    for (int i = 0; i < max; ++i) {
      res.push_back(nums[max_index]);
      max_index = parent[max_index];
    }
    return res;
  }
};
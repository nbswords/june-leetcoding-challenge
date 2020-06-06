class Solution {
 public:
  // compare functions for sorting
  static bool cmp(vector<int> a, vector<int> b) {
    return abs(a[0] - a[1]) > abs(b[0] - b[1]);
  }
  int twoCitySchedCost(vector<vector<int>>& costs) {
    // n=size of costs array, a and b are half of array
    int n = costs.size();
    int a = n / 2;
    int b = n / 2;
    // sort costs array to find minimum cost
    sort(costs.begin(), costs.end(), cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // put the smaller cost into a and the other put into b
      if (b == 0 || (costs[i][0] <= costs[i][1] && a > 0)) {
        a--;
        ans += costs[i][0];
      } else {
        b--;
        ans += costs[i][1];
      }
    }
    return ans;
  }
};
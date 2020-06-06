class Solution {
 public:
  Solution(vector<int>& w) {
    // sum the weights
    sum = w;
    for (int i = 1; i < w.size(); ++i) {
      sum[i] = sum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    // The last value of sum array is the greatest weight
    int x = rand() % sum.back();
    int left = 0, right = sum.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (sum[mid] <= x)
        left = mid + 1;
      else
        right = mid;
    }
    return right;
  }

 private:
  vector<int> sum;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
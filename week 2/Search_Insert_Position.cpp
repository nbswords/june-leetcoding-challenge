class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      // search success
      if (target == nums[mid]) return mid;
      // search fail
      else if (target < nums[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
    return start;
  }
};
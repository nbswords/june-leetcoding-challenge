class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // a[] represent height and b[] represent the number of people in front of
    // this person who have a height >=  h sort array by height
    // if their height is equal then put the smaller b[] in front of bigger b[]
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    });

    vector<vector<int>> ans;
    for (auto i : people) {
      ans.insert(ans.begin() + i[1], i);
    }
    return ans;
  }
};
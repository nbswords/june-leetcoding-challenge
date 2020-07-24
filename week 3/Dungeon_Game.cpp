class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    const int row = dungeon.size();
    const int col = dungeon[0].size();
    //  min_bv = minium blood needed from (i,j) to princess
    vector<vector<int>> min_bv(row + 1, vector<int>(col + 1, INT_MAX));

    min_bv[row][col - 1] = min_bv[row - 1][col] = 1;
    for (int i = row - 1; i >= 0; i--)
      for (int j = col - 1; j >= 0; j--)
        min_bv[i][j] =
            max(1, min(min_bv[i][j + 1], min_bv[i + 1][j]) - dungeon[i][j]);
    return min_bv[0][0];
  }
};
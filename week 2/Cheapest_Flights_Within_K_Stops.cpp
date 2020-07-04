class Solution {
 public:
  // Bellman-Ford algorithm
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    constexpr int kInfCost = 1e9;
    // initialization of Bellman-Ford: dp[0:k+2][src]=0
    vector<vector<int>> dp(K + 2, vector<int>(n, kInfCost));
    dp[0][src] = 0;
    for (int i = 1; i <= K + 1; ++i) {
      dp[i][src] = 0;
      // dp[k][i] = min(dp[k-1][j] + price[j][i])
      for (const auto& p : flights)
        dp[i][p[1]] = min(dp[i][p[1]], dp[i - 1][p[0]] + p[2]);
    }
    // answer: dp[K+1][dst]
    return dp[K + 1][dst] >= kInfCost ? -1 : dp[K + 1][dst];
  }
};
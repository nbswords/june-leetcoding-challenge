// The hardest problem in this challenge
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string> > &tickets) {
    map<string, priority_queue<string, vector<string>, greater<string> > > mp;

    for (int i = 0; i < tickets.size(); i++) {
      string from = tickets[i][0];
      string to = tickets[i][1];
      if (mp.find(from) == mp.end()) {
        priority_queue<string, vector<string>, greater<string> > q;
        q.push(to);
        mp[from] = q;
      } else {
        mp[from].push(to);
      }
    }
    vector<string> res;
    string cur = "JFK";
    dfs(cur, mp, res);
    reverse(res.begin(), res.end());
    return res;
  }

  void dfs(string cur,
           map<string,
               priority_queue<string, vector<string>, greater<string> > > &mp,
           vector<string> &res) {
    while (mp[cur].size()) {
      string nxt = mp[cur].top();
      mp[cur].pop();
      dfs(nxt, mp, res);
    }
    res.push_back(cur);
  }
};
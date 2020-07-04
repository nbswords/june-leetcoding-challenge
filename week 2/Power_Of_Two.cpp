class Solution {
 public:
  bool isPowerOfTwo(int n) {
    if (n <= 0)
      return false;
    else if (n == 1)
      return true;
    while (n > 3) {
      if (n % 2 != 0) return false;
      n = int(n / 2);
    }
    return n % 2 == 0;
  }
};

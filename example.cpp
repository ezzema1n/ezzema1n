#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, S;
  cin >> S >> n;
  vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));
  dp[0][0] = 1;

  vector<int> wt(n + 1);
  for (int i; i <= n; ++i) {
    cin >> wt[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= S; ++j) {
      if (wt[i] <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i]]);
      }

      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  for (int i = S; i >= 0; --i) {
    if (dp[n][i] == 1) {
      cout << i << '\n';
      return 0;
    }
  }
  return 0;
}

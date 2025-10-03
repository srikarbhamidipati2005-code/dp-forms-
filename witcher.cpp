// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dungeon(n, vector<int>(m)), dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cin >> dungeon[i][j];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (i == n - 1 && j == m - 1)dp[i][j] = max(1, 1 - dungeon[i][j]);
            else dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }
    cout << dp[0][0] << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}

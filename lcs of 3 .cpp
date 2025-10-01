// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int dp[101][101][101], n1, n2, n3;
string s1, s2, s3;
void solve() {
    cin >> s1 >> s2 >> s3;
    memset(dp, 0, sizeof(dp));
    n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            for (int k = 1; k <= n3; k++) {
                auto &ans = dp[i][j][k];
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])ans = max(ans, 1 + dp[i - 1][j - 1][k - 1]);
                ans = max({ans, dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
            }
        }
    }
    cout << dp[n1][n2][n3] << endl;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


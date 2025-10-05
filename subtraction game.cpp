#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<int> dp;
int rec(int x) {
    if (x == 0)return 0;
    if (__builtin_popcount(x) == 1)return 1;
    auto &ans = dp[x];
    if (ans != -1)return ans;
    ans = 1;
    for (int j = 0; (1 << j) <= x; j++) {
        ans &= rec(x - (1 << j));
    }
    ans ^= 1;
    return ans;
}
void solve() {
    dp.assign((int)2e5 + 10, -1);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto ans = rec(n);
        if (ans)cout << "Vivek" << endl;
        else cout << "Abhishek" << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    solve();
    return 0;
}

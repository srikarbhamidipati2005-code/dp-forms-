#include<bits/stdc++.h>
using namespace std;
int n;
const int MAX_N = 10010;
int arr[n];
int dp[MAX_N];

int rec(int level) {
    // best LIS ending at level.
    // pruning
    if (level < 0) return 0;
    // base case
    if (level == 0) return 1;
    
    // cache check
    if (dp[level] != -1) return dp[level];
    
    // compute
    int ans = 1; // at least the element itself
    for (int prev_taken = 0; prev_taken < level; prev_taken++) {
        if (arr[prev_taken] < arr[level]) {
            ans = max(ans, 1 + rec(prev_taken));
        }
    }
    
    // save and return
    return dp[level] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    
    int best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, rec(i));
    }
    
    cout << best << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}

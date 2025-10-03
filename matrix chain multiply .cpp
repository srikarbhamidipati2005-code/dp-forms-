#include<bits/stdc++.h>
using namespace std;

int n;
int x[1010], y[1010]; // this both represent dimension of matrix.

int dp[1010][1010]; // memoization table (fast look-up).

int rec(int l, int r) {
	// pruning
	if(l>r) return 0;
	// basecase
	if(l==r) return 0; // if one matrix, then cost will be 0.
	// cache-check
	if(dp[l][r] != -1) {
		return dp[l][r];
	}
	// compute
	int ans = 1e9; // find min. cost
	for(int mid=l; mid<r; mid++) {
	    ans = min(ans, rec(l,mid) + rec(mid+1, r) + x[l]*y[mid]*y[r]);
	}
	// save & return
	return dp[l][r] = ans;
}


int main() {


	cin>>n;


	for(int i=1; i<=n; i++) {
		cin>>x[i]>>y[i];
	}


	memset(dp,-1,sizeof(dp));


	cout << rec(1,n) << endl;

}

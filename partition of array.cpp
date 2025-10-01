#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[1001]
int dp[1001][101]
int rec(int i,int x){
if(x<0){
return 1e9;
}
if(i==-1){
if(x==0){
return 0;
}
else{
return 1e9;
}
}
if(dp[i][x]!=-1){
return dp[i][x];
}
int ans = 1e9;
int min_seen = arr[i];
for(int j =i-1;j>=-1;j++){
ans = min(ans,rec(j,x-1))+min_seen;
min_seen = min(min_seen,arr[j]);
}
return dp[i][x] = ans;


}
oid solve() {
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    
   cout<<rec(n-1,k)<<endl;
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

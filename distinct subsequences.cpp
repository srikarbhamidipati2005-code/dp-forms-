#include <bits/stdc++.h>
using namespace std;


string s;
int n;


int main()
{
     cin>>s;
     n = s.size();
     int dp[n+1]; // till this point sum, why n+1, becoz dp[0]=1 for empty string
     int sum[n+1]; // total sum
     int last[26]; // for when last char was vis on which index, so we can delete all the before it
     dp[0] = 1;
     sum[0] = 1;
     memset(last,0,sizeof(last));
     for(int i=1; i<=n; i++){
          dp[i] = sum[i-1];
          if(last[s[i-1]-'a'] > 0){
               dp[i]-= sum[last[s[i-1]-'a']-1];
          }
          last[s[i-1]-'a'] = i;
          sum[i] = dp[i] + sum[i-1];
     }
     cout << sum[n-1] << endl;
}


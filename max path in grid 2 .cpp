/* This is the FORM: 02 Variant of the PROBLEM */

#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'


const int INF = 1e9;


int n, m;
int grid[1001][1001];


bool done[1001][1001];
int dp[1001][1001];


// rec: best max sum path ending at (row, col)
int rec(int row, int col)
{
    // pruning
    if(row <= 0 || col <= 0){
        // invalid
        return -INF;
    }
    
    // base case
    if(row == 1 && col == 1){
        // valid path
        return grid[row][col];
    }
    
    // cache check
    if(done[row][col]){
        return dp[row][col];
    }
    
    // transition
    int ans = max(rec(row - 1, col), rec(row, col - 1)) + grid[row][col];
    
    // save and return
    done[row][col] = 1;
    return dp[row][col] = ans;
    
}


void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>grid[i][j];
        }
    }
    memset(done, 0, sizeof(done));
    cout<<rec(n, m)<<endl;
}


signed main()
{
    ios
    solve();
}
/*
INPUT:
4 4
2 10 31 30
5 32 1 1
10 3 5 2
15 6 11 5

A﻿NSWER: 81 (2 -> 10 -> 31 -> 30 -> 1 -> 2 -> 5_
*/

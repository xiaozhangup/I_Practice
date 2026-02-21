// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1025
// 日期: 2026年02月21日

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
// #include <bits/stdc++.h>

using namespace std;

void slove();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n, k; cin >> n >> k;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            if (i >= j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            }
        }
    }

    cout << dp[n][k];
}
// 链接: https://vjudge.net/problem/HDU-1176
// 日期: 2026年02月18日

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

void slove(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    while (cin >> T) {
        if (T == 0) break;
        slove(T);
    }
}

#define ll long long

void slove(int n) {
    vector<vector<int>> dp(1e5 + 5, vector<int>(13, 0));
    int maxT = 0;
    for (int i = 0; i < n; i++) {
        int x, t; cin >> x >> t;
        dp[t][x]++;
        maxT = max(maxT, t);
    }

    for (int i = maxT; i >= 0; i--) {
        for (int j = 0; j <= 10; j++) {
            int left = (j == 0) ? 0 : dp[i + 1][j - 1];
            int mid = dp[i + 1][j];
            int right = (j == 10) ? 0 : dp[i + 1][j + 1];
            dp[i][j] += max(left, max(mid, right));
        }
    }


    cout << dp[0][5] << "\n";
}
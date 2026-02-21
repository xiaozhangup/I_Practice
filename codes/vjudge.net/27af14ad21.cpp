// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1877
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
    int n, beginLevel, maxLevel;
    cin >> n >> beginLevel >> maxLevel;

    vector<int> arrc(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> arrc[i];
    }

    vector<vector<bool>> dp(n + 5, vector<bool>(maxLevel + 5, false));
    dp[0][beginLevel] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxLevel; j++) {
            if (dp[i - 1][j]) {
                if (j + arrc[i] <= maxLevel) {
                    dp[i][j + arrc[i]] = true;
                }

                if (j - arrc[i] >= 0) {
                    dp[i][j - arrc[i]] = true;
                }
            }
        }
    }

    for (int j = maxLevel; j >= 0; j--) {
        if (dp[n][j]) {
            cout << j;
            return;
        }
    }

    cout << -1;
}
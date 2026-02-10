// 链接: https://ac.nowcoder.com/acm/contest/127702/E
// 日期: 2026年02月08日

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
    string s; cin >> s;
    int n = s.length();
    int ans = 1e5;

    for (int d = 0; d < 26; d++) {
        vector<vector<int>> dp(n, vector<int>(26, 1e5));
        for (int c = 0; c < 26; c++) {
            dp[0][c] = (c == (s[0] - 'a') ? 0 : 1);
        }

        for (int i = 1; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                int g = (c == (s[i] - 'a') ? 0 : 1);

                for (int p = 0; p < 26; p++) {
                    int dif = (c - p + 26) % 26;

                    if (dif == d || dif == (26 - d) % 26) {
                        dp[i][c] = min(dp[i][c], dp[i - 1][p] + g);
                    }
                }
            }
        }

        for (int c = 0; c < 26; c++) {
            ans = min(ans, dp[n - 1][c]);
        }
    }

    cout << ans;
}
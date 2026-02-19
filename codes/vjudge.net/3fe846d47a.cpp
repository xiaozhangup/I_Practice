// 链接: https://vjudge.net/problem/POJ-1458
// 日期: 2026年02月19日

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
    string s1, s2;
    while (cin >> s1 >> s2) {
        int l1 = s1.length();
        int l2 = s2.length();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }


        cout << dp[l1][l2] << "\n";
    }
}

#define ll long long

void slove() {

}
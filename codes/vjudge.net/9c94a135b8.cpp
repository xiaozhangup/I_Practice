// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1466
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

#define int long long

void slove() {
    int n; cin >> n;
    int sum = (1 + n) * n / 2;
    if (sum & 1) {
        cout << "0";
        return;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[target] / 2;
}
// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1192
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
#define MOD 100003

void slove() {
    int N, K; cin >> N >> K;

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int s = 1; s <= K; s++) {
            if (i - s >= 0) {
                dp[i] += dp[i - s];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[N];
}
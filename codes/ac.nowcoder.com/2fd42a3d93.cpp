// 链接: https://ac.nowcoder.com/acm/contest/127703/D
// 日期: 2026年02月15日

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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> dp(n + 2, 0);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int v = arr[i];
        dp[v] = max(dp[v - 1], dp[v + 1]) + 1;
        res = max(res, dp[v]);
    }

    cout << res << "\n";
}
// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-B3637
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

#define ll long long

void slove() {
    int n; cin >> n;
    vector<int> arr(n + 1);
    int res = 0;
    vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        
        for (int k = 1; k < i; k++) {
            if (arr[k] < arr[i]) {
                dp[i] = max(dp[i], dp[k] + 1);
                res = max(res, dp[i]);
            }
        }
    }

    cout << res;
}
// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P3131
// 日期: 2026年01月25日

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

    vector<int> first(7, -1);
    first[0] = 0;

    int ans = 0;
    int pref = 0;
    for (int i = 1; i <= n; i++) {
        ll a; cin >> a;
        pref = (pref + (int)(a % 7)) % 7;

        if (first[pref] == -1) first[pref] = i;
        else ans = max(ans, i - first[pref]);
    }

    cout << ans;
}
// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P4552
// 日期: 2026年01月29日

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
    vector<ll> arr(n + 1);

    ll zs = 0;
    ll fs = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 2; i <= n; i++) {
        ll diff = arr[i] - arr[i - 1];
        if (diff > 0) zs += diff;
        else fs -= diff;
    }

    cout << max(zs, fs) << "\n" << abs(zs - fs) + 1;

}
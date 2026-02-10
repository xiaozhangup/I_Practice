// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5745
// 日期: 2026年01月30日

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
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int l = 1, r = 1;
    int ansl = 1, ansr = n;
    int offset = m;

    ll sum = 0, ansm = 0;
    for (r = 1; r <= n; r++) {
        sum += arr[r];
        
        while (sum > m) {
            sum -= arr[l];
            l++;
        }

        if (offset > m - sum && m - sum >= 0) {
            ansl = l;
            ansr = r;
            ansm = sum;
            offset = m - sum;
        }
    }

    cout << ansl << " " << ansr << " " << ansm;
}
// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P8218
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
    int arr[n];
    for (int i = 0; i < n; i++) {
        int b; cin >> b;
        if (i == 0) {
            arr[0] = b;
        } else {
            arr[i] = b + arr[i - 1];
        }
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        if (l - 1 == -1) {
            cout << arr[r];
        } else {
            cout << arr[r] - arr[l - 1];
        }
        cout << "\n";
    }
}
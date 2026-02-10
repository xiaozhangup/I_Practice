// 链接: https://codeforces.com/contest/2185/problem/C
// 日期: 2026年01月26日

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
    int b0 = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a < 0) b0++;
        arr[i] = a;
    }

    sort(arr.begin(), arr.end());
    int maxl = 1;
    int lasti = arr[0];
    int curl = 1;
    for (int i = 1; i < n; i++) {
        if (lasti == arr[i] || lasti + 1 == arr[i]) {
            if (lasti + 1 == arr[i]) curl++;
        } else {
            maxl = max(maxl, curl);
            curl = 1;
        }
        lasti = arr[i];
    }
    maxl = max(maxl, curl);

    cout << maxl <<"\n";
}
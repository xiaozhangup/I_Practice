// 链接: https://ac.nowcoder.com/acm/contest/120561/E
// 日期: 2026年02月03日

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

#define int long long

void slove() {
    int n, k; cin >> n >> k;
    vector<int> v(n + 1);
    v[0] = k;
    int mmax = -2e18;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        v[i] = a;

        mmax = max(mmax, a + v[i - 1]);
    }

    mmax = max(mmax, v[0] + v[n]);
    cout << mmax << "\n";
}
// 链接: https://ac.nowcoder.com/acm/contest/120564/D
// 日期: 2026年02月09日

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
#include <numeric>
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
    int x, a, s; cin >> x >> a >> s;

    int minv = (1LL << 62);
    int a1 = -1, a2 = -1;

    int maxs = max(a, s);
    int mins = min(a, s);
    bool flip = (maxs == a);

    for (int c = 0; c <= x / maxs; c++) {
        if (c >= minv) break;

        int rem = x - c * maxs;
        if (rem % s != 0) continue;

        int rs = rem / s;
        int cur = max(c, rs);
        if (cur < minv) {
            minv = cur;
            a1 = c;
            a2 = rs;
        }
    }

    if (minv == (1LL << 62)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (flip) cout << a1 << " " << a2 << "\n";
        else cout << a2 << " " << a1 << "\n";
    }
}
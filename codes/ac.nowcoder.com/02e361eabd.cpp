// 链接: https://ac.nowcoder.com/acm/contest/120561/G
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

int rev(int x) {
    int res = 0;
    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

void slove() {
    int l, r; cin >> l >> r;
    int ans = rev(r);

    int p = 10;
    while (true) {
        int c = (r / p) * p - 1;
        if (c < l) break;

        ans = max(ans, rev(c));
        if (r / p == 0) break;
        
        p *= 10;
    }
    
    cout << ans << "\n";
}
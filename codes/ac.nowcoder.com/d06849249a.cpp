// 链接: https://ac.nowcoder.com/acm/contest/120563/J
// 日期: 2026年02月07日

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
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        bool done = false;
        for (int o = 0; o < 62; o++) {
            int s = 1LL << o;
            int e = 1LL << (o + 1);
            if ((x >= s) && (x < e)) {
                int ans = min(n, e - 1) - s + 1;

                cout << ans;
                done = true;
                break;
            }
        }

        if (!done) {
            cout << "1";
        }

        cout << "\n";
    }
}
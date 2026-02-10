// 链接: https://ac.nowcoder.com/acm/contest/120564/B
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

vector<int> u1s1(2e5 + 1, 0);

void slove() {
    int n, q, s; cin >> n >> q >> s;

    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        u1s1[i] = t + u1s1[i - 1];
    }
    for (int i = 1; i <= q; i++) {
        int x, y; cin >> x >> y;
        cout << u1s1[x - 1] + y - 1 + s << "\n";
    }

}
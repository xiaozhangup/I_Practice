// 链接: https://ac.nowcoder.com/acm/contest/120564/F
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
    cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int a, b; cin >> a >> b;
    int c0 = max(a, b);
    int c1 = min(a, b);
    bool flip = c0 != a;

    int amo = c1 + 1;
    int blak = c0 / amo;
    int rem = c0 % amo;

    for (int i = 0; i < amo; i++) {
        int blank = blak;

        if (i < rem) blank += 1;
        for (int j = 0; j < blank; j++) {
            cout << flip;
        }

        if (i < c1) {
            cout << !flip;
        }
    }

    cout << "\n";
}
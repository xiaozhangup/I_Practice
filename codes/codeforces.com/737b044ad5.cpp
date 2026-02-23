// 链接: https://codeforces.com/contest/2202/problem/A
// 日期: 2026年02月23日

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
    int x, y; cin >> x >> y;

    if (y < 0) {
        if (y * -1 * 4 > x) {
            cout << "NO\n";
            return;
        }

        int rem = x + y * 4;
        rem -= (rem / 6) * 6;
        if (rem % 3 == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    if (y > 0) {
        if (y * 2 > x) {
            cout << "NO\n";
            return;
        }

        int rem = x - y * 2;
        rem -= (rem / 6) * 6;
        if (rem % 3 == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    if (y == 0) {
        int rem = x;
        rem -= (rem / 6) * 6;
        if (rem % 3 == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    cout << "\n";
}
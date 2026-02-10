// 链接: https://ac.nowcoder.com/acm/contest/120563/A
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
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int x; cin >> x;

    for (int i = 1; i <= 100; i++) {
        if (i * (i + 1) == x) {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}
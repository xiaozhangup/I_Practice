// 链接: https://ac.nowcoder.com/acm/contest/120562/A
// 日期: 2026年02月05日

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
    int a, b, c; cin >> a >> b >> c;
    int a1 = abs(a - b);
    int a2 = abs(a - c);
    int a3 = abs(b - c);

    if (a1 <= 1 && a2 <= 1 && a3 <= 1) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}
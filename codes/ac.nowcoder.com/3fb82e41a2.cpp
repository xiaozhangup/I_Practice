// 链接: https://ac.nowcoder.com/acm/contest/120563/H
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
#include <iomanip>
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

#define int long long

void slove() {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;

    int rr = xa * yb - xb * ya;
    if (ya == yb) {
        if (abs(rr) == 4) {
            cout << 1.0;
        } else {
            cout << "no answer";
        }
    } else {
        double ans = (double)(4.0 - (double) rr) / (double) (ya - yb);
        printf("%.10f", ans);
    }
}
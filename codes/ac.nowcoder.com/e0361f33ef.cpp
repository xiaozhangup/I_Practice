// 链接: https://ac.nowcoder.com/acm/contest/127702/A
// 日期: 2026年02月08日

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
    char c;
    bool goway = false;
    while (cin >> c) {
        if (c != '0') {
            goway = true;
        }
        if (goway) cout << c;
    }
}
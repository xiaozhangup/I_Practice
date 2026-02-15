// 链接: https://ac.nowcoder.com/acm/contest/127703/B
// 日期: 2026年02月15日

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
    int n; cin >> n;
    string s; cin >> s;

    int su = 0;
    s += " ";
    for (char c : s) {
        if (c == '1') su++;
        else {
            if (su == 1) {
                cout << "NO\n";
                return;
            }
            su = 0;
        }
    }

    cout << "YES\n";
}
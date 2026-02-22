// 链接: https://ac.nowcoder.com/acm/contest/128672/B
// 日期: 2026年02月22日

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
    string s; cin >> s;
    for (char c : s) {
        if (c == '5' || c == '0') {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}
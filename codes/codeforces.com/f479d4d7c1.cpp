// 链接: https://codeforces.com/contest/2202/problem/B
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
    int n; cin >> n;
    string s; cin >> s;

    if (n & 1) { // ji (aabb) abababa
        if (s[0] == 'b') {
            cout << "NO\n";
            return;
        }
        for (int i = 1; i < n; i += 2) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    } else if (n > 1) { // ou (abbaabbaa) abababab
        for (int i = 0; i < n; i += 2) {
            if (s[i] != '?' && s[i + 1] != '?' && s[i] == s[i + 1]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}
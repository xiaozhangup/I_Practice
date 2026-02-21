// 链接: https://codeforces.com/contest/2192/problem/A
// 日期: 2026年02月21日

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

    int anymore = false;
    {
        char last = s[0];
        for (int i = 1; i < n; i++) {
            if (last == s[i]) {
                anymore = true;
                break;
            }
            last = s[i];
        }
    }

    if (anymore) {
        while (s[0] != s[n - 1]) {
            s = s.substr(1) + s[0];
        }
    }
    // cout << s;

    int sum = 1;
    char last = s[0];
    for (int i = 1; i < n; i++) {
        if (last != s[i]) sum++;
        last = s[i];
    }

    cout << sum << "\n";
}
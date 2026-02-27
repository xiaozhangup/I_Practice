// 链接: https://ac.nowcoder.com/acm/contest/128675/A
// 日期: 2026年02月27日

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
    string s; cin >> s;
    
    if (s.size() > 1) {
        if (s[0] == '/' && s[1] == '/') {
            cout << "null";
            return;
        }
    }

    bool lastIs = false;
    for (char c : s) {
        if (c == '/') {
            if (lastIs) return;
            else lastIs = true;
        }
        else {
            if (lastIs) cout << "/";
            cout << c;
            lastIs = false;
        }
    }

    if (lastIs) cout << "/";
}
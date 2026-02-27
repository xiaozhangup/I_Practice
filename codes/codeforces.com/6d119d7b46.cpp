// 链接: https://codeforces.com/contest/2200/problem/C
// 日期: 2026年02月27日

// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <cstdio>
// #include <cmath>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <unordered_set>
// #include <sstream>
#include <bits/stdc++.h>

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

    string st = "";
    for (char c : s) {
        if (!st.empty() && st.back() == c) {
            st.pop_back();
        } else {
            st.push_back(c);
        }
    }

    if (st.empty()) cout << "YES\n";
    else cout << "NO\n";
}
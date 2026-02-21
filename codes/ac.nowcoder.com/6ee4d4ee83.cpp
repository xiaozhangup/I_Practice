// 链接: https://ac.nowcoder.com/acm/contest/128962/M
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
#include <bits/stdc++.h>

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
    string s;
    cin >> s;

    int a = -1;
    int b = -1;

    int index = 0;
    for (char c : s) {
        index++;
        if (c == '9' && a == -1) a = index;
        if (c == '1' && b == -1) b = index;
    }

    if (a == -1 || b == -1) cout << "-1";
    else cout << a << " " << b;
}
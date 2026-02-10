// 链接: https://ac.nowcoder.com/acm/contest/120563/C
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
    char last;
    cin >> last;
    int maxx = 0;
    int part = 1;
    for (int i = 1; i < n; i++) {
        char c; cin >> c;
        if (c != last) {
            maxx = max(maxx, part);
            part = 1;
        } else {
            part++;
        }
        last = c;
    }
    maxx = max(maxx, part);

    cout << (int) log2(maxx);
    cout << "\n";
}
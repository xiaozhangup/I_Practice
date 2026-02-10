// 链接: https://ac.nowcoder.com/acm/contest/120561/K
// 日期: 2026年02月03日

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
    if (n == 1) {
        cout << "YES\n1\n";
        return;
    }
    if (n == 3) {
        cout << "YES\n1 2 3\n";
        return;
    }


    cout << "NO\n";
}
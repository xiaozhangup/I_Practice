// 链接: https://codeforces.com/contest/2202/problem/C1
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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int res = 1;
    int header = v[0];
    int ava = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] <= header || v[i] > ava + 1) {
            res++;
            header = v[i];
        }
        ava = v[i];
    }
    
    cout << res << "\n";

    // 9 8 2
    // 9 8 9 2 3 4 4 5 3
}
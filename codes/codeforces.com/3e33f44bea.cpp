// 链接: https://codeforces.com/contest/2202/problem/C2
// 日期: 2026年02月24日

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

#define int long long

void slove() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<pair<int, int>> bits;

    int sum = 0;
    int total = 0;

    for (int i = 0; i < n; i++) {
        int cur = v[i];
        int count = 0;

        if (i > 0 && cur > v[i - 1] + 1) {
            count = i;
            bits.clear();
            bits.push_back({cur, i + 1});
        } else {
            int conti = 0;
            while (!bits.empty() && bits.back().first >= cur) {
                conti += bits.back().second;
                bits.pop_back();
            }
            
            count = conti;
            bits.push_back({cur, count + 1});
        }

        sum = sum + 1 + count;
        total += sum;
    }
    
    cout << total << "\n";

    // 9 8 2
    // 9 8 9 2 3 4 4 5 3
}
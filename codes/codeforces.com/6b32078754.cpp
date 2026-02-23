// 链接: https://codeforces.com/contest/2202/problem/D
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

#define ll long long

void slove() {
    int n, k; cin >> n >> k;

    if (k < n || k > 2 * n - 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<int> res;

    int n2 = k - n + 1;
    int n1 = n - n2;

    for (int i = 1; i <= n1; i++) {
        res.push_back(i);
        res.push_back(i);
    }

    int offset = n1;

    if (n2 == 1) {
        res.push_back(offset + 1);
        res.push_back(offset + 1);
    } else if (n2 == 2) {
        res.push_back(offset + 1);
        res.push_back(offset + 2);
        res.push_back(offset + 1);
        res.push_back(offset + 2);
    } else if (n2 >= 3) {
        res.push_back(offset + 1);
        res.push_back(offset + 2);

        for (int i = 2; i <= n2 - 1; i++) {
            res.push_back(offset + i - 1);
            res.push_back(offset + i + 1);
        }

        res.push_back(offset + n2 - 1);
        res.push_back(offset + n2);
    }

    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";
}
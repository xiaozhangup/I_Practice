// 链接: https://codeforces.com/contest/2192/problem/B
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

    vector<vector<int>> cot(2);
    int index = 0;
    for (char c : s) {
        index++;
        cot[c - '0'].push_back(index);
    }
    
    if (cot[1].size() == 0) {
        cout << "0\n";
        return;
    }
    
    if (cot[0].size() == 1) {
        cout << "1\n" << cot[0][0] << "\n";
        return;
    }

    if (cot[1].size() & 1 && cot[0].size() & 1) {
        cout << cot[0].size() << "\n";
        for (int b : cot[0]) {
            cout << b << " ";
        }
        return;
    }

    if (cot[1].size() & 1 && cot[0].size() % 2 == 0) {
        cout << "-1\n";
        return;
    }

    cout << cot[1].size() << "\n";
    for (int b : cot[1]) {
        cout << b << " ";
    }

    // cout << "1\n1";
    cout << "\n";
}
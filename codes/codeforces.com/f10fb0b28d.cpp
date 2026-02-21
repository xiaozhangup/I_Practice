// 链接: https://codeforces.com/contest/2192/problem/E
// 日期: 2026年02月22日

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

    unordered_map<int, int> cot;
    vector<int> arra(n);
    for (int i = 0; i < n; i++) {
        cin >> arra[i];
        cot[arra[i]]++;
    }

    vector<int> arrb(n);
    for (int i = 0; i < n; i++) {
        cin >> arrb[i];
        cot[arrb[i]]++;
    }

    for (auto pa : cot) {
        if (pa.second & 1) {
            cout << "-1\n";
            return;
        }
    }

    unordered_map<int, int> need, used;
    for (auto pa : cot) {
        need[pa.first] = pa.second / 2;
    }
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (used[arra[i]] < need[arra[i]]) {
            used[arra[i]]++;
        } else {
            ans.push_back(i + 1);
            used[arrb[i]]++;
        }
    }

    cout << ans.size();
    cout << "\n"; // cot
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n"; // arr
}
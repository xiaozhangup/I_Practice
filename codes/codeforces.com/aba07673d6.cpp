// 链接: https://codeforces.com/contest/2205/problem/C
// 日期: 2026年02月26日

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
#include <numeric>
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
    vector<vector<int>> arri(n);

    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        vector<int> arrl(l);
        for (int j = 0; j < l; j++) {
            cin >> arrl[j];
        }
        reverse(arrl.begin(), arrl.end());
        
        vector<int> uni;
        unordered_set<int> seen;
        for (int x : arrl) {
            if (!seen.count(x)) {
                uni.push_back(x);
                seen.insert(x);
            }
        }

        arri[i] = uni;
    }

    sort(arri.begin(), arri.end());
    vector<int> Q;
    unordered_set<int> used;
    vector<bool> ublong(n, false);

    for (int step = 0; step < n; step++) {
        int bidx = -1;
        vector<int> remb;

        for (int i = 0; i < n; i++) {
            if (ublong[i]) continue;
            
            vector<int> rem;
            for (int x : arri[i]) {
                if (!used.count(x)) {
                    rem.push_back(x);
                }
            }

            if (bidx == -1 || rem < remb) {
                bidx = i;
                remb = rem;
            }
        }

        ublong[bidx] = true;
        for (int x : remb) {
            Q.push_back(x);
            used.insert(x);
        }
    }

    for (int i = 0; i < Q.size(); i++) {
        cout << Q[i] << " ";
    }
    cout << "\n";
}
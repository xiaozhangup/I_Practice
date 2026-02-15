// 链接: https://ac.nowcoder.com/acm/contest/127703/C
// 日期: 2026年02月15日

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
    int n, m; cin >> n >> m;
    vector<int> arra(n);
    for (int i = 0; i < n; i++) {
        cin >> arra[i];
    }

    vector<int> arrb(m);
    for (int i = 0; i < m; i++) {
        cin >> arrb[i];
    }

    int offset = 0;
    for (int i = 0; i < m; i++) {
        int num = arrb[i];
        if (i + offset >= n) {
            cout << "NO\n";
            return;
        }
        if (arra[i + offset] > num) {
            // PASS
        } else if (arra[i + offset] == num) {
            // PASS
        } else if (arra[i + offset] < num) {
            while (true)
            {
                offset++;
                if (i + offset < n) {
                    if (arra[i + offset] > num) break;
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}
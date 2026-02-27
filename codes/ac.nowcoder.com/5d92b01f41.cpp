// 链接: https://ac.nowcoder.com/acm/contest/128675/F
// 日期: 2026年02月27日

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
    // cin >> T;
    while (T--) {
        slove();
    }
}

#define ll long long

void slove() {
    int n, q; cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int b = 0; b < q; b++) {
        int o; cin >> o;
        if (o == 1) {
            int l, r; cin >> l >> r;
            for (int i = l; i <= r; i++) {
                arr[i] /= (i - l + 1);
            }
        } else {
            int x = arr[1];
            for (int i = 2; i <= n; i++) {
                x ^= arr[i];
            }
            cout << x << "\n";
        }
    }
}
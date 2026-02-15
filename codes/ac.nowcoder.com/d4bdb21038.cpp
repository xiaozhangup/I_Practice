// 链接: https://ac.nowcoder.com/acm/contest/127703/E
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

#define int long long

void slove() {
    int n; cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> ji(n + 1, 0), ou(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ji[i] = ji[i - 1];
        ou[i] = ou[i - 1];

        if (i & 1) {
            ji[i] += arr[i];
        } else {
            ou[i] += arr[i];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        int lef = min(ji[i - 1], ou[i - 1]);

        int su = min(ji[n] - ji[i], ou[n] - ou[i]);
        res = max(res, arr[i] + lef + su);
    }
    
    cout << res << "\n";
}
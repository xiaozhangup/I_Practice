// 链接: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P1638
// 日期: 2026年01月30日

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
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        arr[i] = a;
    }

    map<int, int> count;
    int num = 0, len = n + 1;

    int l = 1, r = 1;
    int ans_l = 1, ans_r = n;

    for (r = 1; r <= n; r++) {
        if (count[arr[r]] == 0) {
            num++;
        }
        count[arr[r]]++;

        while (m == num) {
            if (r - l + 1 < len) {
                len = r - l + 1;
                ans_r = r;
                ans_l = l;
            }

            count[arr[l]]--;
            if (count[arr[l]] == 0) {
                num--;
            }
            l++;
        }
        
    }

    cout << ans_l << " " << ans_r;
}
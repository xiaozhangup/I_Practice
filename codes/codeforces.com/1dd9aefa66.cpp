// 链接: https://codeforces.com/contest/2192/problem/C
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

#define int long long

void optimize_prefix(vector<int>& a, int h) {
    int n = a.size();
    if (n == 0) return;

    vector<int> suffix_max(n);
    vector<int> suffix_pos(n);

    suffix_max[n - 1] = a[n - 1];
    suffix_pos[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > suffix_max[i + 1]) {
            suffix_max[i] = a[i];
            suffix_pos[i] = i;
        } else {
            suffix_max[i] = suffix_max[i + 1];
            suffix_pos[i] = suffix_pos[i + 1];
        }
    }

    int prefix = 0;
    int min_in_prefix = a[0];
    int min_pos = 0;

    for (int k = 0; k < n; ++k) {
        prefix += a[k];

        if (prefix >= h) {
            return;
        }

        if (k + 1 < n) {
            int gain = suffix_max[k + 1] - min_in_prefix;

            if (prefix + gain >= h) {
                int j = suffix_pos[k + 1];
                swap(a[min_pos], a[j]);
                return;
            }
        }

        if (k + 1 < n && a[k + 1] < min_in_prefix) {
            min_in_prefix = a[k + 1];
            min_pos = k + 1;
        }
    }

    return;
}

void slove() {
    int n, h, k;
    cin >> n >> h >> k;
    
    vector<int> arra(n + 1);
    int sum = 0;

    int maxx = 0;
    int maxin = 0;
    for (int i = 0; i < n; i++) {
        cin >> arra[i];
        sum += arra[i];

        if (arra[i] > maxx) {
            maxx = arra[i];
            maxin = i;
        }
    }

    int init = h / sum;
    int res = init * n;
    int rem = h - (init * sum);

    if (init > 0) {
        if (rem > 0) res += k * init;
        else res += k * (init - 1);
    }

    if (rem > 0) {
        optimize_prefix(arra, rem);
        int index = 0;
        while (rem > 0) {
            res += 1;
            rem -= arra[index++];
        }
    }

    cout << res << "\n";
}